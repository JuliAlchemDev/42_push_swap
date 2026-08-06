#!/bin/sh

# Benchmark the asymptotic behavior of each strategy.
# The script checks whether average step counts grow roughly as:
#   simple  -> O(n^2)
#   medium  -> O(n * sqrt(n))
#   complex -> O(n * log(n))

runs=${RUNS:-12}
sizes=${SIZES:-"50 100 200"}
strategies=${STRATEGIES:-"--simple --medium --complex"}

if [ ! -x ./push_swap ]; then
    echo "ERROR: ./push_swap not found or not executable" >&2
    exit 1
fi

result_file=$(mktemp)
trap 'rm -f "$result_file"' EXIT HUP INT TERM

printf 'Benchmarking complexity with %s runs and sizes: %s\n' "$runs" "$sizes"

for strategy in $strategies; do
    printf '\nStrategy: %s\n' "$strategy"
    for size in $sizes; do
        printf '  size %s: ' "$size"
        total_steps=0

        i=1
        while [ "$i" -le "$runs" ]; do
            args=$(shuf -i 0-9999 -n "$size" | tr '\n' ' ')
            output=$(./push_swap "$strategy" $args 2>&1)

            if [ "$output" = "Error" ]; then
                echo "ERROR: push_swap returned Error for $strategy size $size run $i" >&2
                exit 1
            fi

            steps=$(printf '%s\n' "$output" | wc -l)
            total_steps=$((total_steps + steps))
            i=$((i + 1))
        done

        avg=$(awk -v total="$total_steps" -v runs="$runs" 'BEGIN { printf "%.2f", total / runs }')
        printf '%s average steps\n' "$avg"
        printf '%s %s %s\n' "$strategy" "$size" "$avg" >> "$result_file"
    done
done

printf '\nValidating asymptotic trend for each strategy...\n'

eval_status=0
awk -v strategies="$strategies" -v sizes="$sizes" -v min_factor="0.55" -v max_factor="2.2" '
    function expected_ratio(prev_n, next_n, alg) {
        if (alg == "--simple") {
            return (next_n * next_n) / (prev_n * prev_n)
        } else if (alg == "--medium") {
            return (next_n * sqrt(next_n)) / (prev_n * sqrt(prev_n))
        } else if (alg == "--complex") {
            return (next_n * log(next_n)) / (prev_n * log(prev_n))
        }
        return 1
    }
    BEGIN {
        split(strategies, algs, " ")
        size_count = split(sizes, size_list, " ")
        err = 0
    }
    {
        avg[$1","$2] = $3
    }
    END {
        for (ai = 1; ai <= length(algs); ai++) {
            alg = algs[ai]
            printf "\nStrategy: %s\n", alg
            for (si = 1; si < size_count; si++) {
                prev = size_list[si] + 0
                next_n = size_list[si+1] + 0
                a = avg[alg "," prev] + 0
                b = avg[alg "," next_n] + 0

                if (a <= 0 || b <= 0) {
                    printf "  FAIL: missing data for %s at size %s or %s\n", alg, prev, next_n
                    err = 1
                    continue
                }

                actual = b / a
                expected = expected_ratio(prev, next_n, alg)
                lower = expected * min_factor
                upper = expected * max_factor

                printf "  sizes %s -> %s: average %.2f -> %.2f, actual ratio %.2f, expected %.2f\n", prev, next_n, a, b, actual, expected

                if (b <= a) {
                    printf "    FAIL: step count did not increase for %s from %s to %s\n", alg, prev, next_n
                    err = 1
                } else if (actual < lower || actual > upper) {
                    printf "    FAIL: ratio %.2f outside expected range [%.2f, %.2f] for %s\n", actual, lower, upper, alg
                    err = 1
                } else {
                    printf "    OK\n"
                }
            }
        }
        exit err
    }
' "$result_file" || eval_status=1

if [ "$eval_status" -ne 0 ]; then
    echo '\nComplexity trend validation FAILED' >&2
    exit 1
fi

echo '\nComplexity trend validation PASSED'
exit 0
