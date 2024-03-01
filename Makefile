all: program

StrList.o: StrList.c StrList.h
	gcc -c -Wall StrList.c

main.o: main.c StrList.h
	gcc -c -Wall main.c

program: main.o StrList.o
	gcc -Wall main.o StrList.o -o program

clean:
	rm -f main.o StrList.o program

.PHONY: clean all