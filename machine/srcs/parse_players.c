/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_players.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 21:08:32 by bbeldame          #+#    #+#             */
/*   Updated: 2018/02/18 21:50:17 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
** Verify the first 4 bytes of the .cor file, it must correspond to
** the COREWAR_EXEC_MAGIC constant
*/

static void		verify_magic(t_env *e, int i)
{
	/*
		char	*str;
		int		number;

		str = e->player[i].string;
		number = ((MM(str[0]) << 24) | (MM(str[1]) << 16) | (MM(str[2]) << 8) |
		MM(str[3]));
		if (number != COREWAR_EXEC_MAGIC)
			ft_exit(e, 4);
	*/
}

/*
** Parse comment or name in the player's .cor
** We specify an OFFSET because the name start after the 4 bytes
** while the comment start after NAME + 12 bytes
*/

static void		parse_name_or_comment(char *cor, int offset,
	char **dest, int max_size)
{
	int		i;

	i = 0;
	while (i < max_size)
	{
		if (!(ft_strchr(GOOD_CHARACTER, cor[i + offset])))
			ft_exit(e, "Bad characters in comment or name");
		*dest[i] = cor[i + offset];
		i++;
	}
	*dest[max_size] = '\0';
}

void			parse_players(t_env *e)
{
	int		i;

	i = 0;
	while (i < nb_players)
	{
		verify_magic(e, i);
		parse_name_or_comment(e, i, OFFSET_NAME, &(e->players[i].name),
			PROG_NAME_LENGTH);
		parse_name_or_comment(e, i, OFFSET_COMMENT, &(e->players[i].comment),
			COMMENT_LENGTH);
		i++;
	}
}