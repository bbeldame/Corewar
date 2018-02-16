# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arosset <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/23 14:08:14 by arosset           #+#    #+#              #
#    Updated: 2017/10/25 16:25:31 by arosset          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME			= 	asm

CC				=	clang
CFLAGS			=	-Wall -Wextra -Werror
DEBUG 			= 	-g3

LIB_PATH		= 	./libft/
LIB				=	./libft/libft.a
LIB_LINK		=	./libft/libft.a

INC_PATH		= 	./include
SRC_PATH		=	./src
SRC_NAME 		=	main.c free_asm.c error.c parser.c ft_utility.c debug.c \
					struct_list.c set_name_extension.c parse_body.c
OBJ_PATH		=	./obj

OBJ_NAME		=	$(SRC_NAME:.c=.o)
INC_NAME		=	asm.h

OBJ 			= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

# COLORS
RESET			=	"\033[00m"
RED				=	"\033[31m"
GREEN			=	"\033[32m"
YELLOW			=	"\033[33m"
BLUE			= 	"\033[34m"
PURPLE			=	"\033[35m"

# MESSAGE
SUCCESS			=	$(GREEN)SUCCESS$(RESET)
OK				=	$(PURPLE)OK$(RESET)
DELETE			=	$(RED)DELETE$(RESET)
DELETE_LIB		=	$(RED)DELETE LIB$(RESET)
TEST 			= 	$(YELLOW)DEBUT TEST$(RESET)


all: $(LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(DEBUG) $(LIB_LINK) $(CFLAGS) $(OBJ)  -o $@
	@echo "Exec =>"$(YELLOW) $(NAME) $(RESET): $(SUCCESS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(DEBUG) $(CFLAGS) -o $@ -c $<
	@echo "Obj" [ $< ] $(OK)


$(LIB):
	@make -C $(LIB_PATH)

clean:
	@rm -rf $(OBJ) $(OBJ_PATH)
	@echo $(DELETE) : $(OBJ) $(OBJ_PATH)
	@make -C $(LIB_PATH) clean
	@echo $(DELETE_LIB) : Obj Libft



fclean: clean
	@rm -rf $(NAME)
	@echo $(DELETE) : $(NAME)


re: fclean all
