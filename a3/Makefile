FLAGS = -Wall -g
DEPENDENCIES = parentWorker.h

all: a3

a3: test.o implementation.o filesort.o
	gcc ${FLAGS} -o $@ $^

test.o: test.c parentWorker.h
	gcc ${FLAGS} -c $^

implementation.o: implementation.c parentWorker.h
	gcc ${FLAGS} -c $^

filesort.o: filesort.c parentWorker.h
	gcc ${FLAGS} -c $^

clean:
	rm -f *.o a3 *.gch