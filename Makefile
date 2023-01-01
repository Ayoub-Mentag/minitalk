SRC		= server.c client.c
OBJ		= server.o client.o
CC 		= gcc
FLAGS	= -Wall -Werror -Wextra

all : server client

server : server.o
	${CC} ${FLAGS} server.o -o $@

client : client.o
	${CC} ${FLAGS} client.o -o $@

%.o : %.c
	${CC} ${FLAGS} -c $<

fclean : clean
	@rm -f server client

clean : 
	@rm -f ${OBJ}

re : fclean all