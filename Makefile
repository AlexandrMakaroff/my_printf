.PHONY = all clean fclean re
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror -c
CC = gcc
SRCS =  sources/ft_printf.c \
	sources/ft_init_flags.c \
	sources/ft_parse.c \
	sources/ft_print_c.c \
	sources/ft_print_d.c \
	sources/ft_print_p.c \
	sources/ft_print_s.c \
	sources/ft_print_u.c \
	sources/ft_print_x.c \
	sources/ft_put_integer.c \
	sources/ft_put_string.c \
	sources/ft_put_type.c \
	sources/ft_put_unsigned.c \
	sources/ft_putchar.c \
	sources/ft_set_flags.c \
	sources/ft_star_arg.c \
	sources/ft_strcpy.c \
	sources/ft_to_hex.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c sources/ft_printf.h
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJS)


clean:
	@$(MAKE) clean -C ./libft
	@rm -rf $(OBJS)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -rf $(NAME)

re: fclean all