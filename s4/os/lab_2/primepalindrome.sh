#!/bin/bash

read -p "Enter number: " n

while [[ true  ]]; do
	flag=0
	# echo $n
	for (( i = 2; i < n; i++ )); do
		if [[ $n%$i -eq 0 ]]; then
			flag=1
			break
		fi
	done
	num=$n
	reverse=0
	while [ $num -gt 0 ]
	do
	    remainder=$(( $num % 10 )) 
	    reverse=$(( $reverse * 10 + $remainder )) 
	    num=$(( $num / 10 )) 
	done
	if [[ reverse -ne n ]]; then
		flag=1
	fi
	if [[ flag -eq 0 ]]; then
		echo "$n"
		break
	fi
	n=$((n+1))
done