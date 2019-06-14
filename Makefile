INCLUDES = -I ./includes
MINILIBX_INCLUDES = -I ./minilibx_macos

LIBFT = libft/libft.a

SRCS_FRACTOL =	./srcs/fractol/main.c \
				./srcs/fractol/fractol_control.c \
				./srcs/fractol/create_palette.c \
				./srcs/fractol/printing.c \
				./srcs/fractol/add_axis.c \
				./srcs/fractol/fractals/mandelbrot.c \
				./srcs/fractol/fractals/julia.c \
				./srcs/fractol/fractals/newton.c \
				./srcs/fractol/fractals/function_and_derivative.c

SRCS_CALC =		./srcs/newton_function_generator/main.c \
				./srcs/newton_function_generator/parse_input.c \
				./srcs/newton_function_generator/create_file.c

UTILS = 		./utils/struct_operations/t_point.c \
				./utils/struct_operations/t_palette.c \
				./utils/struct_operations/t_summand.c \
				./utils/clear_spaces.c \
				./utils/str_to_low.c \
				./utils/str_to_header.c

OBJ_FRACTOL = $(SRCS_FRACTOL:.c=.o)
OBJ_CALC = $(SRCS_CALC:.c=.o)
OBJ_UTILS = $(UTILS:.c=.o)

EXEC_FRACTOL = fractol
EXEC_CALC = newton

RESET = \033[0m
RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;36m
RED_EXTRA = \033[1;31m
GREEN_EXTRA = \033[1;32m
BLUE_EXTRA = \033[1;36m

%.o:%.c
	@echo "$(GREEN) - Creating $(GREEN_EXTRA)$<...$(RESET)"
	@gcc -Wall -Wextra -Werror -g -c $< -o $@ $(INCLUDES)

all: $(EXEC_FRACTOL)

$(EXEC_CALC): $(OBJ_CALC) $(OBJ_UTILS)
	@echo "$(GREEN)Making objects files for $(GREEN_EXTRA)$(EXEC_CALC)$(RESET)"
	# @make -C libft
	@echo "$(GREEN)Compiling executable $(GREEN_EXTRA)$(EXEC_CALC)$(RESET)"
	@gcc -Wall -Wextra -Werror $(OBJ_CALC) $(OBJ_UTILS) $(LIBFT) $(INCLUDES) -g -o $(EXEC_CALC)
	@echo "$(BLUE_EXTRA)$(EXEC_CALC)$(BLUE): Complete$(RESET)"

$(EXEC_FRACTOL): $(OBJ_FRACTOL) $(OBJ_UTILS)
	@echo "$(GREEN)Making objects files for $(GREEN_EXTRA)$(EXEC_FRACTOL)$(RESET)"
	# @make -C libft
	@echo "$(GREEN)Compiling executable $(GREEN_EXTRA)$(EXEC_FRACTOL)$(RESET)"
	@gcc -Wall -Wextra -Werror $(OBJ_FRACTOL) $(OBJ_UTILS) $(LIBFT) $(INCLUDES) $(MINILIBX_INCLUDES) -L minilibx_macos -lmlx -framework OpenGL -framework AppKit -g -o $(EXEC_FRACTOL)
	@echo "$(BLUE_EXTRA)$(EXEC_FRACTOL)$(BLUE): Complete$(RESET)"

clean:
	@if [ -a "srcs/fractol/main.o" ]; then \
	echo "$(RED)Deleting objects for $(RED_EXTRA)$(EXEC_FRACTOL)$(RESET)"; \
	/bin/rm -rf $(OBJ_FRACTOL); \
	fi
	@if [ -a "srcs/newton_function_generator/main.o" ]; then \
	echo "$(RED)Deleting objects for $(RED_EXTRA)$(EXEC_CALC)$(RESET)"; \
	/bin/rm -rf $(OBJ_CALC); \
	fi
	# @make -C libft clean
	@echo "$(BLUE_EXTRA)clean$(BLUE): Complete$(RESET)"

fclean: clean
	@if [ -a "$(EXEC_FRACTOL)" ]; then \
	echo "$(RED)Deleting executable $(RED_EXTRA)$(EXEC_FRACTOL)$(RESET)"; \
	/bin/rm -f $(EXEC_FRACTOL); \
	fi
	@if [ -a "$(EXEC_CALC)" ]; then \
	echo "$(RED)Deleting executable $(RED_EXTRA)$(EXEC_CALC)$(RESET)"; \
	/bin/rm -f $(EXEC_CALC); \
	fi
	# @make -C libft fclean
	@echo "$(BLUE_EXTRA)fclean$(BLUE): Complete$(RESET)"

re: fclean all
