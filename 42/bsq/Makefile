NAME = libft_app.a

SRCS = srcs/ft_abs.c srcs/ft_app.c srcs/ft_atoi.c srcs/ft_changemapbin.c srcs/ft_changemaptooriginal.c srcs/ft_countlinesmap.c srcs/ft_getbodymap.c srcs/ft_getheadermap.c srcs/ft_getlen.c srcs/ft_getmapbyline.c srcs/ft_getmap.c srcs/ft_getmatrixmap.c srcs/ft_getwidthsize.c srcs/ft_isnumeric.c srcs/ft_iteratematrixinc.c srcs/ft_itoa.c srcs/ft_parsemaptomatrix.c srcs/ft_processmap.c srcs/ft_readmap.c srcs/ft_setbiggestsquare.c srcs/ft_sizefile.c srcs/ft_solvemap.c srcs/ft_strcpy.c srcs/ft_strlen.c srcs/ft_strlenindex.c srcs/ft_strncpy.c srcs/ft_verifybodymap.c srcs/ft_verifybodymapchar.c srcs/ft_verifybodymaplines.c srcs/ft_verifyheadermap.c srcs/ft_verifymap2.c srcs/ft_verifymap.c srcs/ft_verifywidthmap.c

OBJS = ${SRCS:.c=.o}

CC		= cc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs includes/${NAME} ${OBJS}

compile:
	gcc -o bsq -lft_app -L./includes main.c

all:	${NAME}	compile

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} includes/${NAME}

re:		fclean all