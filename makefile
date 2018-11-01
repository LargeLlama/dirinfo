all: main.o
	@gcc -o dirinfo.out main.o

main.o: main.c
	@gcc -c main.c

clean:
	@rm *.o*

run:
	@./dirinfo.out
