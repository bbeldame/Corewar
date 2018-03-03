/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_live.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:23:05 by msakwins          #+#    #+#             */
/*   Updated: 2018/03/03 23:00:50 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			func_live(t_env *env, t_process *current)
{
	unsigned int id;

	id = get_data_dir(env, M(current->pc + 1), g_op[1].label_size);
	printf("le id est %d\n", id);
	env->player[0].live = 1;
	current->live = 1;
	env->nb_lives += 1;
	current->wait = g_op[1].cycles;
	ft_printf("wait = %d\n", current->wait);
	return (1 + 4);
}