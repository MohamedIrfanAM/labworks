
read -p "Enter the number: " num
# echo $num | rev

while [[ num -gt 0 ]]; do
    echo -n $((num%10))
    num=$((num/10))
done