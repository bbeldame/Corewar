/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_body.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 17:37:13 by arosset           #+#    #+#             */
/*   Updated: 2018/02/24 17:37:14 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

/*
**		retourne la taille de l'instruction donne
*/

int 	get_size_inst(char *line)
{
	int i;

	i = 0;
	while (!is_white_space(line[i]) && line[i] != DIRECT_CHAR && line[i])
		i++;
	return (i);
}

/*
**		Identifie l'instruction de la ligne avec idx (max 15) et
**		envoi ses parametres pour verification a parse_params
** 		renvoi 0 pour idx == 16 ou si parse_params == 0
*/

int 	check_inst(char *line, t_asm *param)
{
	int 	idx;
	int 	i;
	int 	size;

	idx = 0;
	i = 0;
	while (g_op_tab[idx].name)
	{
		size = get_size_inst(line);
		if (!(ft_strncmp(line, g_op_tab[idx].name, size)))
		{
			i += ft_strlen(g_op_tab[idx].name);
			break ;
		}
		idx++;
	}
	if (idx == 16)
		return (0);
	if (!parse_params(line + i, param, idx))
		return (0);
	return (1);
}

/*
**		separe les labels des instructions
**		envoi les instructions a check_inst
** 		coupe l'execution du programme si check_inst renvoi 0
*/

int 	check_body(t_asm *param)
{
	t_file_list *files;
	int 		i;

	files = param->body;
	while (files)
	{
		i = is_label(files->line);
		while (is_white_space(files->line[i]))
			i++;
		if (files->line[i] != '\0')
		{
			if (!check_inst(files->line + i, param))
				exit_msg_error(22, files->num_l, param);
		}
		files = files->next;
	}
	return (1);
}
