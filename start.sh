for i in 1 
do
	./fillit correct_file/valid_$i >> rez/rez$i
	diff -q rez/rez$i correct_compare/output_valid_$i
done