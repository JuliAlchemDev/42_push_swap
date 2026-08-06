#!/bin/sh

total_runs=100
size=500
alg="--adaptive"

pass_threshold=12000
good_threshold=8000
excellent_threshold=5500

if [ -t 1 ]; then
    RED=$(printf '\033[31m')
    WHITE=$(printf '\033[37m')
    ORANGE=$(printf '\033[38;5;208m')
    YELLOW=$(printf '\033[33m')
    GREEN=$(printf '\033[32m')
    RESET=$(printf '\033[0m')
else
    RED=''
    WHITE=''
    ORANGE=''
    YELLOW=''
    GREEN=''
    RESET=''
fi

echo "Algorithm: $alg"
echo " - total runs: $total_runs"
echo " - size stack: $size"
echo " - thresholds: <${pass_threshold} pass, <${good_threshold} good, <${excellent_threshold} excellent."

steps_file=$(mktemp)
trap 'rm -f "$steps_file"' EXIT HUP INT TERM

error_count=0
fail_count=0
pass_count=0
good_count=0
excellent_count=0

for i in $(seq "$total_runs")
do
    args=$(shuf -i 0-9999 -n "$size" | tr '\n' ' ')

    output=$(./push_swap "$alg" $args 2>&1)
    lines=$(printf '%s\n' "$output" | wc -l)

    if [ "$lines" -eq 1 ] && [ "$output" = "Error" ]; then
        error_count=$((error_count + 1))
        printf '%b' "${RED}!${RESET}"
        continue
    fi

    printf '%s\n' "$lines" >> "$steps_file"

    checker=$(printf '%s\n' "$output" | ./checker_linux $args)

    if [ "$checker" != "OK" ]; then
        error_count=$((error_count + 1))
        printf '%b' "${RED}!${RESET}"
    elif [ "$lines" -ge "$pass_threshold" ]; then
        fail_count=$((fail_count + 1))
        printf '%b' "${WHITE}F${RESET}"
    elif [ "$lines" -ge "$good_threshold" ]; then
        pass_count=$((pass_count + 1))
        printf '%b' "${ORANGE}.${RESET}"
    elif [ "$lines" -ge "$excellent_threshold" ]; then
        good_count=$((good_count + 1))
        printf '%b' "${YELLOW}.${RESET}"
    else
        excellent_count=$((excellent_count + 1))
        printf '%b' "${GREEN}.${RESET}"
    fi
done

echo ""
echo "--- Results ---"
printf '%b\n' "${RED}ERROR:${RESET} $error_count"
printf '%b\n' "${WHITE}FAIL:${RESET} $fail_count"
printf '%b\n' "${ORANGE}PASS:${RESET} $pass_count"
printf '%b\n' "${YELLOW}GOOD:${RESET} $good_count"
printf '%b\n' "${GREEN}EXCELLENT:${RESET} $excellent_count"

echo ""
echo "--- Step statistics ---"
if [ -s "$steps_file" ]; then
    avg_steps=$(awk '{ sum += $1; count++ } END { if (count > 0) printf "%.2f", sum / count }' "$steps_file")
    median_steps=$(sort -n "$steps_file" | awk '
        {
            values[NR] = $1
        }
        END {
            if (NR == 0) {
                print "N/A"
                exit
            }
            mid = int(NR / 2)
            if (NR % 2 == 1) {
                print values[mid + 1]
            } else {
                printf "%.2f", (values[mid] + values[mid + 1]) / 2
            }
        }
    ')

    echo "Average steps: $avg_steps"
    echo "Median steps: $median_steps"
    echo "Distribution:"
    awk -v bins=10 -v width=40 '
        {
            values[NR] = $1
            if (NR == 1) {
                min = $1
                max = $1
            }
            if ($1 < min) min = $1
            if ($1 > max) max = $1
        }
        END {
            if (NR == 0) {
                print "(no data)"
                exit
            }
            if (max == min) {
                printf "all values |"
                for (i = 0; i < width; i++) printf "#"
                print ""
                exit
            }
            bin_width = (max - min) / bins
            if (bin_width < 1) bin_width = 1
            for (i = 0; i < bins; i++) counts[i] = 0
            for (i = 1; i <= NR; i++) {
                idx = int((values[i] - min) / bin_width)
                if (idx >= bins) idx = bins - 1
                counts[idx]++
            }
            max_count = 0
            for (i = 0; i < bins; i++) {
                if (counts[i] > max_count) max_count = counts[i]
            }
            for (i = 0; i < bins; i++) {
                start = int(min + i * bin_width)
                end = int(min + (i + 1) * bin_width - 1)
                if (i == bins - 1) end = max
                bar_len = 0
                if (max_count > 0) {
                    bar_len = int((counts[i] * width) / max_count)
                    if (bar_len == 0 && counts[i] > 0) bar_len = 1
                }
                printf "%d-%d |", start, end
                for (j = 0; j < bar_len; j++) printf "#"
                printf " (%d)\n", counts[i]
            }
        }
    ' "$steps_file"
else
    echo "Average steps: N/A"
    echo "Median steps: N/A"
    echo "Distribution: (no data)"
fi