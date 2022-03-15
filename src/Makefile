CC = cc
TDEPS = tokenizer.h history.h dimitri_lib.h
TLIBS = find_spaces.o wordenizer.o dimitri_lib.o history.o


all:tokenizer

#simple_console.c has a main method.  I use it to test and to various code
tokenizer: $(TLIBS) simple_console.o
	$(CC) -o simple_console.o simple_console.c -c
	$(CC) -o tokenizer $(TLIBS) simple_console.o

$(TLIBS): $(TDEPS)



clean:
	-rm -f *.o tokenizer 
