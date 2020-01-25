NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIB_SRC_FOLDER = ./libft/
LIB_SRC_FILES = ft_atoi.c ft_atoi_base.c ft_bzero.c ft_convert_base.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_isprint.c ft_itoa.c ft_itoa_base_str.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c \
ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_max.c  ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
ft_memmove.c ft_memset.c ft_min.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
ft_putstr.c ft_putstr_fd.c ft_split.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c \
ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c \
ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c

LIB_OBJ_FOLDER = ./libft/obj/
LIB_OBJ_FILES = $(LIB_SRC_FILES:.c=.o)
LIB_OBJ = $(addprefix $(LIB_OBJ_FOLDER), $(LIB_OBJ_FILES))

LIB_HDR_FOLDER = ./libft/
LIB_HDR_FILE = libft.h
LIB_HDR = $(addprefix $(LIB_HDR_FOLDER), $(LIB_HDR_FILE))


SRC_FOLDER = ./src/
SRC_FILES = bin.c buffer.c buffer2.c char.c colors.c hex.c int_utils.c loop.c oct.c \
parsing.c parsing_bis.c pointers.c signed.c string.c unsigned.c floats/deal_inf_nan.c floats/double.c \
floats/get_bigint_info.c floats/long_double.c floats/op.c floats/print_big_dbl.c \
floats/print_dec_part.c floats/print_int_part.c floats/print_small_dbl.c \
floats/round_up.c floats/store_dbl.c floats/store_ldbl.c floats/utils.c
SRC = $(addprefix $(SRC_FOLDER), $(SRC_FILES))

OBJ_FOLDER = ./obj/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_FOLDER), $(OBJ_FILES))

HDR_FOLDER = ./includes/
HDR_FILES = prototypes.h structs.h
HDR = $(addprefix $(HDR_FOLDER), $(HDR_FILES))

all: $(NAME)

$(NAME): $(OBJ) $(LIB_OBJ)
	ar -rc $(NAME) $(OBJ) $(LIB_OBJ)
	ranlib $(NAME)

$(LIB_OBJ_FOLDER)%.o:$(LIB_SRC_FOLDER)%.c $(LIB_HDR)
	mkdir -p $(LIB_OBJ_FOLDER)
	$(CC) -c $(CFLAGS) -I$(LIB_HDR_FOLDER) -o $@ $<

$(OBJ_FOLDER)%.o:$(SRC_FOLDER)%.c $(HDR)
	mkdir -p $(OBJ_FOLDER)
	mkdir -p $(OBJ_FOLDER)floats/
	$(CC) -c $(CFLAGS) -I$(HDR_FOLDER) -o $@ $<

clean:
	rm -rf $(OBJ) $(OBJ_FOLDER)floats/ $(OBJ_FOLDER)
	rm -rf $(LIB_OBJ) $(LIB_OBJ_FOLDER)

fclean: clean
	rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
