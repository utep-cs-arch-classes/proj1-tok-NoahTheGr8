main: runner.o tokenizer.o history.o
	gcc -o output runner.o tokenizer.o history.o 

runner.o: runner.c
	gcc -c runner.c

tokenizer.o: tokenizer.c tokenizer.h
	gcc -c tokenizer.c

history.o: history.c history.h
	gcc -c history.c

clean:
	rm -f *.o *~ *#
	ls
