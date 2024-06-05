#!/bin/bash
echo "Enter 1 to print the first pattern or 2 to print the second pattern:"
read case_num

case $case_num in
  1)
    echo "Enter the number of rows for the first pattern:"
    read rows
    for ((i=1; i<=rows; i++))
    do
      for ((j=1; j<=i; j++))
      do
        echo -n "* "
      done
      echo
    done
    ;;
  2)
    echo "Enter the number of rows for the second pattern:"
    read rows
    for ((i=rows; i>=1; i--))
    do
      for ((j=1; j<=i; j++))
      do
        echo -n "* "
      done
      echo
    done
    ;;
  *)
    echo "Invalid option. Please enter 1 or 2."
    ;;
esac
