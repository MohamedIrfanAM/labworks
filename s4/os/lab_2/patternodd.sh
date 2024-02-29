#!/bin/bash

read -p "Enter number: " n

for (( i = 1; i <= n; i++ )); do
	for (( j = 0; j < i*2-1 ; j++ )); do
		echo -ne "* "
	done
	echo ""
done
for (( i = n-1; i >= 1; i-- )); do
	for (( j = 0; j < i*2-1 ; j++ )); do
		echo -ne "* "
	done
	echo ""
done