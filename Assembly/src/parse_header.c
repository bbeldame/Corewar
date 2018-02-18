/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 13:58:23 by arosset           #+#    #+#             */
/*   Updated: 2018/02/18 16:47:12 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int 	add_name_comment(char *line, char verif, t_asm *param)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (line[i] && line[i] != '\"')
		i++;
	if (line[i] != '\"')
		return (0);
	i++;
	while (line[i + j] && line[i + j] != '\"')
		j++;
	if (line[i + j] != '\"')
		return (0);
	if (verif == 0)
		param->name_prg = ft_strsub(line, i, j);
	if (verif == 1)
		param->comment_prg = ft_strsub(line, i, j);
	return (1);
}

int		verif_name_comment(char *line, int verif)
{
	if (ft_strncmp(line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == 0)
	{
		if (verif == 0)
			return (1);
		else
			return (0);
	}
	else if (ft_strncmp(line, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)) == 0)
	{
		if (verif == 1)
			return (1);
		else
			return (0);
	}
	return (0);
}

void 	verif_len_header(t_asm *param)
{
	if (ft_strlen(param->name_prg) > PROG_NAME_LENGTH)
		exit_msg_error(30, 0, param);
	if (ft_strlen(param->comment_prg) > COMMENT_LENGTH)
		exit_msg_error(31, 0, param);
}

void 	verif_exist_header(t_asm *param)
{
	if (!param->name_prg || ft_strlen(param->name_prg) < 1)
		exit_msg_error(13, 0, param);
	if (!param->comment_prg || ft_strlen(param->comment_prg) < 1)
		exit_msg_error(14, 0, param);
}

int 	set_name_comment(t_asm *param)
{
	int 		verif;
	t_file_list	*file;
	char 		**tab;

	file = param->header;
	verif = 0;
	while (file)
	{
		tab = ft_strsplit(file->line, ' ');
		if (verif_name_comment(tab[0], verif))
			add_name_comment(file->line, verif, param);
		verif++;
		free_tab(tab);
		if (file->next)
			file = file->next;
		else
			break;
	}
	verif_exist_header(param);
	verif_len_header(param);
	return (1);
}
