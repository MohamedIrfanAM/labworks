echo "Enter a Number"
read basicSalary
echo $basicSalary

if [ $basicSalary -lt 1500 ]; then
	HRA=$(echo "scale=2; 0.1*$basicSalary" | bc) 
 	DA=$(echo "scale=2; 0.9*$basicSalary" | bc) 
 else
 	HRA="500"
 	DA=$(echo "scale=2; 0.98*$basicSalary" | bc)
 fi

echo "HRA = $HRA"
echo "DA = $DA"
grossSalary=$(echo "scale=2; $basicSalary+$HRA+$DA"  | bc) 
echo "grossSalary = $grossSalary"
