/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:03:54 by arosset           #+#    #+#             */
/*   Updated: 2018/03/08 16:03:57 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int		get_ocp_return(t_inst *ins, int oc)
{
	if (ins->nb_instr == 0)
		return (oc << 6);
	else if (ins->nb_instr == 1)
		return (oc << 4);
	else
		return (oc << 2);
}

int 	get_labdir_pos(t_asm *param, t_inst *ins, t_label *tmp, int oc)
{
	t_list		*new;
	t_labdir	*content;

	if ((new = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (0);
	if ((content = (t_labdir*)malloc(sizeof(t_labdir))) == NULL)
		return (0);
	content->label = tmp->label;
	content->instr_addr = ins->ins_octet;
	content->addr = ins->octet + 1;
	new->content = content;
	new->next = NULL;
	ins->param[ins->nb_instr] = 0;
	ft_lstaddtail(&param->labdirs, new);
	if (oc == 0b10)
	{
		if (g_op_tab[ins->i_instr].label_size)
			ins->octet += 2;
		else
			ins->octet += 4;
	}
	else
		ins->octet += 2;
	return (get_ocp_return(ins, oc));
}

int 	ft_get_label(t_asm *param, t_inst *ins, int oc, int i)
{
	t_list 	*elem;
	t_label *tmp;
	int 	idx;

	elem = param->labels;
	while (elem)
	{
		tmp = elem->content;
		idx = ft_strlen(ins->ins + i + 1) > ft_strlen(tmp->label) - 1 ?
			ft_strlen(ins->ins + i + 1) : ft_strlen(tmp->label) - 1;
		if (!ft_strncmp(ins->ins + i + 1, tmp->label, idx))
			return (get_labdir_pos(param, ins, tmp, oc));
		elem = elem->next;
	}
	return (0);
}

int 	get_reg(t_inst *ins)
{
	if (ins->ins[0] == 'r')
	{
		ins->param[ins->nb_instr] = ft_atoi_oflow(ins->ins + 1);
		ins->octet++;
		return (get_ocp_return(ins, 0b01));
	}
	return (0);
}

int 	get_ind(t_asm *param, t_inst *ins, int oc)
{
	int 	idx;
	int 	i;

	i = (oc == 0b10 ? 0 : -1);
	if (ins->ins[++i] == LABEL_CHAR)
		return (ft_get_label(param, ins, oc, i));
	idx = i;
	if (ins->ins[idx] == '-')
		idx++;
	while (ins->ins[idx])
		if (ft_isdigit(ins->ins[idx++]))
			return (0);
	ins->param[ins->nb_instr] = ft_atoi_oflow(ins->ins + i);
	if (oc == 0b10)
	{
		if (!g_op_tab[ins->i_instr].label_size)
			ins->octet += 4;
		else
			ins->octet += 2;
	}
	else
		ins->octet += 2;
	return (get_ocp_return(ins, oc));
}
