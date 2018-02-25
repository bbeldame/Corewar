/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 21:19:30 by bbeldame          #+#    #+#             */
/*   Updated: 2018/02/25 23:21:00 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_ocp		get_ocp(t_env *env, t_process *current)
{
	unsigned char	byte_ocp;
	t_ocp			ocp;
	
	ocp.three = 0;
	ocp.two = 0;
	ocp.one = 0;
	byte_ocp = 0;
	if (env->arena[current->pc] != LIVE && env->arena[current->pc] != ZJMP &&
		env->arena[current->pc] != FORK && env->arena[current->pc] != LFORK)
	{
		byte_ocp = env->arena[current->pc + 1];
		ocp.three = byte_ocp >> 6;
		ocp.two = (byte_ocp >> 4) & 0x03;
		ocp.one = (byte_ocp >> 2) & 0x03;
	}
	return ocp;
}

void		init_reg(t_process *process)
{
	int i;

	i = 0;
	while (i < 16)
		process->reg[i++] = 0;
}
