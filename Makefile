# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 13:41:10 by fhenrion          #+#    #+#              #
#    Updated: 2019/11/08 10:56:03 by fhenrion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HDR_NAME = libft.h

SRC_NAME = memset bzero memcpy memccpy memmove memchr memcmp strlen islower \
isupper isalpha isdigit isalnum isascii isprint toupper tolower strchr \
strrchr strncmp strlcpy strlcat strnstr atoi calloc strdup substr strjoin \
strtrim split itoa strmapi putchar_fd putstr_fd putendl_fd putnbr_fd
SRC = $(addprefix ft_,$(SRC_NAME))
SRC_BONUS_NAME = lstnew lstadd_front lstsize lstlast lstadd_back lstdelone \
lstclear lstiter lstmap lstat putstrlst_fd putnbrlst_fd lstreverse lstmerge \
isspace memdel putchar putendl putnbr putstr strchri strrchri substrchr \
substrrchr lststrsort lststrrsort strcmp lstchrsplit putstrtab_fd tabstrsort \
tabstrrsort
SRC_BONUS = $(addprefix ft_,$(SRC_BONUS_NAME))

O_SRC = $(addsuffix .o,$(SRC))
O_BONUS_SRC = $(addsuffix .o,$(SRC_BONUS))

CC = gcc
CFLAGS = -Werror -Wall -Wextra

.PHONY: clean fclean all re bonus

all: $(O_SRC) $(NAME)
	@echo "\033[0;32mLibrary Compilation OK\033[0m"

bonus: $(O_SRC) $(O_BONUS_SRC)
	@ar rc $(NAME) $(O_SRC) $(O_BONUS_SRC)
	@ranlib $(NAME)
	@echo "\033[0;32mLibrary Bonus Addition OK\033[0m"

$(NAME):
	@ar rc $@ $(O_SRC)
	@ranlib $@

%.o : %.c ${HDR_NAME}
	$(CC) -c $(CFLAGS) -I $(HDR_NAME) $< -o $@

clean:
	@/bin/rm -f $(O_SRC) $(O_BONUS_SRC)
	@/bin/rm -f libft.h.gch
	@echo "\033[0;32mObjects files cleaning OK\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[0;32mLibrary cleaning OK\033[0m"

re: fclean all
