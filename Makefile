timerdemo: timerdemo.o timer_engine.o jqueue.o timer_obj.o
	$(CC) -g -o timerdemo timerdemo.o timer_engine.o pool.o jqueue.o timer_obj.o
timerdemo.o:
	$(CC) -g -c timerdemo.c
timer_engine.o: jqueue.o timer_obj.o
	$(CC) -g -c timer_engine.c
timer_obj.o:
	$(CC) -g -c timer_obj.c
jqueue.o: pool.o
	$(CC) -g -c jqueue.c
pool.o:
	$(CC) -g -c pool.c
clean:
	rm *.o timerdemo
