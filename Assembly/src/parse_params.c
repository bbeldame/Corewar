/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 18:17:18 by arosset           #+#    #+#             */
/*   Updated: 2018/02/24 18:17:20 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int 	get_param_end(char *line)
{
	int i;

	i = 0;
	while (line[i] != SEPARATOR_CHAR && !is_white_space(line[i])
			&& line[i] && line[i] != COMMENT_CHAR)
		i++;
	return (i);
}

int 	validate_param(t_list *labels, char *ins, int p_type)
{
	int	flag;

	flag = 0;
	if (p_type & T_REG)
		if(is_reg(ins))
			flag = 1;
	if (p_type & T_DIR)
		if (is_dir(labels, ins))
			flag = 1;
	if (p_type & T_IND)
		if (is_ind(labels, ins))
			flag = 1;
	if (!flag)
		return (0);
	return (1);
}

int 	verif_end_line_param(char *str, int i)
{
	while (is_white_space(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int 	parse_params(char *line, t_asm *param, int idx)
{
	int 	nb_instr;
	int 	i;
	char 	*inst;

	i = 0;
	nb_instr = 0;
	while (nb_instr < g_op_tab[idx].nb_param)
	{
		while (is_white_space(line[i]) || line[i] == SEPARATOR_CHAR)
			i++;
		if ((inst = ft_strsub(line, i, get_param_end(line + i))) == NULL)
			return (0);
		if (!validate_param(param->labels, inst, g_op_tab[idx].param[nb_instr]))
		{
			ft_strdel(&inst);
			return (0);
		}
		i += ft_strlen(inst);
		ft_strdel(&inst);
		nb_instr++;
	}
	if (!verif_end_line_param(line, i))
		return (0);
	return (1);
}
