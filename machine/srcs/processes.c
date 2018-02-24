/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 21:04:55 by bbeldame          #+#    #+#             */
/*   Updated: 2018/02/24 21:22:18 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_process		*create_new_process(t_env *env, int i)
{
	t_process	*process;

	if (!(process = (t_process *)malloc(sizeof(t_process))))
		ft_exit(1, "Malloc for process error");
	process->id_champion = i;
	process->reg[0] = env->player[i].nb;
	process->carry = 0;
	process->opcode = 0;
	process->pc = 0;
	process->prev = NULL;
	process->next = NULL;
	return (process);
}
