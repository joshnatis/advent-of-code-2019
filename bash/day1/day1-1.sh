#!/bin/bash

main() {
	total=0
	nums=( $(cat "$1") )
	for num in "${nums[@]}"; do
		let total=$total+$num/3-2
	done
	echo $total
}

main "input.txt"
