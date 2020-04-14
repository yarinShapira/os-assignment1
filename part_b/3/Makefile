out:daemon.out

daemon.out: daemon.c
	gcc -Wall -o daemon.out daemon.c

.PHONY: clean out

clean:
	rm -f *.o *.out *.so