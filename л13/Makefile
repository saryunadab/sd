main: bin.o func.o sort.o main.o
	gcc -Wall bin.o func.o sort.o main.o -o main 

main.o:main.c
	gcc -c main.c -o main.o
bin.o: bin.c
	gcc -c bin.c -o bin.o
func.o: func.c
	gcc -c func.c -o func.o
sort.o: sort.c
	gcc -c sort.c -o sort.o

run:
	./main

clean:
	rm -f main main.o bin.o sort.o func.o