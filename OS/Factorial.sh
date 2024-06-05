echo "Enter a number to find its factorial:"
read num
i=1
factorial=1
while [[ $i -le $num ]]; do
factorial=$(($factorial*$i))
i=$(($i+1))
done
echo "The factorial of $num is $factorial"
