/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_name_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 15:31:13 by arosset           #+#    #+#             */
/*   Updated: 2018/02/11 15:31:14 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

/*
**		remplace .s par .cor
*/

char	*set_name_cor(char *name)
{
	char *file_cor;

	file_cor = ft_strnew(ft_strlen(name) - 2);
	file_cor = ft_strncpy(file_cor, name, (ft_strlen(name) - 2));
	file_cor = ft_strjoin(file_cor, ".cor");
	return (file_cor);
}

/*
**		verif extension du fichier demande
*/

int 	ft_check_ext(char *str)
{
	if ((str[ft_strlen(str) - 1] == 's') && (str[ft_strlen(str) - 2] == '.'))
		return (1);
	else
		exit_msg_error(12, 0, NULL);
	return (0);
}
