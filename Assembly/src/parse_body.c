/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_body.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:45:09 by arosset           #+#    #+#             */
/*   Updated: 2018/03/04 15:59:41 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

/*
**		Initialise un nouveau maillon pour t_list labels
*/

t_list	*init_label(char *label)
{
	t_list	*new;

	if (label == NULL)
		return (NULL);
	if ((new = (t_list*)malloc(sizeof(t_list))) == NULL)
		exit_msg_error(10, 0, NULL);
	new->content = label;
	new->next = NULL;
	return (new);
}

/*
**		Initialise avec init_label et ajoute avec ft_lstaddtail
** 		un nouveau maillon a t_list labels
**		renvoi 1 en cas de reussite
** 		sinon renvoi 0
*/

int		save_label(t_asm *param, char *label)
{
	t_list	*new;

	if ((new = init_label(label)) == NULL)
		return (0);
	ft_lstaddtail(&param->labels, new);
	return (1);
}

/*
**		parcours la t_file_list body, isole et enregistre chaque label
** 		dans une t_list label
**		renvoi 1 en cas de reussite
** 		sinon renvoi 0
*/

int		get_label(t_asm *param)
{
	t_file_list	*files;
	int			i;

	i = 0;
	files = param->body;
	while (files)
	{
		if ((i = is_label(files->line)))
		{
			if (!save_label(param, ft_strsub(files->line, 0, i - 1)))
				return (0);
		}
		files = files->next;
	}
	return (1);
}

/*
**		parse le corps du programme en asm
** 		cree en premiers lieu une t_list des labels avec get_label
** 		et verifie la validite des instructions avec check_body
** 		renvoi 1 en cas de reussite
*/

int		ft_parse_body(t_asm *param)
{
	int	ret;

	ret = 0;
	//ft_printf("create list label\n");
	if (!get_label(param))
		return (0);
	//ft_printf("parse body\n");
	if (!check_body(param))
		return (0);
	return (1);
}
