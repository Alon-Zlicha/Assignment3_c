all: StrList

StrList.o: StrList.c StrList.h
	gcc -c -Wall StrList.c

main.o: main.c StrList.h
	gcc -c -Wall main.c

StrList: main.o StrList.o
	gcc -Wall main.o StrList.o -o StrList

clean:
	rm -f main.o StrList.o StrList

.PHONY: clean all