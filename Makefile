NAME        = cub3D
SRCS_DIR    = sources
OBJ_DIR     = bin
LIBFT_DIR   = Libft
LIBFT       = libft.a
MLX_DIR     = mlx
MLX         = libmlx.a

SRCS        = $(wildcard $(SRCS_DIR)/*.c) $(wildcard $(SRCS_DIR)/**/*.c)
OBJS        = $(patsubst $(SRCS_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

CCFLAGS     = -Wall -Wextra -Werror -g -I includes
MLXFLAGS    = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

INC         = includes
OS			= mac

GREEN       = \033[38;5;47m
YELLOW      = \033[38;5;226m
RED         = \033[38;5;196m
CYAN        = \033[1;36m
RESET       = \033[0m

ifeq ($(MODE), debug)
    FLAGS += -fsanitize=address
endif

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJ_DIR)
	@cc $(CCFLAGS) -c $< -o $@
	@echo "[$(CYAN)compiling$(RESET)]:\t $<"

all: $(NAME)
	@echo "[$(GREEN)DONE$(RESET)]:\t\t $(GREEN)$(NAME)$(RESET)"

$(NAME): $(OBJS) $(LIBFT_DIR)/$(LIBFT) $(MLX_DIR)/$(MLX)
	@cc $(CCFLAGS) $(MLXFLAGS) -I $(INC) $(OBJS) $(MLX_DIR)/$(MLX) $(LIBFT_DIR)/$(LIBFT) -o $(NAME)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)/
	@mkdir $(OBJ_DIR)/render
	@mkdir $(OBJ_DIR)/init_exit

$(LIBFT_DIR)/$(LIBFT):
	@echo "[$(CYAN)compiling$(RESET)]:\t $@"
	@make -C $(LIBFT_DIR)

$(MLX_DIR)/$(MLX):
	@echo "[$(CYAN)compiling$(RESET)]:\t $@"
	@make -C $(MLX_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@echo "$(YELLOW)Removing objects files$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@rm -rf $(MLX_DIR)/$(MLX)
	@echo "$(RED)removing $(NAME) executable$(RESET)"

re: fclean all

.PHONY: all clean fclean re error
