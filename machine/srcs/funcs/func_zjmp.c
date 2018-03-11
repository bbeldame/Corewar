/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:23:05 by msakwins          #+#    #+#             */
/*   Updated: 2018/03/12 00:50:58 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		func_zjmp(t_env *e, t_process *current)
{
	short int	index;

	if (current->carry)
	{
		index = (short int)get_data_dir(e, M((current->pc + 1)), 2);
		index = (index % IDX_MOD);
		if (e->verbose)
			ft_printf("Zjmp called from %d : jumping of %d steps\n",
				current->id_champion, index);
		return (index);
	}
	else 
	{
		if (e->verbose)
			ft_printf("Zjmp called from %d : carry 0 so no jump\n",
				current->id_champion);
	}
	return (1 + 2);
}
