echo "Enter the number"
read num
i=1
while [ $num -gt 1 ]
do
  i=$(($i*$num))
  num=$(($num-1))
done
echo "The factorial is $i"

