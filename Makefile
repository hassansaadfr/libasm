NAME		=	libasm.a

SRCS 		=	ft_strlen.s	\
				ft_strcpy.s	\
				ft_strcmp.s	\
				ft_strdup.s	\
				ft_write.s	\
				ft_read.s	\
				ft_list_size.s

CC 			=	nasm -f elf64

OBJS 		=	${SRCS:.s=.o}


UTILS		=	real_functions/ft_lstsize.c \
				real_functions/ft_lstclear.c \
				real_functions/ft_lstlast.c

OBJS_UTILS	=	${UTILS:.s=.o}

${NAME}		:	${OBJS}
				@ar rc ${NAME} ${OBJS}

all			:	${NAME}

.s.o		:
				${CC} -o $@ $?

test		:	re ${OBJS} ${OBJS_UTILS}
				@clang -Wall -Wextra -Werror -g -I includes ${OBJS} ${OBJS_UTILS} main.c -o test
				@printf "\e[32mRun tests with ./test\n\e[39m"

clean		:
				rm -rf ${OBJS}

fclean		:	clean
				rm -rf $(NAME)
				rm -rf test

re			:	fclean all

.phony		:	all clean fclean test
