echo "First"
read a
echo "Second"
read b
sum=`echo $a+$b |bc`
echo "sum -> $sum"
