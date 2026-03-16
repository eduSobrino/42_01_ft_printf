# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/09 14:33:18 by esobrino          #+#    #+#              #
#    Updated: 2026/03/16 21:11:02 by esobrino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#------------------------------------------------------------------------------#
#                                    CONFIG                                    #
#------------------------------------------------------------------------------#

# Library Name
NAME = libftprintf.a

# Compilator and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I. -I$(INC_DIR) -I$(LIBFT_DIR)

# Command to linking *.o files and create the *.a library
AR = ar -rcs

# Command to remove files
RM = rm -f

# Test (optional, outside mandatory flow)
TEST_SRC = main.c
TEST_BIN = main.out
TEST_INCLUDES = -I. -I$(LIBFT_DIR) -I$(INC_DIR)

#------------------------------------------------------------------------------#
#                                  DIRECTORIES                                 #
#------------------------------------------------------------------------------#

# Source Files Directories
SRC_DIR = src

# Object Files Direrctorie
OBJ_DIR = obj

# Header Files Directorie
INC_DIR = inc 

# libft 
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

#------------------------------------------------------------------------------#
#                                    SOURCES                                   #
#------------------------------------------------------------------------------#

# Source files
SRCS = \
	$(SRC_DIR)/ft_printf.c \
	$(SRC_DIR)/parser/init_format.c \
	$(SRC_DIR)/parser/format_parser.c \
	$(SRC_DIR)/parser/parse_number_sat.c \
	$(SRC_DIR)/dispatcher/get_spec_table.c \
	$(SRC_DIR)/dispatcher/handler_selector.c \
	$(SRC_DIR)/dispatcher/priority_rules.c \
	$(SRC_DIR)/utils/number_printer.c \
	$(SRC_DIR)/utils/text_printer.c \
	$(SRC_DIR)/utils/buffer_manager.c \
	$(SRC_DIR)/handler/handler_c.c \
	$(SRC_DIR)/handler/handler_di.c \
	$(SRC_DIR)/handler/handler_p.c \
	$(SRC_DIR)/handler/handler_s.c \
	$(SRC_DIR)/handler/handler_u.c \
	$(SRC_DIR)/handler/handler_x.c \
	$(SRC_DIR)/handler/handler_percent.c \
 

# Object files 
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS)) 

#------------------------------------------------------------------------------#
#                                     RULES                                    #
#------------------------------------------------------------------------------#

# Make
all: $(NAME)

# Linking *.o to create library
$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME) # Copies libft.a to the root directorie with the name libftprint.a
	$(AR) $(NAME) $(OBJS) # Include all *.o files inside the libftprintf.a, where there are all libft *.o files

# Compiling *.c files to *.o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compilación de libft
$(LIBFT): 
	make -C $(LIBFT_DIR)

# Removing all *.o files
clean: 
	$(RM) $(OBJS)
	make clean -C $(LIBFT_DIR)

# Removing all, libftprintf.a and *.o files
fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

# Cleans and recompiles everything
re: fclean all	 

# Compiles main.c for testing 
$(TEST_BIN): $(TEST_SRC) $(NAME)
	$(CC) $(CFLAGS) $(TEST_INCLUDES) $(TEST_SRC) -L. -lftprintf -o $(TEST_BIN)

test: $(TEST_BIN)
	./$(TEST_BIN)

# Cleans main.out
test_clean:
	$(RM) $(TEST_BIN)

# PHONY commands
.PHONY: all clean fclean re test test_clean
