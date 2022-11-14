NAME	= philo

HEADER	=	include/philosopher.h

INCLUDES= ${addprefix -I, ${sort ${dir ${HEADER}}}}

SRCS	=	src/main.c		\
			src/philo.c		\
			src/routine.c	\
			src/init.c		\
			src/utils.c		\

OBJS	= ${SRCS:.c=.o}

CC		= gcc

CFLAGS    = -Wall -Wextra -Werror

%o : %c ${HEADER} Makefile
		${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:    ${NAME}

clean:
		rm -f ${OBJS}

fclean:    clean
		rm -f ${NAME}

re:        fclean all

.PHONY:    all clean fclean re