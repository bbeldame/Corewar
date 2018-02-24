/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:07:14 by msakwins          #+#    #+#             */
/*   Updated: 2018/02/18 16:54:20 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		reset_lives(t_env *env)
{
	int		i;

	i = 0;
	while (i <= env->nb_players)
	{
		env->player[i].live = 0;
		i++;
	}
}

int		new_cycle(t_env *env)
{
		reset_lives(env);
		env->nb_lives = 0

}

int		check_living(t_env *env)
{
	int		i;

	i = 0;
	while (i <= env->nb_players)
	{
		if (env->player[i].live = 0)
			dead = 1;
		live = 0
		i++;
	}
}

int		check_cycles(t_env *env)
{
	if (env->cycle == env->cycle_to_die)
	{
		verifie que chaque joueur a appele live au moins une fois
		if (env->nb_lives < NBR_LIVE)
		{
			env->nb_checks += 1;
		}
		if (env->nb_checks == MAX_CHECKS || env->nb_lives >= NBR_LIVE)
		{
			env->cycle_to_die -= CYCLE_DELTA;
			env->nb_checks = 0;
			new_cycle(env);
		
		}
	}
}