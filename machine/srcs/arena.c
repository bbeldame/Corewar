/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:07:14 by msakwins          #+#    #+#             */
/*   Updated: 2018/02/18 16:54:20 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		init_arena(t_env *env)
{
	int			i;
	static int	j;

	i = 0;
	j = 0;
	env->arena = ft_strnew(MEM_SIZE);
	while (i < env->nb_players)
	{
		env->player[i].start_pos = (MEM_SIZE / env->nb_players) * i;
		env->player[i].live = 0;
		j = (MEM_SIZE / env->nb_players) * i;
		i++;
	}
}