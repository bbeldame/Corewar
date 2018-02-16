/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:00:46 by arosset           #+#    #+#             */
/*   Updated: 2018/01/30 14:59:52 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/includes/libft.h"
# include "op.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>


typedef struct 			s_file_list
{
	char 				*line;
	int 				num_l;
	struct s_file_list	*next;
}						t_file_list;

typedef struct			s_asm
{
	char				*name_prg;
	char 				*comment_prg;
	char 				*file_cor;
	char 				*file_s;
	t_file_list			*header;
	t_file_list 		*body;
}						t_asm;

typedef struct 			s_token
{
	char 				*label;
	int 				num_l;
	char 				*instruction;
	struct s_token		*next;
}						t_token;

/*
** 		Fonction erreur
*/

void 	ft_error(char *s);
void 	exit_msg_error(int c_er, int n_line, t_asm *param);

/*
**		Parser
*/

void 	ft_parser(t_asm *param);
void 	ft_parse_body(t_asm *param);

/*
** 		verif extension and name
*/

int 	ft_check_ext(char *str);
char	*set_name_cor(char *name);

/*
** 		struct and list
*/

t_asm 	*init_t_asm(char *name);
void  	ft_add_end_file_list(t_file_list **list, char *line, int num_l);
int 	size_list(t_file_list **list);

/*
** 		Utilitaire
*/

void 	ft_print_usage(void);
int 	ft_open_file(char *s);
char 	*ft_skip_space(char *s);
int 	verif_line(char *line);

/*
** 		Free
*/

void 	free_file_list(t_file_list **list);

/*
** 		Debug
*/

void 	ft_print_asm(t_asm *param);
void 	ft_print_file_list(t_file_list *list);

#endif
