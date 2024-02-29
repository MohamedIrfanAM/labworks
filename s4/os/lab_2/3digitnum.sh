#!/bin/bash

for (( i = 100; i <= 333; i++ )); do
	d=$i
	flag=0
	while [[ $d -gt 0 ]]; do
		if [[ d%10 -gt 3 ]]; then
			flag=1;
			break
		fi
		d=($d/10)
	done
	if [[ flag -eq 0 ]]; then
		echo $i
	fi
done