/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:20:54 by msakwins          #+#    #+#             */
/*   Updated: 2018/02/18 20:18:51 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		check_number(char *nb)
{
	char	*numbers;
	int		i;

	numbers = "0123456789";
	i = -1;
	while (nb[++i])
		if (!(ft_strchr(numbers, nb[i])))
			ft_exit(1, "Wrong value");
}

void		check_dup_number(t_env *env, int nb)
{
	int		i;

	i = 0;
	while (i <= env->nb_players)
	{
		if (nb == env->player[i].nb)
			ft_exit(2, "Players can't have the same number");
		i++;
	}
}
