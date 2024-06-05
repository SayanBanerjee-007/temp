echo "Enter two numbers to compare."
read num1
read num2

if [[ $num1 -eq $num2 ]]; then
  echo "The numbers are equal."
else
  if [[ $num1 -gt $num2 ]]; then
    echo "$num1 is larger than $num2."
  else
    echo "$num2 is larger than $num1."
  fi
fi
