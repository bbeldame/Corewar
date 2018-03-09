/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:07:14 by msakwins          #+#    #+#             */
/*   Updated: 2018/03/09 22:26:52 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static t_process	*kill_process(t_env *env, t_process *killed)
{
	t_process	*tmp;

	tmp = killed->next;
	if (killed->next)
		killed->next->prev = killed->prev;
	if (killed->prev)
		killed->prev->next = killed->next;
	if (killed == env->head)
		env->head = tmp;
	free(killed);
	killed = NULL;
	env->nb_processes--;
	return (tmp);
}

static void			check_livings(t_env *env)
{
	t_process	*tmp;
	int			i;

	tmp = env->head;
	i = 0;
	while (i < env->nb_processes)
	{
		if (tmp->live == 0)
			tmp = kill_process(env, tmp);
		else
		{
			tmp->live = 0;
			tmp = tmp->next;
		}
		i++;
	}
}

int					check_cycles(t_env *env, int *cycle_to_die)
{
	if (*cycle_to_die == 0)
	{
		env->nb_checks++;
		if (env->nb_lives >= NBR_LIVE)
			env->cycle_to_die -= CYCLE_DELTA;
		if (env->nb_checks == MAX_CHECKS)
		{
			env->cycle_to_die -= CYCLE_DELTA;
			env->nb_checks = 0;
		}
		check_livings(env);
		env->nb_lives = 0;
		*cycle_to_die = env->cycle_to_die;
	}
	if (!env->nb_processes || env->cycle_to_die <= 0)
		return (0);
	return (1);
}
