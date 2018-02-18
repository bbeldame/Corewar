# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/18 16:15:40 by bbeldame          #+#    #+#              #
#    Updated: 2018/02/18 16:31:55 by bbeldame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../corewar

FLAGS = -Wall -Wextra -Werror

LIBFTA = libft.a

LIBFTDIR = ../libft
OBJDIR = ./obj/
INCDIR = ./includes
SRCDIR = ./srcs/

SRCS_NAME = main.c

OBJS = $(addprefix $(OBJDIR),$(SRCS_NAME:.c=.o))
LIBFT = $(addprefix $(LIBFTDIR)/,$(LIBFTA))

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

SRCS = $(addprefix $(SRCDIR),$(SRCS_NAME))

all: $(NAME)

obj:
		mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
		gcc $(FLAGS) -I $(INCDIR) -I $(LIBFTDIR) -o $@ -c $<

$(NAME): obj $(OBJS)
		gcc $(OBJS) $(LIBFT) -lm -o $(NAME)
			@echo "$(GREEN)---------corewar compiled---------$(NC)"

norme:
		norminette includes srcs

clean:
		rm -rf $(OBJDIR)

fclean:	clean
		rm -f $(NAME)
		echo "$(GREEN)----corewar removed completely----$(NC)"

re: fclean all