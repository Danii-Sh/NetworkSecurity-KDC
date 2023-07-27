CC=gcc
LIBS=-lpthread



DEPS= 
OBJ= readfile.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< 
readfile:	$(OBJ)
	gcc -o $@ $^ $(LIBS)
.PHONY:	clean
clean:
	rm *.o readfile
