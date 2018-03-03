/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_and.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:23:05 by msakwins          #+#    #+#             */
/*   Updated: 2018/03/03 22:00:33 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		func_and(t_env *env, t_process *current, t_ocp ocp)
{
	int				size1;
	int				size2;
	unsigned int	value1;
	unsigned int	value2;

	size1 = get_size_param(ocp.one, 4);
	size2 = get_size_param(ocp.two, 4);
	value1 = get_data_all_types(env, current, M(current->pc + 2), ocp.one);
	value2 = get_data_all_types(env, current,
		M(current->pc + 2 + size1), ocp.two);
	if (!verify_reg(env->arena[M(2 + size1 + size2)], 0, 0))
		return (2 + size1 + size2 + 1);
	current->reg[env->arena[M(current->pc + 2 + size1 + size2)] - 1] =
		value1 & value2;
	current->carry =
		current->reg[env->arena[M(2 + size1 + size2)] - 1] ? 0 : 1;
	return (2 + size1 + size2 + 1);
}
