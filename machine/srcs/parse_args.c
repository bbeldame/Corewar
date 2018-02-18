/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:07:14 by msakwins          #+#    #+#             */
/*   Updated: 2018/02/18 16:54:20 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		parse_args(t_env *env, int argc, char **argv)
{
	int		i;

	i = 1;
	env->nb_players = 0;
	if (ft_strequ(argv[i], "-dump"))
	{
		env->dump = atoll(argv[i + 1]);
	}
	while (i < argc)
	{
		if (ft_strequ(argv[i], "-n"))
			env->nb_players += 1;
		else
			env->nb_players += 1;
		if (env->nb_players > MAX_PLAYERS)
		{
			ft_printf("nb = %d\n", env->nb_players);
			ft_exit(1, 1);
		}
		i++;
	}
}