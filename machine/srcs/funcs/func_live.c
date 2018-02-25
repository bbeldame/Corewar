/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_live.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:23:05 by msakwins          #+#    #+#             */
/*   Updated: 2018/02/25 21:35:43 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			func_live(t_env *env, t_process *curr)
{
	unsigned int id;

	id = get_data_dir(env, M(curr->pc + 1), g_op[1].label_size);
	printf("le id est %d\n", id);
	env->player[0].live = 1;
	curr->live = 1;
	env->nb_lives += 1;
	curr->wait = g_op[1].cycles;
	ft_printf("wait = %d\n", curr->wait);
	return (1);
}