# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knaumov <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 09:50:35 by knaumov           #+#    #+#              #
#    Updated: 2019/05/06 12:32:42 by knaumov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILES = ./ft_atoi.c \
		./ft_abs.c \
		./ft_bzero.c \
		./ft_memdel_arlen.c \
		./ft_isspace.c \
		./ft_isalnum.c \
		./ft_isalpha.c \
		./ft_isascii.c \
		./ft_isdigit.c \
		./ft_isprint.c \
		./ft_itoa.c \
		./ft_memalloc.c \
		./ft_memccpy.c \
		./ft_memchr.c \
		./ft_memcmp.c \
		./ft_memcpy.c \
		./ft_memdel.c \
		./ft_memmove.c \
		./ft_memset.c \
		./ft_putchar.c \
		./ft_putchar_fd.c \
		./ft_putendl.c \
		./ft_putendl_fd.c \
		./ft_putnbr.c \
		./ft_putnbr_fd.c \
		./ft_putstr.c \
		./ft_putstr_fd.c \
		./ft_strcat.c \
		./ft_strsch.c \
		./ft_strchr.c \
		./ft_strclr.c \
		./ft_strcmp.c \
		./ft_strcpy.c \
		./ft_strdel.c \
		./ft_strdup.c \
		./ft_strequ.c \
		./ft_striter.c \
		./ft_striteri.c \
		./ft_strjoin.c \
		./ft_strlcat.c \
		./ft_strlen.c \
		./ft_strmap.c \
		./ft_strmapi.c \
		./ft_strncat.c \
		./ft_strncmp.c \
		./ft_strncpy.c \
		./ft_strnequ.c \
		./ft_strnew.c \
		./ft_strnstr.c \
		./ft_strrchr.c \
		./ft_strsplit.c \
		./ft_strstr.c \
		./ft_strsub.c \
		./ft_strtrim.c \
		./ft_tolower.c \
		./ft_toupper.c \
		./ft_itoa_base.c \
		./get_next_line.c \
		./ft_putunsignedint.c \
		./ft_strccrt.c \
		./ft_bchar.c \
		./ft_update.c \
		./ft_strtoupper.c \
		./ft_strtolower.c \
		./ft_putwchar.c \
		./ft_putwchar_fd.c \
		./ft_putwstr.c \
		./ft_putwstr_fd.c \
		./ft_wstrlen.c \
		./ft_wstrdup.c \
		./ft_wchrlen.c \
		./ft_strcon.c \
		./ft_clean_arr.c \
		./ft_create_arr.c \
		./ft_clean_int_arr.c \
		./error.c \
		./adding_minus.c \
		./adding_plus.c \
		./adding_precision_number.c \
		./adding_precision_string.c \
		./adding_space.c \
		./adding_width.c \
		./adding_width_null_char.c \
		./conversion_b.c \
		./conversion_c.c \
		./conversion_d_i.c \
		./conversion_o_cap_o.c \
		./conversion_p.c \
		./conversion_s.c \
		./conversion_u_cap_d_cap_u.c \
		./conversion_wide_c.c \
		./conversion_wide_s.c \
		./conversion_x_cap_x.c \
		./conversions.c \
		./ft_itoa_base_unsigned.c \
		./ft_itoa_intmax.c \
		./ft_itoa_unsigned.c \
		./ft_printf.c \
		./handle_flags.c \
		./handle_format.c \
		./handle_precision.c \
		./handle_width.c \
		./parse_flags.c \
		./printing_wide_string.c

OBJ =   $(FILES:.c=.o)

RESET = \033[0m
RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;36m
RED_EXTRA = \033[1;31m
GREEN_EXTRA = \033[1;32m
BLUE_EXTRA = \033[1;36m

%.o : %.c
	@echo "$(GREEN) 	- Creating $(GREEN_EXTRA)$< $(GREEN)for $(GREEN_EXTRA)Libft..."
	@gcc -g -Wall -Werror -Wextra -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN_EXTRA)   Libft: $(GREEN)Compiling $(GREEN_EXTRA)libft.a$(RESET)"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(BLUE_EXTRA)   Libft: $(NAME)$(BLUE): Complete$(RESET)"

clean:
	@if [ -a "./ft_atoi.o" ]; then echo "$(RED_EXTRA)   Libft: $(RED)Deleting objects for $(RED_EXTRA)libft.a$(RESET)"; fi
	@if [ -a "./ft_atoi.o" ]; then /bin/rm -f $(OBJ); fi
	@echo "$(BLUE_EXTRA)   Libft: clean$(BLUE): Complete$(RESET)"

fclean: clean
	@if [ -a "$(NAME)" ]; then echo "$(RED_EXTRA)   Libft: $(RED)Deleting $(RED_EXTRA)libft.a$(RESET)"; fi
	@if [ -a "$(NAME)" ]; then /bin/rm -f $(NAME); fi
	@echo "$(BLUE_EXTRA)   Libft: fclean$(BLUE): Complete$(RESET)"

re:	fclean all
