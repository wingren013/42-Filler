# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smifsud <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/21 09:27:22 by smifsud           #+#    #+#              #
#    Updated: 2017/02/03 10:46:49 by smifsud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
PRINTF = libftprintf.a
P1 = resources/players/filler

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
FILENAMES += ft_realc.c ft_modstr.c ft_realloc_str.c ft_rightjustify.c ft_realc_str.c
FILENAMES += ft_tohex.c ft_hexchar.c charfillfromleft.c charfillfromright.c ft_char_to_str.c debug_printevery.c
FILENAMES += ft_wchardup.c ft_wcharlen.c ft_itoa_base.c ft_itoa_base_u.c ft_itoa_base_up.c ft_itoa_base_up_u.c ft_wcstombs.c
FILENAMES += ft_memcat.c ft_utf8.c

DIR2 = src2
FILENAMES2 = c_flag.c clearholder.c d_flag.c flags_modstr.c jd_flag.c jo_flag.c ju_flag.c
FILENAMES2 += ft_asprintf.c ft_printf.c functions.c lc_flag.c ld_flag.c lo_flag.c jupperhex_flag.c
FILENAMES2 += ls_flag.c lu_flag.c lx_flag.c o_flag.c p_flag.c percentpercent.c jx_flag.c
FILENAMES2 += s_flag.c setup.c u_flag.c x_flag.c poundmod.c plusmod.c spacemod.c
FILENAMES2 += upperhex_flag.c lupperhex_flag.c ft_vasprintf.c p_ls.c ft_dprintf.c
FILENAMES2 += hd_flag.c hu_flag.c ho_flag.c hx_flag.c hupperhex_flag.c hhd_flag.c hhu_flag.c hho_flag.c hhx_flag.c hhupperhex_flag.c
FILENAMES2 += zd_flag.c zu_flag.c zo_flag.c zx_flag.c zupperhex_flag.c modstr_continue.c length_modifiers.c widthmod.c
DIR2INC = -I src1

DIR3 = bot
FILENAMES3 = globals.c mapreader.c phil.c pieceplacer.c player3.c
INCLUDE = includes/

OBJS = $(addprefix build/, $(FILENAMES:.c=.o))
OBJS2 = $(addprefix build/, $(FILENAMES2:.c=.o))
OBJS3 = $(addprefix build/, $(FILENAMES3:.c=.o))
FILES = $(addprefix src1/, $(FILENAMES))
FILES2 = $(addprefix $(DIR2)/, $(FILENAMES2))
FILES3 = $(addprefix $(DIR3)/, $(FILENAMES3))
GNL = notgnl/get_next_line.c
CFLAGS = -Wall -Wextra -Werror -fsanitize=address

.PHONY: all index clean fclean re comp

all: $(NAME) $(P1)

lib: $(NAME)

$(NAME): $(OBJS) $(OBJS2)
	ar rc $(NAME) $(OBJS) $(OBJS2)

index:
	ranlib $(NAME)

build/%.o: src1/%.c | build
	gcc -c $^ -o $@ $(CFLAGS)

build/%.o: $(DIR2)/%.c | build
	gcc -c $^ -o $@ $(CFLAGS) $(DIR2INC)

$(P1): $(OBJS3) $(NAME) | $(PLAYER1)
	gcc $(OBJS3) $(NAME) $(GNL) -o $@ $(CFLAGS) -I $(INCLUDE)

p1: $(P1)

build/%.o: $(DIR3)/%.c | build
	gcc -c $^ -o $@ $(CFLAGS) -I $(INCLUDE)

build:
	mkdir build

clean:
	rm -rf build

fclean: clean
	rm -f $(NAME)
	rm -rf $(P1)

comp: $(OBJS)
	rm -f $(NAME)
	ar rc $(NAME) $(OBJS)

re: fclean all
