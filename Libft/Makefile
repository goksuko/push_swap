NAME = libft.a

SOURCES_MAND = \
			ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			get_next_line.c \
			get_next_line_utils.c

SOURCES_BONUS = \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c


OBJS_MAND = $(SOURCES_MAND:.c=.o)
OBJS_BONUS = $(SOURCES_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar

Reset		=	"\033[0m"
Green		=	"\033[0;32m"
Yellow		=	"\033[0;33m"
Blue		=	"\033[0;34m"

all: $(NAME)

$(NAME): $(OBJS_MAND) 
	@echo ${Blue} Building ${NAME} ${Reset}
	@$(AR) rcs $(NAME) $(OBJS_MAND)

%.o: %.c
	@$(CC) $(CFLAGS) -g -c $< -o $@

bonus: $(NAME) $(OBJS_BONUS)
	@$(AR) rcs $(NAME) $(OBJS_MAND) $(OBJS_BONUS)

clean:
	@echo ${Yellow} Deleting ${NAME} ${Reset}
	@rm -f $(OBJS_MAND) $(OBJS_BONUS)

fclean:clean
	@echo ${Yellow} Deleting ${NAME} ${Reset}
	@rm -f $(NAME) ./a.out

re: fclean all

.PHONY: all bonus clean fclean re