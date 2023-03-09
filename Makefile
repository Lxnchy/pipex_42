# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 14:00:10 by jehubert          #+#    #+#              #
#    Updated: 2023/03/09 17:12:00 by jehubert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT = libft/libft.a

HEAD = includes/

SRCS = srcs/pipex.c \
	srcs/childs.c \
	srcs/cmdlist.c \
	srcs/get.c \
	srcs/utils.c \
	srcs/error.c \
	srcs/heredoc.c \
	srcs/parsing.c

B_SRCS = srcs/pipex_bonus.c \
	srcs/childs.c \
	srcs/cmdlist.c \
	srcs/get.c \
	srcs/utils.c \
	srcs/error.c \
	srcs/heredoc.c \
	srcs/parsing.c

OBJS = $(patsubst %,objs/%,$(notdir ${SRCS:.c=.o}))

B_OBJS = $(patsubst %,objs/%,$(notdir ${B_SRCS:.c=.o}))

CFLAGS = -Wall -Wextra -Werror

objs/%.o : srcs/%.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: $(OBJS)
	make --no-print-directory -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(B_OBJS)
	make --no-print-directory -C ./libft
	$(CC) $(CFLAGS) $(B_OBJS) $(LIBFT) -o $(NAME)

all: $(NAME)

clean:
	make --no-print-directory -C ./libft clean
	rm -f $(OBJS) $(B_OBJS)

fclean:	clean
	make --no-print-directory -C ./libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
.SILENT: all clean fclean re ${NAME} $(OBJS) bonus