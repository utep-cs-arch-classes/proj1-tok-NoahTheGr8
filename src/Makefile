main: runer.c tokenizer.c
	gcc -o run runner.o tokenizer.o

runner.o: runner.c
	gcc -o runner.c

tokenizer.o: tokenizer.c tokenizer.h
	gcc -o tokenizer.c

clean:
	rm -f *.o *~ *#
	ls
