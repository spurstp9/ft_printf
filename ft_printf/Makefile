.PHONY: all clean fclean re

NAME = libftprintf.a

LIBFT_SRC_FOLDER = ./libft/
LIBFT_SRC_FILES = ft_atoi.c ft_atoi_base.c ft_bzero.c ft_convert_base.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_isprint.c ft_itoa.c ft_itoa_base_str.c ft_lltoa.c ft_lltoa_base_str.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c \
ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_max.c  ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
ft_memmove.c ft_memset.c ft_min.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
ft_putstr.c ft_putstr_fd.c ft_split.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c \
ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c \
ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_ulltoa.c ft_ulltoa_base_str.c
LIBFT_SRC = $(addprefix $(LIBFT_SRC_FOLDER), $(LIBFT_SRC_FILES))

LIB_OBJ_FOLDER = ./obj/
LIBFT_OBJ_FILES = $(LIBFT_SRC_FILES:.c=.o)
LIBFT_OBJ = $(addprefix $(LIB_OBJ_FOLDER), $(LIBFT_OBJ_FILES))

LIBFT_INC = -I./libft
INC = -I./includes
HEADERS_PATH =./includes/
HEADERS_FILES = bigint.h ft_printf.h struct.h
HEADERS = $(addprefix $(HEADERS_PATH), $(HEADERS_FILES))

SRC_FOLDER = ./srcs/
SRC_FILES = loop.c misc.c numbers.c parsing.c parsing2.c floats/get_bigint_info.c floats/dbl_main.c \
floats/manage_dbl.c floats/manage_ldbl.c floats/op.c floats/print_big_dbl.c floats/print_common.c floats/print_dbl.c \
floats/utils.c
SRC = $(addprefix $(SRC_FOLDER), $(SRC_FILES))

OBJ_FOLDER = ./obj/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_FOLDER), $(OBJ_FILES))

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_OBJ) $(HEADERS)
	ar -rc $(NAME) $(LIBFT_OBJ) $(OBJ)
	ranlib $(NAME)

$(LIB_OBJ_FOLDER)%.o:$(LIBFT_SRC_FOLDER)%.c
	mkdir $(LIB_OBJ_FOLDER) 2>/dev/null || echo "" > /dev/null
	$(CC) $(CFLAGS) $(LIBFT_INC) -c $< -o $@

$(OBJ_FOLDER)%.o:$(SRC_FOLDER)%.c
	mkdir $(OBJ_FOLDER) 2>/dev/null || echo "" > /dev/null
	mkdir $(OBJ_FOLDER)floats 2>/dev/null || echo "" > /dev/null
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@rm -rf $(LIB_OBJ_FOLDER)
	@rm -rf $(OBJ_FOLDER)
	@rm -rf obj

fclean: clean
	@rm -rf $(NAME)

re: fclean all
