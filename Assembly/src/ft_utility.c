/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 14:19:02 by arosset           #+#    #+#             */
/*   Updated: 2018/03/04 15:57:44 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void	ft_print_usage(void)
{
	ft_printf("Usage: ./asm <source_file.s>\n");
}

/*
**		ouvre le fichier passe en parametre
** 		quitte le programme avec exit_msg_error si fd == -1
*/

int		ft_open_file(char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd == -1)
		exit_msg_error(11, 0, NULL);
	return (fd);
}

/*
**		renvoi l'adresse du premiers caractere qui n'est pas un espace
**		de la chaine passe en parametre
*/

char	*ft_skip_space(char *s)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	return (&s[i]);
}

/*
**		renvoi 1 si la chaine passe en parametre ne commence pas par "#"
**		sinon renvoi 0
*/

int		verif_line(char *line)
{
	char	*tmp;

	tmp = ft_skip_space(line);
	if (tmp[0] == '#' || tmp[0] == '\0')
		return (0);
	return (1);
}

/*
**		renvoi 1 si le caractere est un "espace blanc"
** 		sinon renvoi 0
*/

int		is_white_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' ||
			c == '\r')
		return (1);
	else
		return (0);
}
