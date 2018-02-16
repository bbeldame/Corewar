/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:16:24 by arosset           #+#    #+#             */
/*   Updated: 2018/01/26 15:16:25 by arosset          ###   ########.fr       */
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
		ft_free_tab(tab);
		if (file->next)
			file = file->next;
		else
			break;
	}
	if (!param->name_prg || !param->comment_prg)
		exit_msg_error(20, file->num_l, param);
	return (1);
}

void 	set_file_list(t_asm *param, int fd, int num_l)
{
	char 		*line;
	t_file_list *header_list;
	t_file_list *body_list;

	line = NULL;
	header_list = NULL;
	body_list = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (verif_line(line))
		{
			if (size_list(&header_list) < 2)
				ft_add_end_file_list(&header_list, line, num_l);
			else
				ft_add_end_file_list(&body_list, line, num_l);
		}

		num_l++;
		ft_strdel(&line);
	}
	param->header = header_list;
	param->body = body_list;
}

void 	ft_parser(t_asm *param)
{
	int 	fd;

	fd = ft_open_file(param->file_s);
	set_file_list(param, fd, 1);
	set_name_comment(param);
	free_file_list(&param->header);

	// ft_print_asm(param);
	ft_printf("parse header OK\n");
	//ft_parse_body(param);
	//ft_print_asm(param);
	//ft_printf("parse body OK\n");
}
