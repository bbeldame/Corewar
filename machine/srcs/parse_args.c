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

void		add_player(t_env *env, char *nb, int argc, int *i)
{
	int		current;

	if (ft_strequ(nb, "0"))
	{
		if (env->nb_players == 0)
			current = 1;

	}
	else
		if ((*i + 3 > argc))
			ft_exit(1, "Wrong value");
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
			add_player(env, "0", argc, &i);
		env->nb_players += 1;
		if (env->nb_players > MAX_PLAYERS)
		{
			ft_exit(2, "Maximum number of players is 4.");
		}
		i++;
	}
}
