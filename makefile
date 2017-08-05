 pool:pthread_pool.h main.c
	gcc  -Wall -g main.c -o  pool -lpthread
	./pool
clean:
	rm *.o 
