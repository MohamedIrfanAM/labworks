#!/bin/bash

read -p "Enter number: " num

echo "Binary = "
echo "obase=2;$num" | bc
printf 'Hexadecimal = %x\n' $num
printf 'Octal = %o\n' $num