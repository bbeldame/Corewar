/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_live.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:23:05 by msakwins          #+#    #+#             */
/*   Updated: 2018/03/11 23:23:52 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			func_live(t_env *env, t_process *current)
{
	unsigned int	id;
	int				i;

	i = 0;
	id = get_data_dir(env, M((current->pc + 1)), 4);
	current->live++;
	env->nb_lives += 1;
	if (env->verbose)
		ft_printf("Live called from %d\n", current->id_champion);
	while (i < env->nb_players)
	{
		if (env->player[i].nb == (int)id)
		{
			env->player[i].live++;
			env->winner = i;
			if (!env->visu)
			{
				ft_printf("Un processus dit que le joueur %d(%s)",
					env->player[i].nb, env->player[i].header->prog_name);
				ft_printf(" est en vie\n");
			}
		}
		i++;
	}
	return (1 + 4);
}
