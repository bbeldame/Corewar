/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:07:14 by msakwins          #+#    #+#             */
/*   Updated: 2018/02/24 22:09:05 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static t_process	*create_new_process(t_env *env, int i)
{
	t_process	*process;

	if (!(process = (t_process *)malloc(sizeof(t_process))))
		ft_exit(1, "Malloc for process error");
	process->id_champion = i;
	init_reg(process);
	process->reg[0] = env->player[i].nb;
	process->carry = 0;
	process->opcode = 0;
	process->pc = 0;
	process->prev = NULL;
	process->next = NULL;
	return (process);
}

void				init_arena_and_processes(t_env *env)
{
	int			i;
	t_process	*tmp;

	ft_bzero(env->arena, sizeof(unsigned char) * MEM_SIZE);
	i = env->nb_players - 1;
	while (i >= 0)
	{
		if (i == env->nb_players - 1)
		{
			env->head = create_new_process(env, i);
			tmp = env->head;
		}
		else
		{
			tmp->next = create_new_process(env, i);
			tmp->next->prev = tmp;
			tmp = tmp->next;
		}
		ft_memcpy(&(env->arena[i * MEM_SIZE / env->nb_players]),
			env->player[i].code, env->player[i].header->prog_size);
		ft_strdel(&(env->player[i].code));
		i--;
	}
	env->head->prev = tmp;
	tmp->next = env->head;
	printf("ca va etre moche : %X\n", env->arena);
	func_aff();
}
