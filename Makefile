objects =   arvore.o main.o

all :   $(objects)
	gcc -o  alg $(objects)

run :   alg
	./alg

arvore.o :   arvore.h
main.o  :   arvore.h

clean   :
	rm *.o alg
