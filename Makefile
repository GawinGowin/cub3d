NAME := cub3D
LIB_NAME = libft.a

HEADER :=
SOURCES :=
LIB_SOURCES :=

# Header
HEADER += cub3d.h
HEADER += libft.h

# Sources
SOURCES += detect_event.c
SOURCES += main.c
SOURCES += set_array_from_file.c
SOURCES += valid_argument.c

# Library
## Original Libft
LIB_SOURCES += libft/ft_atoi.c
LIB_SOURCES += libft/ft_bzero.c
LIB_SOURCES += libft/ft_calloc.c
LIB_SOURCES += libft/ft_isalnum.c
LIB_SOURCES += libft/ft_isalpha.c
LIB_SOURCES += libft/ft_isascii.c
LIB_SOURCES += libft/ft_isdigit.c
LIB_SOURCES += libft/ft_isprint.c
LIB_SOURCES += libft/ft_itoa.c
LIB_SOURCES += libft/ft_memchr.c
LIB_SOURCES += libft/ft_memcmp.c
LIB_SOURCES += libft/ft_memcpy.c
LIB_SOURCES += libft/ft_memmove.c
LIB_SOURCES += libft/ft_memset.c
LIB_SOURCES += libft/ft_putchar_fd.c
LIB_SOURCES += libft/ft_putendl_fd.c
LIB_SOURCES += libft/ft_putnbr_fd.c
LIB_SOURCES += libft/ft_putstr_fd.c
LIB_SOURCES += libft/ft_split.c
LIB_SOURCES += libft/ft_strchr.c
LIB_SOURCES += libft/ft_strdup.c
LIB_SOURCES += libft/ft_striteri.c
LIB_SOURCES += libft/ft_strjoin.c
LIB_SOURCES += libft/ft_strlcat.c
LIB_SOURCES += libft/ft_strlcpy.c
LIB_SOURCES += libft/ft_strlen.c
LIB_SOURCES += libft/ft_strmapi.c
LIB_SOURCES += libft/ft_strncmp.c
LIB_SOURCES += libft/ft_strnstr.c
LIB_SOURCES += libft/ft_strrchr.c
LIB_SOURCES += libft/ft_strtrim.c
LIB_SOURCES += libft/ft_substr.c
LIB_SOURCES += libft/ft_tolower.c
LIB_SOURCES += libft/ft_toupper.c
LIB_SOURCES += libft/ft_lstadd_back.c
LIB_SOURCES += libft/ft_lstadd_front.c
LIB_SOURCES += libft/ft_lstclear.c
LIB_SOURCES += libft/ft_lstdelone.c
LIB_SOURCES += libft/ft_lstiter.c
LIB_SOURCES += libft/ft_lstlast.c
LIB_SOURCES += libft/ft_lstmap.c
LIB_SOURCES += libft/ft_lstnew.c
LIB_SOURCES += libft/ft_lstsize.c
## Extra Libft
LIB_SOURCES += libft/ft_strcmp.c
LIB_SOURCES += libft/ft_strjoin_sep.c

SOURCES_PREFIX = cmd/$(NAME)/
LIB_SOURCES_PREFIX = pkg/

LIBRARY_DIR = lib
HEADER_DIR = include

CC := cc
CFLAGS := -Wall -Wextra -Werror
IFLAGS := -I$(HEADER_DIR)
LFLAGS := -lmlx_Linux -lXext -lX11 -lm -L$(LIBRARY_DIR) -lft
DFLAGS := -fdiagnostics-color=always -g3 -fsanitize=address

ifdef DEBUG
CFLAGS += $(DFLAGS)
endif


SOURCES := $(addprefix $(SOURCES_PREFIX),$(SOURCES))
OBJS := $(SOURCES:.c=.o)
LIB_SOURCES := $(addprefix $(LIB_SOURCES_PREFIX),$(LIB_SOURCES))
LIB_OBJS := $(LIB_SOURCES:.c=.o)

MLX_HEADER := $(addprefix $(HEADER_DIR)/,mlx.h)
MLX_LIB := $(addprefix $(LIBRARY_DIR)/,libmlx.a)

.PHONY: all
all: init $(NAME)

$(NAME): $(LIB_NAME) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $@

$(LIB_NAME): $(LIB_OBJS)
	ar rcs $(LIBRARY_DIR)/$@ $(LIB_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

.PHONY: init
init: $(MLX_HEADER) $(MLX_LIB)

$(MLX_HEADER): 
	mkdir -p $(HEADER_DIR)
	sh install_minilibx.sh

$(MLX_LIB): 
	mkdir -p $(LIBRARY_DIR)
	sh install_minilibx.sh

.PHONY: clean
clean: 
	rm -f *.o

.PHONY: fclean
fclean:
	rm -f cub3D

.PHONY: re
re: fclean all
