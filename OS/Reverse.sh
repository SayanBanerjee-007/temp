echo "Enter a number to find its reverse:"
read num
reverse=0

while [ $num -ne 0 ]; do
  remainder=$(($num % 10))
  reverse=$(($reverse * 10 + $remainder))
  num=$(($num / 10))
done

echo "The reverse of the number is $reverse"
