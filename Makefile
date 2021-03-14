NAME		=	libasm.a

CC			=	clang

HEADERS		=	-I includes

CFLAGS		=	-Wall -Wextra -Werror -g

SRCS 		=	ft_strlen.s	\
				ft_strcpy.s	\
				ft_strcmp.s	\
				ft_strdup.s	\
				ft_write.s	\
				ft_read.s

SRCS_BONUS	=	ft_list_size.s

CC 			=	nasm -f elf64

OBJS 		=	${SRCS:.s=.o}

OBJS_BONUS	=	${SRCS_BONUS:.s=.o}

UTILS		=	real_functions/ft_lstsize.c \
				real_functions/ft_lstclear.c \
				real_functions/ft_lstlast.c

${NAME}		:	${OBJS}
				@ar rc ${NAME} ${OBJS}

all			:	${NAME}

bonus		:	${NAME} ${OBJS_BONUS}
				@ar rc ${NAME} ${OBJS} ${OBJS_BONUS} ${UTILS}

.s.o		:
				${CC} -o $@ $?

test		:	${OBJS} ${OBJS_BONUS} ${UTILS}
				@clang -Wall -Wextra -Werror -Iincludes ${OBJS} ${OBJS_BONUS} ${UTILS} main.c -o test
				@printf "\e[32mRun tests with ./test\n\e[39m"

clean		:
				rm -rf ${OBJS} $(OBJS_BONUS)

fclean		:	clean
				rm -rf ${NAME}
				rm -rf test

re			:	fclean all

.phony		:	all clean fclean test
