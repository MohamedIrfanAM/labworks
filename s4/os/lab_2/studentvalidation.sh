#!/bin/bash

IFS=' '

while read line; do
	read -a student <<< "$line"
	flag=0
	for (( i = 1; i < 4; i++ )); do
		if [[ ${student[$i]} -lt 55 ]]; then
			flag=1
		fi
	done
	if [[ flag -eq 0 ]]; then
		echo "${student[0]} = passed"
	else
		echo "${student[0]} = failed"
	fi
done <students.txt