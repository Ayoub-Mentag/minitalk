SRC		= server.c client.c
OBJ		= server.o client.o
CC 		= gcc
FLAGS	= -Wall -Werror -Wextra

all : server client

server : server.o
	${CC} ${FLAGS} server.o -o $@

client : client.o
	${CC} ${FLAGS} client.o -o $@

bonus : server_bonus client_bonus 

server_bonus : server_bonus.o
	@${CC} ${FLAGS} server_bonus.o -o $@

client_bonus : client_bonus.o
	@${CC} ${FLAGS} client_bonus.o -o $@

%.o : %.c
	${CC} ${FLAGS} -c $<

fclean : clean
	@rm -f server client server_bonus client_bonus

clean : 
	@rm -f *.o

re : fclean all bonus