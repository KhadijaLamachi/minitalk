NAME_1=server

NAME_2=client

CC=cc

CFLAGS=-Wall -Wextra -Werror

SRC_SERVER=server.c utils_server.c

SRC_CLIENT=client.c utils_client.c

OBJ_SERVER=$(SRC_SERVER:.c=.o)

OBJ_CLIENT=$(SRC_CLIENT:.c=.o)

all:$(NAME_1) $(NAME_2)

$(NAME_1):$(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(NAME_1)

$(NAME_2):$(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(NAME_2)

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)

fclean:clean
	rm -f $(NAME_1) $(NAME_2)

re:fclean all

.PHONY:all clean fclean re

.SECONDARY:$(OBJ_CLIENT) $(OBJ_SERVER)