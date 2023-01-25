# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 12:08:36 by waraissi          #+#    #+#              #
#    Updated: 2023/01/24 16:54:09 by waraissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libft.a

CC = cc

FLAGS = -Wall -Wextra -Werror

AR = ar -rcs

SRCS = ft_isalpha \
			ft_isdigit \
			ft_isalnum \
			ft_isascii \
			ft_isprint \
			ft_strlen \
			ft_memset \
			ft_bzero \
			ft_memcpy \
			ft_memmove \
			ft_strlcpy \
			ft_strlcat \
			ft_toupper \
			ft_tolower \
			ft_strchr \
			ft_memcmp \
			ft_atoi \
			ft_strdup \
			ft_calloc \
			ft_strncmp \
			ft_strnstr \
			ft_strrchr \
			ft_memchr \
			ft_substr \
			ft_strjoin \
			ft_strtrim \
			ft_split \
			ft_itoa \
			ft_strmapi \
			ft_striteri \
			ft_putchar_fd \
			ft_putstr_fd \
			ft_putendl_fd \
			ft_putnbr_fd \
			ft_lstnew\
 			ft_lstadd_front\
 			ft_lstsize\
 			ft_lstlast\
 			ft_lstadd_back\
 			ft_lstdelone\
 			ft_lstclear\
 			ft_lstiter\
 			ft_lstmap \
			get_next_line\
			ft_putchar\
			ft_putnbr\
			ft_putstr\
 			ft_putnbr_base_upper\
	 		ft_putnbr_base_lower\
	   		ft_putnbr_unsigned\
		   	ft_putnbr_base\
			ft_strjoin_sep\
			ft_strjoin_free\
		   	ft_printf\
			ft_strcmp

OBJ_DIR = ../../bin/libft_global/

OBJCTS_OK = $(SRCS:=.o)

OBJCTS = ${addprefix $(OBJ_DIR),$(OBJCTS_OK)}

all: ${NAME}

${NAME}: ${OBJCTS}
	@${AR} ${NAME} ${OBJCTS}

$(OBJ_DIR)%.o: %.c ../../inc/libft.h
	@mkdir -p $(OBJ_DIR)
	${CC} ${FLAGS} -c $< -o $@
	
clean:
	@rm $(OBJCTS)
fclean: clean
	@rm -rf ${NAME} $(OBJ_DIR)

re: fclean all