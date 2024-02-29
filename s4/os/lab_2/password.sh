#!/bin/bash

read -p "Enter password: " password

len=${#password}

if [[ ($len -lt 8)  || !($password =~ [A-Z]) ||  !($password =~ [a-z])]]; then
	echo "Password is weak"
else
	echo "Password is strong"
fi
