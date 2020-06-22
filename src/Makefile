CFLAGS =-g -O3

tokenizer: main.o
	cc -o $@ $^ $(CFLAGS)

main.o: main.c  tokenizer.c tokenizer.h

clean:
	rm -f *.o sortargs

remove:
	rm -f *~
