# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 19:05:39 by aouichou          #+#    #+#              #
#    Updated: 2023/08/17 09:19:31 by aouichou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_atoi.c					\
		ft_atoi_base.c				\
		ft_bzero.c					\
		ft_isalnum.c				\
		ft_isalpha.c				\
		ft_isascii.c				\
		ft_isdigit.c				\
		ft_isprint.c				\
		ft_strlen.c					\
		ft_memset.c					\
		ft_memcpy.c					\
		ft_memmove.c				\
		ft_strlcpy.c				\
		ft_strlcat.c				\
		ft_tolower.c				\
		ft_toupper.c				\
		ft_strchr.c					\
		ft_strdup.c					\
		ft_strrchr.c				\
		ft_strncmp.c				\
		ft_memchr.c					\
		ft_memcmp.c					\
		ft_strnstr.c				\
		ft_calloc.c					\
		ft_substr.c					\
		ft_strjoin.c				\
		ft_strtrim.c				\
		ft_split.c					\
		ft_itoa.c					\
		ft_strmapi.c				\
		ft_striteri.c				\
		ft_putchar_fd.c				\
		ft_putstr_fd.c				\
		ft_putendl_fd.c				\
		ft_putnbr_fd.c 				\
		ft_strnew.c 				\
		ft_printf.c					\
		ft_printf_utilis.c			\
		ft_printf_utilis2.c			\
		ft_flags.c					\
		ft_itoa_base.c				\
		ft_print_chars.c			\
		ft_print_hex.c				\
		ft_print_numbers.c			\
		get_next_line.c				\
		ft_strchri.c				\
		ft_substr_free.c			\
		ft_strjoin_free.c			\
		ft_strtok.c					\
		ft_strrtok.c				\
		ft_strsplit_white_spaces.c	\
		ft_strstr.c					\
		ft_str_find_replace.c		\
		ft_lstnew.c 				\
		ft_lstadd_front.c 			\
		ft_lstsize.c 				\
		*ft_lstlast.c 				\
		ft_lstadd_back.c 			\
		ft_lstdelone.c 				\
		ft_lstclear.c 				\
		ft_lstiter.c 				\
		ft_lstmap.c					\
		ft_array_size.c				\
		ft_array_dup.c				\
		ft_array_free.c				\
		ft_array_expand.c			\
		ft_array_contract.c			\
		ft_strchri_set.c			\
		ft_countchar.c				\
		ft_array_replace.c			\
		ft_isspace.c				\
		ft_array_print_fd.c			\
		ft_array_sort.c				\
		ft_strcpy.c					\
		ft_free.c					\
		ft_clean_array.c			\
		ft_atof.c					\
		ft_realloc.c				\
		ft_arradd_int.c				\
		ft_strcpy_end.c				\
		ft_lstfind.c				\


OBJS = $(SRCS:.c=.o)
INCLUDES =
CC = gcc
CCFLAGS = -Wall -Wextra -Werror -g
YLW = '\033[0;33m'
BIGRN = '\033[1;92m'
BRED = '\033[1;31m'
BIRED = '\033[1;91m'
CYN = '\033[0;36m'
BIPRPL = '\033[1;95m'
COLOR_OFF = '\033[0m'

all: $(NAME)

$(NAME) :
		@echo "$(YLW)Making library...$(COLOR_OFF)"
		@-$(CC) $(CCFLAGS) -c $(SRCS) && ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)
		@echo "$(BIGRN)SUCCESS!!!$(COLOR_OFF)"

clean:
		@-(rm -f $(OBJS))
		@echo "$(BRED)Objs files deleted$(COLOR_OFF)"

fclean: clean
		@-rm -f $(NAME)
		@echo "$(BIRED)Library deleted$(COLOR_OFF)"

re: fclean all
