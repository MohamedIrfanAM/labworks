for filename in "$@"
do
	echo $filename
	sed -i -e 's/\(.*\)/\U\1/' $filename
done