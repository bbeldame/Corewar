/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_live.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:23:05 by msakwins          #+#    #+#             */
/*   Updated: 2018/03/05 00:30:11 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			func_live(t_env *env, t_process *current)
{
	unsigned int	id;
	int				i;

	id = get_data_dir(env, M(current->pc + 1), 4);
	env->player[0].live = 1;
	current->live++;
	env->nb_lives += 1;
	i = 0;
	while (i < env->nb_players)
	{
		if (env->player[i].nb == (int)id)
		{
			env->player[i].live++;
			env->winner = i;
			ft_printf("Un processus dit que le joueur %d(%s) est en vie\n",
				env->player[i].nb, env->player[i].header->prog_name);
		}
		i++;
	}
	return (1 + 4);
}
