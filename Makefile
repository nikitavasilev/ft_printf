NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
RM = rm -f

SRCS =		./srcs/ft_putchar.c \
			./srcs/ft_putstr.c \
			./srcs/ft_strlen.c \
			./srcs/putaddr.c \
			./srcs/putnbr_base.c \
			./srcs/format_specifier.c \
			./srcs/ft_printf.c \
			./srcs/check_null.c \
			./srcs/ft_isdigit.c \
			./srcs/ft_atoi.c \
			./srcs/count_chars.c \
			./srcs/dot_check.c \
			./srcs/minus_padding.c \
			./srcs/sharp_check.c \
			./srcs/space_and_sign.c \
			./srcs/utilities_zero_check.c \
			./srcs/zero_check.c \
			./srcs/ft_strcmp.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o: $(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	ranlib $(NAME)

so:
	$(CC) -c -fPIC $(CFLAGS) $(SRCS)
	gcc -shared -o libftprintf.so $(OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

bonus: all

.PHONY: bonus so all clean fclean re
