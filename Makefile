CC=cc

CFLAGS=-Wall -Wextra -Werror

all:client server

server:server.o
	$(CC) $(CFLAGS) server.o -o server

client:client.o
	$(CC) $(CFLAGS) client.o -o client

clean:
	rm -f client.o server.o

fclean:clean
	rm -f client server

re:fclean all

.PHONY:all clean fclean re
