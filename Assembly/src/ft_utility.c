/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 14:19:02 by arosset           #+#    #+#             */
/*   Updated: 2018/01/27 14:19:04 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void 	ft_print_usage()
{
	ft_printf("Usage: ./asm <source_file.s>\n");
}

int 	ft_open_file(char *s)
{
	int 	fd;

	fd = open(s, O_RDONLY);
	if (fd == -1)
		exit_msg_error(11, 0, NULL);
	return (fd);
}

char 	*ft_skip_space(char *s)
{
	int 	i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	return (&s[i]);
}

int 	verif_line(char *line)
{
	char *tmp;

	tmp = ft_skip_space(line);
	if (tmp[0] == '#' || tmp[0] == '\0')
		return (0);
	return (1);
}
