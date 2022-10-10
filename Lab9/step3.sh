for file in file1.txt file2.txt file3.txt
do
	for bufferr in 100 1000 10000
	do
		echo "Step3 $file $buffer"
		time ./step3 $file $buffer
		echo " "
	done
done
