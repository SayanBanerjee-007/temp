echo "Enter a number to find the sum of its digits:"
read num
sum=0

while [ $num -ne 0 ]; do
  digit=$(($num % 10))
  sum=$(($sum + $digit))
  num=$(($num / 10))
done

echo "The sum of the digits is $sum"
