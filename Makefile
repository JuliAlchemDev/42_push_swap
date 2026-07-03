NAME = push_swap

SRC_DIR = ./srcs
OBJ_DIR = ./obj
LIB_DIR = ./Libft
DEP_DIR = ./include
SRCS = \
       srcs/main.c \
       srcs/clear_stack.c \
	   srcs/compute_disorder.c \
	   srcs/error.c \
       srcs/load_stack.c \
	   srcs/input_parser.c \
	   srcs/insertion_sort.c \
       srcs/push.c \
       srcs/rotate.c \
       srcs/rotate_reverse.c \
       srcs/swap.c \
	   srcs/is_valid_int.c \
	   srcs/ft_strcmp.c \
       utils/putstack.c \
	   utils/display_stacks.c

OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(notdir $(SRCS)))
LIBFT = $(LIB_DIR)/libft.a
DEPS = $(DEP_DIR)/push_swap.h

CC = cc
FLAGS = -Wall -Werror -Wextra
RM = rm -f

VPATH = srcs utils

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: %.c $(DEPS) | $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIB_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) $^ -o $@

.PHONY: all clean fclean re

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
