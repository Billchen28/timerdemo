timerdemo: timerdemo.o timer_engine.o jqueue.o
	$(CC) -o timerdemo timerdemo.o timer_engine.o pool.o jqueue.o
timerdemo.o:
	$(CC) -c timerdemo.c
timer_engine.o: jqueue.o
	$(CC) -c timer_engine.c
jqueue.o: pool.o
	$(CC) -c jqueue.c
pool.o:
	$(CC) -c pool.c
clean:
	rm *.o timerdemo
