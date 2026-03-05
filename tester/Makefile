# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/09 14:33:18 by esobrino          #+#    #+#              #
#    Updated: 2026/02/24 18:26:28 by esobrino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#------------------------------------------------------------------------------#
#                                  VARIABLES                                   #
#------------------------------------------------------------------------------#

# Nombre de la librería
NAME = test.out 

# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
IFLAGS = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(LIBFTPRINTF_DIR)

# Comando para crear librería
AR = ar -rcs

# Comando para eliminar archivos
RM = rm -f

# Archivos fuente
SRCS = test.c 

# Archivos objeto
OBJS = $(SRCS:.c=.o) 

# Directorios de archivos header
INC_DIR = .

# libft 
LIBFT_DIR = $(LIBFTPRINTF_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a

# libftprintf 
LIBFTPRINTF_DIR = ..
LIBFTPRINTF = $(LIBFTPRINTF_DIR)/libftprintf.a

#------------------------------------------------------------------------------#
#                                    REGLAS                                    #
#------------------------------------------------------------------------------#

# Regla principal
all: $(NAME)

# Crear la librería
$(NAME): $(OBJS) 	
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTPRINTF) $(LIBFT) -o $(NAME)

# Compilar archivos .c a .o
%.o:%.c $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

# Compilación de libftprintf
$(LIBFTPRINTF): $(LIBFT)
	make -C $(LIBFTPRINTF_DIR)

# Compilación de libft
$(LIBFT): 
	make -C $(LIBFT_DIR)

# Eliminar archivos .o
clean: 
	$(RM) $(OBJS)
	make clean -C $(LIBFTPRINTF_DIR)

# Eliminar archivos .o y librería
fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFTPRINTF_DIR)

# Limpiar y recompilar todo
re: fclean all

.PHONY: all clean fclean re
