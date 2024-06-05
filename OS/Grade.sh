echo "Enter marks for five subjects: "
read sub1
read sub2
read sub3
read sub4
read sub5

total=$(($sub1 + $sub2 + $sub3 + $sub4 + $sub5))
average=$(($total / 5))

if [[ $average -ge 90 ]]; then
  grade="Outstanding"
elif [[ $average -ge 80 ]]; then
  grade="Excellent"
elif [[ $average -ge 70 ]]; then
  grade="Very Good"
elif [[ $average -ge 60 ]]; then
  grade="Good"
elif [[ $average -ge 50 ]]; then
  grade="Satisfactory"
else
  grade="Fail"
fi

echo "The student's grade is: $grade"
