/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 18:43:15 by bbeldame          #+#    #+#             */
/*   Updated: 2018/03/03 20:15:53 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void increment_pc(t_env *env, t_process *current, int size)
{
	current->pc = M(current->pc + size);
	get_opcode(env, current);

	int i = 0;
	while (i < 20)
		printf("%d, ", current->reg[i++]);
	printf("\n");
}

static void	exec_instruction(t_env *env, t_process *current)
{
	int		size;
	t_ocp	ocp;

	ocp = get_ocp(env, current);
	size = g_op[current->opcode].func(env, current, ocp);
	increment_pc(env, current, size);
}

static void exec_cycle(t_env *env)
{
	t_process *tmp;

	tmp = env->head;
	while (tmp)
	{
		if (tmp->opcode)
		{
			if (tmp->wait == 0)
				exec_instruction(env, tmp);
			else
				tmp->wait--;
		}
		tmp = tmp->next;
	}
}

void		launch_lifecycle(t_env *env)
{
	int		check;
	int		cycle_to_die;

	check = 1;
	env->cycle_to_die = CYCLE_TO_DIE;
	env->cycle = 1;
	env->nb_lives = 0;
	env->nb_checks = 0;
	load_all_opcode(env);
	cycle_to_die = env->cycle_to_die;
	/*while (check)
	{
		exec_cycle(env);
		// check = check_cycles(env, &cycle_to_die);
		cycle_to_die--;
		env->cycle++;
		check = 0; // testing
	}*/

	int i = 0;
	while (i < 300)
	{
		env->visu = 1;
		env->nb_lives++;
		if (env->visu)
			visu(env);
		if (i == env->dump) {
			print_dump(env);
		}
		exec_cycle(env);
		i++;
	}

}