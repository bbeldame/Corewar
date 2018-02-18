/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:07:14 by msakwins          #+#    #+#             */
/*   Updated: 2018/02/18 20:18:51 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		ft_exit(int i, char *str)
{
	ft_putstr_fd("Error: ", 2);
	if (i == 1)
		ft_putstr_fd("(Syntax) ", 2);
	if (i == 2)
		ft_putstr_fd("Do you even read the rules? ", 2);
	ft_putendl_fd(str, 2);
	exit(1);
}