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

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I. -I$(INC_DIR) -I$(LIBFT_DIR) -MMD -MP

AR = ar
ARFLAGS = -rcs

RM = rm -f

#------------------------------------------------------------------------------#
#                                  DIRECTORIES                                 #
#------------------------------------------------------------------------------#

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

#------------------------------------------------------------------------------#
#                                    SOURCES                                   #
#------------------------------------------------------------------------------#

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

LIBFT_SRCS = \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_atoi.c \
	ft_strlen.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strnstr.c \
	ft_strncmp.c \
	ft_strdup.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_calloc.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS = $(OBJS:.o=.d)
LIBFT_OBJS = $(addprefix $(LIBFT_DIR)/,$(LIBFT_SRCS:.c=.o))

#------------------------------------------------------------------------------#
#                                     RULES                                    #
#------------------------------------------------------------------------------#

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(RM) $@
	$(AR) $(ARFLAGS) $@ $(LIBFT_OBJS) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS) $(DEPS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

# -----------------------------------------------------------------------------#
# Optional local tests - keep commented out for submission.
# Uncomment locally only if you also keep the auxiliary `main.c` outside the
# deliverable version of the project.
#
# TEST_SRC = main.c
# TEST_BIN = main.out
#
# $(TEST_BIN): $(TEST_SRC) $(NAME)
# 	$(CC) $(CFLAGS) -I. -I$(INC_DIR) -I$(LIBFT_DIR) $(TEST_SRC) -L. -lftprintf -o $(TEST_BIN)
#
# test: $(TEST_BIN)
# 	./$(TEST_BIN)
#
# test_clean:
# 	$(RM) $(TEST_BIN)

-include $(DEPS)

.PHONY: all clean fclean re
