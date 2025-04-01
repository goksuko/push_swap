NAME = push_swap
BONUS_NAME = checker
LIBFT = ./Libft/libft.a
FT_PRINTF = ./ft_printf/ft_printf.a
HEAD = ../Include/push_swap.h

SRCS_1 = \
			main.c \

SRCS_2 = \
			atois.c \
			checks_new.c \
			find_index.c \
			maths.c	\
			oper_swap.c \
			oper_push.c \
			oper_rotate.c \
			oper_reverse.c \
			new_sort.c \
			new_sort_utils.c \
			new_sort_utils2.c \
			radix.c \
			radix_utils.c \
			sort.c \
			utils.c \
			utils2.c \

SRCS_DIR = Sources

OBJS_1 = $(SRCS_1:%.c=$(OBJS_DIR)/%.o)

OBJS_2 = $(SRCS_2:%.c=$(OBJS_DIR)/%.o)

OBJS_DIR = Objects

BONUS_SRCS = \
			checker.c \
			checker2.c \

BONUS_SRCS_DIR = Sources/Bonus

BONUS_OBJS = $(BONUS_SRCS:%.c=$(BONUS_OBJS_DIR)/%.o)

BONUS_OBJS_DIR = Objects/Bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g

Reset		=	"\033[0m"
Green		=	"\033[0;32m"
Yellow		=	"\033[0;33m"
Blue		=	"\033[0;34m"

all: $(NAME)

$(NAME): $(FT_PRINTF) $(LIBFT) $(OBJS_DIR) $(OBJS_1) $(OBJS_2)
	@echo ${Blue} Building ${NAME} ${Reset}
	@$(CC) $(CFLAGS) $(OBJS_1) $(OBJS_2) $(FT_PRINTF) $(LIBFT) -o $(NAME)
	@make bonus --no-print-directory
	@echo ${Green} Building Complete ${Reset}
	@echo ${Green} 🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳 ${Reset}


$(LIBFT):
	@$(MAKE) --no-print-directory -C ./Libft

$(FT_PRINTF):
	@$(MAKE) --no-print-directory -C ./ft_printf

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
	@$(CC) $(CFLAGS) -c -o $@ $^

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(FT_PRINTF) $(LIBFT) $(OBJS_DIR) $(OBJS_2) $(BONUS_OBJS_DIR) $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(OBJS_2) $(FT_PRINTF) $(LIBFT) -o $(BONUS_NAME)

$(BONUS_OBJS_DIR):
	@mkdir -p $(BONUS_OBJS_DIR)

$(BONUS_OBJS_DIR)/%.o:$(BONUS_SRCS_DIR)/%.c
	@$(CC) $(CFLAGS) -c -o $@ $^ -I $(HEAD)

clean:
	@echo ${Yellow} Deleting ${NAME} ${Reset}
	@rm -rf $(OBJS_DIR)
	@$(MAKE) --no-print-directory clean -C ./Libft
	@$(MAKE) --no-print-directory clean -C ./ft_printf
	@echo ${Green} Deleting Complete ${Reset}

fclean:
	@echo ${Yellow} Deleting ${NAME} ${Reset}
	@rm -f $(NAME) $(BONUS_NAME)
	@rm -f ./a.out
	@rm -f ./Sources/a.out
	@rm -f ./push_swap
	@rm -rf $(OBJS_DIR)
	@$(MAKE) --no-print-directory fclean -C ./Libft
	@$(MAKE) --no-print-directory fclean -C ./ft_printf
	@echo ${Green} Deleting Complete ${Reset}

re: fclean all

.PHONY: all bonus clean fclean re
