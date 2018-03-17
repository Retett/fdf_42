#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/24 16:01:22 by ayavorsk          #+#    #+#              #
#    Updated: 2017/10/24 16:01:22 by ayavorsk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

HEAD = fdf.h

SRC = main.c\
	ft_error.c\
	get_next_line.c\
	read_file.c\
	put_map.c\
	ft_mlx_tools.c\
		
LIBFT = libft/

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra -g
FRAM = -L minilibx -I minilibx -lmlx -framework OpenGL -framework AppKit -g

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) $(FRAM) -o $(NAME) $(OBJ) -L $(LIBFT) -lft

%.o: %.c $(HEAD)
	@$(CC) $(FLAGS) -c $<

clean:
	rm -f $(OBJ)
	@make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: re all clean fclean