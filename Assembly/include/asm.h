/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:00:46 by arosset           #+#    #+#             */
/*   Updated: 2018/02/18 16:48:33 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../../libft/includes/libft.h"
# include "../../libft/includes/ft_printf.h"
# include "op.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct			s_label
{
	char				*label;
	int					addr;
}						t_label;


typedef struct 			s_file_list
{
	char 				*line;
	int 				num_l;
	struct s_file_list	*next;
}						t_file_list;

typedef struct 			s_token
{
	char 				*label;
	int 				num_l;
	char 				*command;
	char 				instruction[3];
	struct s_token		*next;
}						t_token;

typedef struct			s_asm
{
	char				*name_prg;
	char 				*comment_prg;
	char 				*file_cor;
	char 				*file_s;
	int 				fd;
	t_file_list			*header;
	t_file_list 		*body;
	t_token 			*token;
	t_list 				*labels;
}						t_asm;

/*
** 		Fonction erreur
*/

void 	ft_error(char *s);
void 	exit_msg_error(int c_er, int n_line, t_asm *param);

/*
**		Finalisation asm
*/

void 	finalize_asm(t_asm *param);
void 	print_header(t_asm *param);
void 	print_magic(int fd);
void 	print_body(t_asm *param);

/*
**		Parser
*/

void 	ft_parser(t_asm *param);
int 	ft_parse_body(t_asm *param);
int 	set_name_comment(t_asm *param);
int 	check_body(t_asm *param);
int 	parse_params(char *line, t_asm *param, int idx);

/*
**		Check des commandes du fichier .s
*/

int 	is_reg(char *param);
int 	is_label(char *param);
int 	is_dir(t_list *labels, char *param);
int 	is_ind(t_list *labels,  char *param);

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

void		ft_lstaddtail(t_list **alst, t_list *new);

/*
** 		Utilitaire
*/

void 	print_header(t_asm *param);
int		is_white_space(char c);
int 	verif_end_line_param(char *str, int i);

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
void 	print_tab(char **tab);
void 	print_label(t_asm *param);

#endif
