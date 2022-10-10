for file in file1.txt file2.txt file3.txt
do
	for buffer in 100 1000 10000
	do
		echo "Step4 $file $buffer"
		time ./step4 $file $buffer
		echo " "
	done
done
