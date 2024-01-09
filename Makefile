###########################################################################
#### SOURCES

SRC_FOLDER	= srcs/mandatory/
SRC_FOLDER_BONUS = srcs/bonus/

SRC_FILES	= main.c mlx_init.c mandelbrot.c handle_events.c julia.c \
handle_params.c atod.c handle_color.c
SRC_FILES_BONUS = main_bonus.c mlx_init_bonus.c mandelbrot_bonus.c handle_color_bonus.c \
handle_events_bonus.c julia_bonus.c handle_params_bonus.c atod_bonus.c burningship_bonus.c \


OBJ_FILES	= $(addprefix $(SRC_FOLDER), $(SRC_FILES:%.c=%.o))
OBJ_FILES_BONUS = $(addprefix $(SRC_FOLDER_BONUS), $(SRC_FILES_BONUS:%.c=%.o))

###########################################################################
#### ARGUMENTS

NAME		= fractol
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -O3 -g3

LIBFT_PATH	= libft/
LIBFT		= $(LIBFT_PATH)libft.a
INCLUDE		= fractol.h
INCLUDE_BONUS = fractol_bonus.h
MLX_PATH	= mlx/
MLX_INCLUDE = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

RED		=	\033[0;31m
GREEN	=	\033[0;32m
YELLOW	=	\033[0;33m
BLUE	=	\033[0;34m
MAGENTA	=	\033[0;35m
CYAN	=	\033[0;36m
WHITE	=	\033[0;37m
RESET	=	\033[0m

###########################################################################
#### RULES

$(NAME): $(OBJ_FILES)
	@make -C $(LIBFT_PATH) --no-print-directory -s
	@make -C $(MLX_PATH) --no-print-directory -s
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) $(MLX_INCLUDE) -o $(NAME)
	@echo "$(MAGENTA)Les fichiers modifiés sont: $?$(RESET)"
	@echo "$(GREEN)Compilation réussie !$(RESET)"

%.o: %.c
	@echo "$(YELLOW)Compilation de $*$(RESET)"
	@$(CC) $(CFLAGS) -I$(INCLUDE) -I$(INCLUDE_BONUS) -I$(LIBFT_PATH) -I/usr/include -I$(MLX_PATH) -c $< -o $@

all : $(NAME)

clean :
	@rm -f *.o ${OBJ_FILES}
	@rm -f *.o ${OBJ_FILES_BONUS}
	@make clean -C $(LIBFT_PATH) --no-print-directory -s
	@make clean -C $(MLX_PATH) --no-print-directory -s
	@echo "$(CYAN) Nettoyage des fichiers intermédiaires $(RESET)"

fclean : clean
	@rm -f ${NAME}
	@make fclean -C $(LIBFT_PATH) --no-print-directory -s
	@echo "$(GREEN) Nettoyage terminé $(RESET)"

bonus : $(OBJ_FILES_BONUS)
	@make -C $(LIBFT_PATH) --no-print-directory -s
	@make -C $(MLX_PATH) --no-print-directory -s
	@$(CC) $(CFLAGS) $(OBJ_FILES_BONUS) $(LIBFT) $(MLX_INCLUDE) -o $(NAME)
	@echo "$(MAGENTA)Les fichiers modifiés sont: $?$(RESET)"
	@echo "$(GREEN)Compilation réussie !$(RESET)"

 
re : fclean all

.PHONY : all clean fclean re