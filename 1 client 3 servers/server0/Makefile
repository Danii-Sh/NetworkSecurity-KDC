CC=gcc
LIBS=-lpthread



DEPS= 
OBJ= server0.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< 
server0:	$(OBJ)
	gcc -o $@ $^ $(LIBS)
.PHONY:	clean
clean:
	rm *.o server0
