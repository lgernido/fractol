###########################################################################
#### ARGUMENTS

NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
INCLUDE		= libft.h
AR 			= ar -rc 

###########################################################################
#### SOURCES

FT_IS = ft_is/ft_isalnum.c ft_is/ft_isalpha.c ft_is/ft_isascii.c ft_is/ft_isdigit.c \
ft_is/ft_isprint.c

FT_LS = ft_ls/ft_lstadd_back.c ft_ls/ft_lstadd_front.c ft_ls/ft_lstclear.c ft_ls/ft_lstdelone.c \
ft_ls/ft_lstiter.c ft_ls/ft_lstlast.c ft_ls/ft_lstmap.c ft_ls/ft_lstnew.c ft_ls/ft_lstsize.c

FT_MEM = ft_mem/ft_memchr.c ft_mem/ft_memcmp.c ft_mem/ft_memcpy.c ft_mem/ft_memmove.c ft_mem/ft_memset.c

FT_PRINTF = ft_printf/ft_easyprint.c ft_printf/ft_printf.c ft_printf/ft_printhex.c ft_printf/ft_printptr.c\
ft_printf/ft_printui.c 

FT_PUT = ft_put/ft_putchar.c ft_put/ft_putchar_fd.c ft_put/ft_putendl_fd.c ft_put/ft_putnbr_fd.c ft_put/ft_putstr.c 

FT_STR = ft_str/ft_strchr.c ft_str/ft_strdup.c ft_str/ft_striteri.c ft_str/ft_strjoin.c ft_str/ft_strlcat.c ft_str/ft_strlcpy.c \
ft_str/ft_strlen.c ft_str/ft_strmapi.c ft_str/ft_strncmp.c ft_str/ft_strndup.c ft_str/ft_strnstr.c ft_str/ft_strrchr.c ft_str/ft_strtrim.c\
ft_str/ft_substr.c 

GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \

OTHERS = others/ft_atoi.c others/ft_bzero.c others/ft_calloc.c others/ft_itoa.c others/ft_split.c others/ft_tolower.c others/ft_toupper.c

SRC_FILES	= $(FT_IS) $(FT_LS) $(FT_MEM) $(FT_PRINTF) $(FT_PUT) $(FT_STR) $(GNL) $(OTHERS)

OBJ_FILES	= $(SRC_FILES:.c=.o)

###########################################################################
#### RULES

$(NAME) : ${OBJ_FILES}
		${AR} ${NAME} ${OBJ_FILES}

%.o: %.c $(INCLUDE)
	$(CC) $(FLAGS) -I ./ -c $< -o $@

all : clean fclean

clean :
	rm -f *.o
	rm -f *.o ${OBJ_FILES}

fclean : clean
	rm -f ${NAME}

re : fclean ${NAME}

.PHONY : bonus all clean fclean re


