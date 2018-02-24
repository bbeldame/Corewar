/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:20:49 by arosset           #+#    #+#             */
/*   Updated: 2018/02/24 15:20:51 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int 	ft_str_is_int(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 && str[i] > 57 )
			return (0);
		i++;
	}
	return (1);
}

int 	is_reg(char *param)
{
	if (param[0] == 'r')
	{
		if (ft_str_is_int(param + 1))
		{
			if (ft_atoi(param + 1) > 0 && ft_atoi(param + 1) < 100)
				return (1);
		}
	}
	return (0);
}

int 	is_label(char *param)
{
	int 	i;

	i = 0;
	while (ft_strchr(LABEL_CHARS, param[i]))
		i++;
	if (param[i] == LABEL_CHAR)
		return (i + 1);
	return (0);
}
