FLAGS := -c -g

../final/jecc: grammer_analysis.c GT.o word_analysis.a datastruct.a seman.a ../auto/final/states_table.o
	gcc -o ../final/jecc  -g grammer_analysis.c  GT.o ../auto/final/states_table.o  word_analysis.a datastruct.a seman.a \
	-I ../datastruct -I ../auto/final -I ../word_analysis/ -I ../seman/ -I ./

ga.a:grammer_analysis.o GT.o
	ar -rcs ga.a grammer_analysis.o GT.o

grammer_analysis.o:grammer_analysis.c
	gcc -o grammer_analysis.o $(FLAGS) grammer_analysis.c \
	-I ../datastruct -I ../auto/final -I ../word_analysis/

GT.o:GT.c
	gcc -o GT.o $(FLAGS) GT.c \
	-I ../datastruct -I ../auto/final -I ../word_analysis/

word_analysis.a:../word_analysis/token.o ../word_analysis/hash.o ../word_analysis/mm.o ../word_analysis/word_analysis.o
	ar rcs word_analysis.a ../word_analysis/token.o ../word_analysis/hash.o ../word_analysis/mm.o ../word_analysis/word_analysis.o

../word_analysis/token.o:../word_analysis/token.c
	gcc -o ../word_analysis/token.o $(FLAGS) ../word_analysis/token.c

../word_analysis/hash.o:
	gcc -o ../word_analysis/hash.o $(FLAGS) ../word_analysis/hash.c

../word_analysis/mm.o: 
	gcc -o ../word_analysis/mm.o $(FLAGS) ../word_analysis/mm.c

../word_analysis/word_analysis.o:
	gcc -o ../word_analysis/word_analysis.o $(FLAGS) ../word_analysis/word_analysis.c

datastruct.a:../datastruct/linear.o ../datastruct/stack.o
	ar rcs datastruct.a ../datastruct/linear.o ../datastruct/stack.o

../datastruct/linear.o:../datastruct/linear.c
	gcc -o ../datastruct/linear.o $(FLAGS) ../datastruct/linear.c -I ../word_analysis/

../datastruct/stack.o: ../datastruct/stack.c
	gcc -o ../datastruct/stack.o $(FLAGS) ../datastruct/stack.c -I ../word_analysis/

../auto/final/states_table.o: ../auto/final/states_table.c
	gcc -o ../auto/final/states_table.o $(FLAGS) ../auto/final/states_table.c

seman.a: ../seman/block.o ../seman/function.o ../seman/seman.o
	ar rcs seman.a ../seman/block.o ../seman/function.o ../seman/seman.o

../seman/block.o: ../seman/block.c 
	gcc -o ../seman/block.o $(FLAGS) ../seman/block.c -I ../grammer/ -I ../word_analysis/

../seman/function.o: ../seman/function.c
	gcc -o ../seman/function.o $(FLAGS) ../seman/function.c -I ../grammer/ -I ../word_analysis/ -I ../datastruct/

../seman/seman.o: ../seman/seman.c
	gcc -o ../seman/seman.o $(FLAGS) ../seman/seman.c -I ../grammer/ -I ../word_analysis/ -I ../datastruct/

clean:
	rm -f *.a *.o
	rm -f ../word_analysis/*.o
	rm -f ../datastruct/*.o
	rm -f ../auto/final/*.o
	rm -f ../seman/*.o 
	rm -f 




