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

char 	*ft_clear_str(char *s)
{
	int 	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\t')
			s[i] = ' ';
		i++;
	}
	return (s);
}

void 	set_file_list(t_asm *param, int fd)
{
	char 		*line;
	int 		num_l;
	t_file_list *header_list;
	t_file_list *body_list;

	line = NULL;
	num_l = 1;
	header_list = NULL;
	body_list = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (verif_line(line))
		{
			line = ft_clear_str(line);
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
	set_file_list(param, fd);
	set_name_comment(param);
	free_file_list(&param->header);
	//ft_print_asm(param);
	//ft_printf("parse header OK\n");
	if (!ft_parse_body(param))
		ft_printf("parse KO\n");
	ft_printf("parse body OK\n");
}
