main: runner.o tokenizer.o
	gcc -o run runner.o tokenizer.o

runner.o: runner.c
	gcc -c runner.c

tokenizer.o: tokenizer.c tokenizer.h
	gcc -c tokenizer.c

clean:
	rm -f *.o *~ *#
	ls
