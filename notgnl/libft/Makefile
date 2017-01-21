# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smifsud <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/21 09:27:22 by smifsud           #+#    #+#              #
#    Updated: 2016/09/26 22:36:59 by smifsud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILENAMES = ft_atoi.c ft_bzero.c ft_free_everything.c ft_isalnum.c ft_isalpha.c ft_isascii.c
FILENAMES += ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c
FILENAMES += ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c
FILENAMES += ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c
FILENAMES += ft_realloc.c ft_realloc_nptr.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c
FILENAMES += ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c
FILENAMES += ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c
FILENAMES += ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c
FILENAMES += ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_reversestr.c
FILENAMES += ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c

OBJS = $(addprefix build/, $(FILENAMES:.c=.o))

CFLAGS = -Wall -Wextra -Werror

.PHONY: all index clean fclean re comp

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

index:
	ranlib $(NAME)

build/%.o: %.c | build
	gcc -c $^ -o $@ $(CFLAGS)

build:
	mkdir build

clean:
	rm -rf build

fclean: clean
	rm -f $(NAME)

comp: $(OBJS)
	rm -f $(NAME)
	ar rc $(NAME) $(OBJS)

re: fclean all
