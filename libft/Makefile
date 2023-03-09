# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 16:07:29 by jehubert          #+#    #+#              #
#    Updated: 2023/03/09 17:03:40 by jehubert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c \
ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c  \
ft_lstadd_back.c get_next_line.c get_next_line_utils.c ft_printf.c ft_printf_utils.c \
ft_realloc.c ft_join.c

SRCS = srcs/$(SRC)

OBJS = objs

CFLAGS	= -Wall -Wextra -Werror

OBJECT = $(patsubst %,$(OBJS)/%,$(notdir ${SRCS:.c=.o}))

$(OBJS)/%.o : srcs/%.c
		${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJECT)
	ar rc $(NAME) $(OBJECT)
	ranlib $(NAME)

all : $(NAME)

bonus : all

clean :
	rm -f $(OBJECT) $(BOBJECT)

fclean : clean
	rm -f libft.a

re : fclean all

.PHONY: all clean fclean re
.SILENT: all clean fclean re $(NAME) $(OBJECT)
