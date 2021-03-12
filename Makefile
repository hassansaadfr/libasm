NAME		= libasm.a

SRCS 		=	ft_strlen.s	\
				ft_strcpy.s	\
				ft_strcmp.s	\
				ft_strdup.s	\
				ft_write.s	\
				ft_read.s

CC 			=	nasm -fmacho64

OBJS 		=	${SRCS:.s=.o}

${NAME}		:	${OBJS}
				ar rc ${NAME} ${OBJS}

all			:	${NAME}

.s.o		:
				${CC} -o $@ $?

test		:	${NAME}
				@gcc -Wall -Wextra -Werror -I./libasm.h libasm.a main.c -o test
				@printf "\e[32mRun tests with ./test\n\e[39m"

clean		:
				rm -rf ${OBJS}

fclean		:	clean
				rm -rf $(NAME)
				rm -rf test

re			:	fclean all
