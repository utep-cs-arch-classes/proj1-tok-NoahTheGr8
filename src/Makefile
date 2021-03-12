main: runner.o
	cc runner.o -o runner 

runner.o: runner.c
	gcc -c runner.c

tokenizer.o: tokenizer.c tokenizer.h
	gcc -c tokenizer.c

history.o: history.c history.h
	gcc -c history.c

clean:
	rm -f *.o *~ *#
	ls
