/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:23:05 by msakwins          #+#    #+#             */
/*   Updated: 2018/03/02 01:35:09 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*int		func_st(t_env *env, t_process *current, t_ocp ocp)
{
	int				size;
	unsigned int	value;
	int				reg_idx;
	unsigned int	second;
	int				i;

	size = get_size_param(ocp.two, 4);
	reg_idx = env->arena[M(current->pc + 2)];
	if (ocp.one != REG_CODE || ocp.two == REG_CODE ||
		reg_idx > REG_NUMBER || ocp.two == 0)
		return (2 + size + 1);
	value = current->reg[reg_idx - 1];
	current->carry = value == 0 ? 1 : 0;
	if (ocp.two == REG_CODE)
	{
		second = env->arena[M(current->pc + 3)];
		if (second > REG_NUMBER)
			return (2 + size + 1);
		current->reg[second - 1] = value;
	}
	// HERE I HAVE TO INSERT THE DATA IN THE INDIRECT PLACEMENT
	else
	{
		i = 0;
		second = get_data_ind(e, current->pc + 1, 1);
		while (i < REG_SIZE) {
			// Hardest part uugh
		}
	}
	return (2 + size + 1);
}*/

int func_st() {
	return (1);
}