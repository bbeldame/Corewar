/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_players.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 21:08:32 by bbeldame          #+#    #+#             */
/*   Updated: 2018/02/18 21:21:36 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void		verify_magic(t_env *e, int i)
{

}

/*
** Parse comment or name in the player's .cor
** We specify an OFFSET because the name 
*/

static void		parse_name_or_comment(t_env *e)
{

}

void			parse_players(t_env *e)
{
	int		i;

	i = 0;
	while (i < nb_players)
	{
		verify_magic(e, i);
		parse_name(e, i);
		parse_comment(e, i);
		i++;
	}
}