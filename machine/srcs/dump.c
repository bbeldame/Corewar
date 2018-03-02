/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:07:14 by bbeldame          #+#    #+#             */
/*   Updated: 2018/03/02 01:00:50 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		print_dump(t_env *e)
{
	int		i;
	int		hex;

	hex = 0;
	i = 0;
	while (i < MEM_SIZE)
	{
		if ((i) % (32) == 0)
			ft_printf("0x%04x : ", hex);
		ft_printf("%02x ", LBYTE(e->arena[i]));
		if ((i + 1) % (32) == 0)
		{
			ft_printf("\n");
			hex += 32;
		}
		i++;
	}
	exit(1);
}
