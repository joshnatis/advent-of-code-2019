#!/bin/bash

main() {
	total=0
	nums=( $(cat "$1") )
	for num in "${nums[@]}"; do
		total=$(calcfuel $num $total)
	done
	echo $total
}

calcfuel() {
	let fuel=$1/3-2
	if [ $fuel -le 0 ]; then
		echo $2
		return
	fi

	let total=$2+$fuel
	echo $(calcfuel $fuel $total)
}

main "input.txt"