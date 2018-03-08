/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_body.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:34:02 by arosset           #+#    #+#             */
/*   Updated: 2018/02/28 17:34:07 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int 	jump_nextline(char *str, int i)
{
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

int 	get_param(t_asm *param, t_inst *ins)
{
	int flag;
	int	p_type;

	flag = 0;
	p_type = g_op_tab[ins->i_instr].param[ins->nb_instr];
	if (p_type & T_REG)
		ins->ocp |= get_reg(ins);
	if (p_type & T_DIR)
	{
		flag = ins->ocp;
		if (*(ins->ins) == DIRECT_CHAR)
			ins->ocp |= get_ind(param, ins, 0b10);
		flag = flag != ins->ocp ? 1 : 0;
	}
	if (!flag && p_type & T_IND)
		ins->ocp |= get_ind(param, ins, 0b11);
	return (param->idx + ft_strlen(ins->ins));
}

void 	print_param(t_asm *param, t_inst *ins)
{
	int i;

	i = -1;
	if (g_op_tab[ins->i_instr].ocp)
		ft_putchar_fd(ins->ocp, param->fd);
	while (++i < ins->nb_instr)
	{
		if (((unsigned)ins->ocp >> (6 - i * 2) & 0b11) == 0b01)
			ft_putchar_fd(ins->param[i], param->fd);
		else if (((unsigned)ins->ocp >> (6 - i * 2) & 0b11) == 0b11 || g_op_tab[ins->i_instr].label_size)
		{
			ft_putchar_fd((unsigned)ins->param[i] >> 8, param->fd);
			ft_putchar_fd(ins->param[i], param->fd);
		}
		else
		{
			ft_putchar_fd((unsigned)ins->param[i] >> 24, param->fd);
			ft_putchar_fd(ins->param[i] >> 16, param->fd);
			ft_putchar_fd(ins->param[i] >> 8, param->fd);
			ft_putchar_fd(ins->param[i], param->fd);
		}
	}
}

int 	print_params(t_asm *param, t_inst *ins, int i)
{
	char *f_content;

	if (g_op_tab[ins->i_instr].ocp)
		ins->octet++;
	ins->nb_instr = -1;
	ins->ocp = 0;
	f_content = param->f_content;
	while (++ins->nb_instr < g_op_tab[ins->i_instr].nb_param)
	{
		while (is_white_space(f_content[i]) || f_content[i] == SEPARATOR_CHAR)
			param->idx++;
		if ((ins->ins = ft_strsub(f_content, i, get_param_end(f_content + i) - i)) == NULL)
			return (0);
		i = get_param(param, ins);
		free(ins->ins);
	}
	param->idx = i;
	print_param(param, ins);
	return (i);
}

int 	get_instr(t_asm *param, int i, t_inst *ins)
{
	char	*f_content;
	int 	idx;
	int 	label_size;

	idx = 0;
	f_content = param->f_content;
	if (!f_content[i])
		return (i);
	while (g_op_tab[idx].name)
	{
		label_size = get_size_inst(f_content + i);
		if (!(ft_strncmp(f_content + i, g_op_tab[idx].name, label_size)))
		{
			i += ft_strlen(g_op_tab[idx].name);
			break ;
		}
		idx++;
	}
	ins->octet += 1;
	ft_putchar_fd(idx + 1, param->fd);
	ins->ins_octet = ins->octet;
	ins->i_instr = idx;
	if (!(i = print_params(param, ins, i)))
		return (0);
	return (i);
}

int 	get_label_pos(t_asm *param, t_inst *ins, int i)
{
	t_list	*tmp;
	t_label	*content;
	int 	x;

	tmp = param->labels;
	while (is_white_space(param->f_content[i]))
		i++;
	while (tmp)
	{
		content = tmp->content;
		x = ft_strlen(content->label);
		if (ft_strncmp(content->label, param->f_content + i, x))
		{
			if (param->f_content[i + x + 1] != LABEL_CHAR)
				return (i);
			content->addr = ins->octet + 1;
			return (get_label_pos(param, ins, x + i));
		}
		tmp = tmp->next;
	}
	return (i);
}

void 	print_body(t_asm *param, char *f_content, int i)
{
	t_inst 		ins;

	ins.octet = 0;
	ft_printf("print body\n");
	while (f_content[i])
	{
		if ((f_content[i] == COMMENT_CHAR) && (i = jump_nextline(f_content, i)))
			continue;
		if (!is_white_space(f_content[i]))
		{
			i = get_label_pos(param, &ins, i);
			while (is_white_space(f_content[i]))
				i++;
			while (f_content[i] == COMMENT_CHAR)
				i = jump_nextline(f_content, i);
			while (is_white_space(f_content[i]))
				i++;
			if (!(i = get_instr(param, i, &ins)))
				return ;
		}
		else
			i++;
	}
	param->prog_size = ins.octet;
}
