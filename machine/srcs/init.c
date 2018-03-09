/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:07:14 by msakwins          #+#    #+#             */
/*   Updated: 2018/03/02 00:56:58 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		init(t_env *env)
{
	env->visu = 0;
	env->nb_players = 0;
	env->dump = -1;
	env->cycle_to_die = CYCLE_TO_DIE;
	env->winner = 0;
}
