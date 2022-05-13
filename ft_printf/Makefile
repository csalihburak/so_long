NAME    = libftprintf.a
CC = gcc
INC = ft_printf.h
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = -rcs
RM = rm -rf

SRCS    = ft_printf.c	\
		  srcs/ft_printf_utils.c	\
		  srcs/ft_put_nbr_Xbase.c	\
		  srcs/ft_put_pointr.c	\

OBJS = $(SRCS:.c=.o)

# colors for printing
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

all: $(NAME)

$(NAME): $(OBJS)
	@ar $(ARFLAGS) $(NAME) $(OBJS)
	@echo "and ... Magic :D"

%.o: %.c $(INC)
	@echo $(Y)Complining [$<]
	@$(CC) -c $< -o $@ $(CFLAGS)

clean:
	@$(RM) $(OBJS)
	@echo $(R)Removed [$(OBJS)]

fclean: clean
	@$(RM) $(NAME)
	@echo $(R)Removed [$(NAME)]

re: fclean all

.PHONY: all, clean, fclean, re
