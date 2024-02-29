echo "Enter three numbers"
read -r a b c

if [ $a -lt $b ]; then
    if [[ $a -lt $c ]]; then
        echo "a -$a is the smallest"
    else
        echo "c -$c is the smallest"
    fi
else
    echo "b -c $b is the smallest"
fi
