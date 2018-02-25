/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_opcode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 19:32:29 by bbeldame          #+#    #+#             */
/*   Updated: 2018/02/25 19:58:24 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		get_opcode(t_env *env, t_process *current)
{
	if (env->arena[current->pc] >= 1 && env->arena[current->pc] <= 16)
	{
		current->opcode = env->arena[current->pc];
		current->wait = g_op[env->arena[current->pc]].cycles;
	}
	else
	{
		current->opcode = 0;
		current->wait = 0;
	}
}

void		load_all_opcode(t_env *env)
{
	t_process		*tmp;

	tmp = env->head;
	while (tmp)
	{
		if (tmp->opcode == 0)
			get_opcode(env, tmp);
		tmp = tmp->next;
	}
}
