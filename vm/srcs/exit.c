/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:07:14 by msakwins          #+#    #+#             */
/*   Updated: 2018/02/18 16:54:20 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		ft_exit(int i, int j)
{
	ft_putstr("Error: ");
	if (i == 1)
	{
		ft_putstr("(Syntax)");
		str_error_flags(j);
	}
	if (i == 2)
	{
		ft_putstr("Do you even read the rules? ");
		str_error_flags(j);
	}
		exit(1);
}

void		str_error_flags(int j)
{
	if (j == 1)
		ft_putendl("Wrong number of players");
}