echo "Enter number"
read num
dig=0
sum=0
while [ $num -gt 1 ]
do
 dig=$(($num%10))
 num=$(($num/10))
 sum=$(($sum+$dig))
done
echo "The sum of digit is $sum"
