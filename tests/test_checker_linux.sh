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
error_count=0
fail_count=0
pass_count=0
good_count=0
excellent_count=0

for i in $(seq "$total_runs")
do
    shuf -i 0-9999 -n "$size" > args.txt
    output=$(./push_swap "$alg" $(cat args.txt) 2>&1)
    lines=$(printf '%s\n' "$output" | wc -l)

    if [ "$lines" -eq 1 ] && [ "$output" = "Error" ]; then
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

rm -f args.txt