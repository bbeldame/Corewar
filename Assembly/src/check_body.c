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

int 	get_size_inst(char *line)
{
	int i;

	i = 0;
	while (!is_white_space(line[i]) && line[i] != DIRECT_CHAR && line[i])
		i++;
	return (i);
}

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
