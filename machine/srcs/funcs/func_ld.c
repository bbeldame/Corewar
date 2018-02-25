/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_ld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:23:05 by msakwins          #+#    #+#             */
/*   Updated: 2018/02/26 00:15:30 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		func_ld(t_env *env, t_process *current, t_ocp ocp)
{
	/*int				size;
	unsigned int	value;
	int				reg_idx;

	size = get_size_param(ocp->one, 4);

	if (ocp->one == DIR_CODE)
		value = get_data_dir(env, M(current->pc + 2), 4);
	else if (ocp->first == IND_CODE)
		p[0] = cw_get_data_ind(proc, tmp, (tmp->pc + 2) % MEM_SIZE);

	reg_idx = env->arena[M(current->pc + 2 + size)];

	if (ocp->first == REG_CODE || p[1] < 1 || p[1] > REG_NUMBER ||
		ocp->second != REG_CODE || ocp->first == 0)
		return (2 + p_sze[0] + p_sze[1]);

	tmp->reg[p[1] - 1][0] = p[0] >> 24;
	tmp->reg[p[1] - 1][1] = p[0] >> 16;
	tmp->reg[p[1] - 1][2] = p[0] >> 8;
	tmp->reg[p[1] - 1][3] = p[0];

	current->carry = p[0] == 0 ? 1 : 0;

	return (2 + size + 1);
	*/
	return (0);
}