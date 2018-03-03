/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:23:05 by msakwins          #+#    #+#             */
/*   Updated: 2018/02/22 20:18:51 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		func_zjmp(t_env *e, t_process *current)
{
	int	index;
	
	if (current->carry)
	{
		index = get_data_dir(e, current->pc + 1, 2);
		index = (index % IDX_MOD);
		return(index);
	}
	return(1 + 2);
}