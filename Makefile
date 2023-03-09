CLIENT = client

SERVER = server

SRCS_C = client.c \
	   	 utilslibft.c

PRINTF = ft_printf/libftprintf.a

CC = gcc

#CFLAGS = -Wall -Werror -Wextra

SRCS_S = server.c \

OBJS_C = ${SRCS_C:.c=.o}

OBJS_S = ${SRCS_S:.c=.o}

all : $(CLIENT) $(SERVER)

$(CLIENT) : $(PRINTF) $(OBJS_C)
		$(CC) $^ -o $(CLIENT)

$(SERVER) : $(PRINTF) $(OBJS_S)
		$(CC) $^ -o $(SERVER)
$(PRINTF) :
	make -C ft_printf

clean :
	@rm -rf $(OBJS_C) $(OBJS_S)
	make clean -C ft_printf
fclean : clean
	@rm -rf $(CLIENT) $(SERVER)
	make fclean -C ft_printf

re : fclean all