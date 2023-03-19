SRCS	=	ft_printf.c ft_printf_utils.c ft_printf_utils1.c ft_pr.c ft_pr1.c

OBJS	= 	${SRCS:%.c=%.o}

NAME	=	libftprintf.a

HEADER	=	ft_printf.h

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror -I$(HEADER)

LIB	= ar rc

.PHONY:		all clean fclean re bonus

%.o :		%.c $(HEADER)
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(HEADER)
			$(LIB) $(NAME) $?

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(OBJSB)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

