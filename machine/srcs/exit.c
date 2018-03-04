/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:07:14 by msakwins          #+#    #+#             */
/*   Updated: 2018/03/04 23:53:29 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		ft_exit(int i, char *str)
{
	if (i == 4)
	{
		ft_putstr_fd("Rules: \n", 2);
		ft_putstr_fd("1: usage: ./corewar [-dump nb] [[-n nb] champ1.cor]\n",
			2);
		ft_putstr_fd("2: option '-dump nb' dump the memory on the standard", 2);
		ft_putstr_fd("output after nb cycles and exit the corewar\n", 2);
		ft_putstr_fd("3: option '-n nb' set a number for the next player\n", 2);
		ft_putstr_fd("4: you can add 1 to 4 champions in the arena\n", 2);
		exit(1);
	}
	ft_putstr_fd("Error: ", 2);
	if (i == 1)
		ft_putstr_fd("(Syntax) ", 2);
	if (i == 2)
		ft_putstr_fd("Do you even read the rules? ", 2);
	ft_putendl_fd(str, 2);
	exit(1);
}
