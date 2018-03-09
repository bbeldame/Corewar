/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_fork_lfork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 23:06:18 by bbeldame          #+#    #+#             */
/*   Updated: 2018/03/09 22:57:38 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void			clone_reg(t_process *a, t_process *b)
{
	int i;

	i = 0;
	while (i < REG_NUMBER)
	{
		b->reg[i] = a->reg[i];
		i++;
	}
}

static t_process	*clone_process(t_process *current)
{
	t_process *process;

	if (!(process = (t_process *)malloc(sizeof(t_process))))
		ft_exit(1, "Malloc for process error");
	clone_reg(current, process);
	process->idx_buffer = 0;
	process->id_champion = current->id_champion;
	process->live = 0;
	process->opcode = current->opcode;
	process->carry = current->carry;
	process->wait = current->wait;
	return (process);
}

static int			both_forks(t_env *env, t_process *current, int restr)
{
	short int	value;
	t_process	*forked;

	value = (short int)get_data_dir(env, M(current->pc + 2), 2);
	forked = clone_process(current);
	env->nb_processes++;
	if (restr)
		forked->pc = M(current->pc + value % IDX_MOD);
	else
		forked->pc = M(current->pc + value);
	env->head->prev = forked;
	forked->next = env->head;
	env->head = forked;
	return (3);
}

int					func_lfork(t_env *env, t_process *current)
{
	return (both_forks(env, current, 0));
}

int					func_fork(t_env *env, t_process *current)
{
	return (both_forks(env, current, 1));
}
