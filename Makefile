NAME = push_swap

SRC_DIR = ./srcs
OBJ_DIR = ./obj
LIB_DIR = ./Libft
PRINTF_DIR = ./libftprintf
DEP_DIR = ./include
SRCS = \
	   srcs/bucket_sort.c \
       srcs/clear_stack.c \
	   srcs/compute_disorder.c \
	   srcs/error.c \
	   srcs/ft_putbench.c \
	   srcs/ft_putdisorder.c \
	   srcs/ft_strcmp.c \
	   srcs/input_parser.c \
	   srcs/insertion_sort.c \
	   srcs/is_valid_int.c \
       srcs/load_stack.c \
       srcs/main.c \
       srcs/push.c \
	   srcs/rewind.c \
       srcs/rotate_reverse.c \
       srcs/rotate.c \
	   srcs/select_sort.c \
       srcs/swap.c \
       utils/putstack.c \
	   utils/display_stacks.c

OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(notdir $(SRCS)))
LIBFT = $(LIB_DIR)/libft.a
LIBPRINTF = $(PRINTF_DIR)/libftprintf.a
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

$(LIBPRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJS) $(LIBFT) $(LIBPRINTF)
	$(CC) $(FLAGS) $^ -o $@

.PHONY: all clean fclean re

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
