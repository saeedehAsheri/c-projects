# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sasheri <sasheri@student.42.fr>            +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/27 12:40:45 by sasheri           #+#    #+#              #
#    Updated: 2025/10/27 13:36:48 by sasheri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar
ARFLAGS		= rcs
RM			= rm -f

SRC_DIR		= src
INC_DIR		= ft_printf
LIBFT_DIR	= libft

INCLUDES	= -I$(INC_DIR) -I$(LIBFT_DIR)
LIBFT		= $(LIBFT_DIR)/libft.a

SRC			= \
	$(SRC_DIR)/ft_printf.c \
	$(SRC_DIR)/p_str.c \
	$(SRC_DIR)/p_pointer.c \
	$(SRC_DIR)/p_nbr.c \
	$(SRC_DIR)/p_uint.c \
	$(SRC_DIR)/p_lowhex.c \
	$(SRC_DIR)/p_highhex.c

OBJ			= $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	@cp $(LIBFT) $(NAME)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	@echo "$(NAME) created successfully!"

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/ft_printf.h
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Object files removed."

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(NAME) and libft cleaned."

re: fclean all
