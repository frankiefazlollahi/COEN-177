for file in file1.txt file2.txt file3.txt
do
	for buffer in 100 1000 10000
	do
		for thread in 2 8 32 64
		do
			echo "Step5 $file $buffer $thread"
			time ./step5 $file $buffer $thread
			echo " "
		done
	done
done
