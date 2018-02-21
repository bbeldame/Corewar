/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:07:14 by msakwins          #+#    #+#             */
/*   Updated: 2018/02/18 20:19:18 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			next_number(t_env *env)
{
	int		next;

	next = env->player[env->nb_players - 1].nb + 1;
	return (next);
}

void		add_player(t_env *env, char *nb, int argc, int *i)
{
	int		current;
	int		max;

	current = 1;
	if (ft_strequ(nb, "*"))
		current = (env->nb_players == 0) ? 1 : next_number(env);
	else
	{
		if ((*i + 3 > argc))
			ft_exit(1, "Wrong value");
		check_number(nb);
		if ((max = ft_atoll(nb)) > 2147483644)
			ft_exit(1, "Player number is too big");
		if (max < 1)
			ft_exit(2, "Player number is not accepted");
		current = max;
		*i += 2;
	}
	check_dup_number(env, current);
	env->player[env->nb_players].nb = current;
	env->player[env->nb_players].file_pos = *i;
}

void		parse_args(t_env *env, int argc, char **argv)
{
	int		i;
	int		dump_value;

	i = 1;
	env->nb_players = 0;
	if (ft_strequ(argv[i], "-dump"))
	{
		if (i + 3 > argc)
			ft_exit(2, "No players found");
		check_number(argv[i + 1]);
		dump_value = atoll(argv[i + 1]);
	}
	while (i < argc)
	{
		if (ft_strequ(argv[i], "-n"))
			add_player(env, argv[i + 1], argc, &i);
		else
			add_player(env, "*", argc, &i);
		env->nb_players += 1;
		if (env->nb_players > MAX_PLAYERS)
			ft_exit(2, "Maximum number of players is 4.");
		i++;
	}
}
