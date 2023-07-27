CC=gcc

DEPS= 
OBJ= client.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< 
client:	$(OBJ)
	gcc -o $@ $^ 
.PHONY:	clean
clean:
	rm *.o client
