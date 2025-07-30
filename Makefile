NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
SRC = ft_printf.c	\
	ft_putchar.c	\
	ft_putstr.c		\
	ft_putnbr.c	  	\
	ft_putul.c		\
	ft_putptr.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all