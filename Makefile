CFLAGS := -Wall -Wextra -Werror
CC = cc

NAME = libft.a
FILES = ft_atoi ft_isalnum ft_isdigit ft_lstadd_back\
ft_lstdelone ft_lstmap ft_memchr ft_memmove ft_putendl_fd\
ft_split ft_striteri ft_strlcpy ft_strncmp ft_strtrim ft_toupper\
ft_bzero ft_isalpha ft_lstadd_front\
ft_lstiter ft_lstnew ft_memcmp ft_memset ft_putnbr_fd ft_strchr\
ft_strjoin ft_strlen ft_strnstr ft_substr ft_calloc  ft_isascii\
ft_isprint ft_itoa ft_lstclear ft_lstlast ft_lstsize ft_memcpy\
ft_putchar_fd ft_putstr_fd ft_strdup ft_strlcat ft_strmapi\
ft_strrchr ft_tolower ft_islower ft_isupper ft_isspace ft_printf

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

.PHONY: all, fclean, clean, re

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

