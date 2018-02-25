/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 20:55:34 by bbeldame          #+#    #+#             */
/*   Updated: 2018/02/26 00:15:48 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		get_reg(t_env *env, t_process *current, int i)
{
	int reg_i;

	reg_i = LBYTE(env->arena[M(current->pc + i)]);
	if (reg_i > 0 && reg_i <= REG_NUMBER)
		return (current->reg[reg_i - 1]);
	return (0);
}

unsigned int	get_data_dir(t_env *e, int idx, int label_size)
{
	unsigned int res;

	if (label_size == 1)
	{
		res = (LBYTE(e->arena[M(idx)] << 8 | LBYTE(M(idx + 1))));
	}
	else
	{
		res = (LBYTE(e->arena[M(idx)]) << 24) |
		(LBYTE(e->arena[M(idx + 1)]) << 16) |
			(LBYTE(e->arena[M(idx + 2)]) << 8) |
				LBYTE(e->arena[M(idx + 3)]);
	}
	return (res);
}

/*unsigned int	get_data_ind(t_env *e, int idx)
{
	unsigned int res;
	short		ind;

	ind = (short)(proc->mem[sze % MEM_SIZE] << 8 |
	proc->mem[(sze + 1) % MEM_SIZE])
	% IDX_MOD;
	ret = (proc->mem[(champ->pc + ind) % MEM_SIZE] << 24
	| proc->mem[(champ->pc + ind + 1) % MEM_SIZE] << 16
	| proc->mem[(champ->pc + ind + 2) % MEM_SIZE] << 8
	| proc->mem[(champ->pc + ind + 3) % MEM_SIZE]);
	return (ret);
}*/