/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_players.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 21:08:32 by bbeldame          #+#    #+#             */
/*   Updated: 2018/02/21 20:18:33 by bbeldame         ###   ########.fr       */
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
** Name starts after the 4 bytes
** while the comment start after NAME + 12 bytes
*/

static void		parse_name(int p_index, t_env *e)
{
	int		i;

	i = 0;
	while (i < PROG_NAME_LENGTH)
	{
		if (!(ft_strchr(GOOD_CHARACTERS, e->player[p_index].string[i + OFFSET_NAME])))
			ft_exit(e, "Bad characters in name");
		e->player[p_index].name = e->player[p_index].string[i + OFFSET_NAME];
		i++;
	}
	e->player[p_index].name[i] = '\0';
}

static void		parse_comment(int p_index, t_env *e)
{
	int		i;

	i = 0;
	while (i < COMMENT_LENGTH)
	{
		if (!(ft_strchr(GOOD_CHARACTERS, e->player[p_index].string[i + OFFSET_COMMENT])))
			ft_exit(e, "Bad characters in comment");
		e->player[p_index].comment = e->player[p_index].string[i + OFFSET_COMMENT];
		i++;
	}
	e->player[p_index].name[i] = '\0';
}

void			parse_players(t_env *e)
{
	int		i;

	i = 0;
	while (i < nb_players)
	{
		verify_magic(e, i);
		parse_name(i, e);
		parse_comment(i, e);
		i++;
	}
}