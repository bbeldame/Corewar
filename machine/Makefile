# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/18 16:15:40 by bbeldame          #+#    #+#              #
#    Updated: 2018/02/22 21:42:40 by bbeldame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../corewar

FLAGS = -Wall -Wextra # -Werror to uncomment at the end

LIBFTA = libft.a

LIBFTDIR = ../libft
OBJDIR = ./obj/
INCDIR = ./includes
SRCDIR = ./srcs/
FCDIR = ./funcs/

SRCS_NAME =	main.c \
			arena.c \
			init.c \
			parse_args.c \
			exit.c \
			check.c \
			parse_files.c

FUNC_NAME = func_add.c \
			func_aff.c \
			func_and.c \
			func_fork.c \
			func_ld.c \
			func_ldi.c \
			func_lfork.c \
			func_live.c \
			func_lld.c \
			func_lldi.c \
			func_or.c \
			func_st.c \
			func_sti.c \
			func_sub.c \
			func_xor.c \
			func_zjmp.c


OBJS = $(addprefix $(OBJDIR),$(SRCS_NAME:.c=.o))
LIBFT = $(addprefix $(LIBFTDIR)/,$(LIBFTA))

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

SRCS = $(addprefix $(SRCDIR),$(SRCS_NAME))

all: $(NAME)

obj:
		@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
		@gcc $(FLAGS) -I $(INCDIR) -I $(LIBFTDIR) -o $@ -c $<

$(NAME): obj $(OBJS)
		@gcc $(OBJS) $(LIBFT) -lm -o $(NAME)
			@echo "$(GREEN)---------corewar compiled---------$(NC)"

norme:
		@norminette includes srcs

clean:
		@rm -rf $(OBJDIR)

fclean:	clean
		@rm -f $(NAME)
		@echo "$(GREEN)----corewar removed completely----$(NC)"

re: fclean all