# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/15 15:57:23 by bbeldame          #+#    #+#              #
#    Updated: 2018/02/18 16:05:47 by bbeldame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	makeall

LIBFT_PATH	= ./libft
VM_PATH	= ./VM
ASM_PATH	= ./asm

all:	$(NAME)

$(NAME):
	@make -C $(LIBFT_PATH)
	@make -C $(ASM_PATH)
	@make -C $(VM_PATH)

clean:
	@make -C $(LIBFT_PATH) clean
	@make -C $(ASM_PATH) clean
	@make -C $(VM_PATH) clean

fclean:	clean
	@make -C $(LIBFT_PATH) fclean
	@make -C $(ASM_PATH) fclean
	@make -C $(VM_PATH) fclean

re:		fclean all

.PHONY:		all clean fclean re
