NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
SRC = ft_printf.c	\
	ft_putchar_fd.c	\
	ft_puthex_fd.c		\
	ft_putnbr_fd.c	\
	ft_putstr_fd.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all