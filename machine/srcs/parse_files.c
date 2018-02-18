/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 20:25:46 by bbeldame          #+#    #+#             */
/*   Updated: 2018/02/18 20:59:00 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
** Compute len of the .cor file, it makes the read easier
*/

static int		get_string_len(t_env *e, int i, char **argv)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;
	int		fd;

	e->player[i].len = 0;
	if ((fd = open(argv[e->player[i].file_pos], O_RDONLY)) == -1)
		ft_exit(1, "Open error");
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (ret != 0)
			e->player[i].len += ret;
	}
	if (e->player[i].len > TOTAL_SIZE)
		ft_exit(1, "File too large");
	if (close(fd) == -1)
		ft_exit(1, "Close error");
	if (ret == -1)
		ft_exit(1, "Read error");
	return (e->player[i].len);
}

/*
** Read files and put buffer into player->string
*/

void		parse_files(t_env *e, char **argv)
{
	int i;
	int fd;
	int len;

	i = 0;
	while (i < e->nb_players)
	{
		if (ft_strlen(argv[e->player[i].file_pos]) <= 4 ||
				ft_strcmp(argv[e->player[i].file_pos] +
					ft_strlen(argv[e->player[i].file_pos]) - 4, ".cor"))
			ft_exit(2, "Not a .cor file");
		len = get_string_len(e, i, argv);
		if ((fd = open(argv[e->player[i].file_pos], O_RDONLY)) == -1)
			ft_exit(1, "Open error");
		if (read(fd, e->player[i].string, e->player[i].len) == -1)
			ft_exit(1, "Read error");
		e->player[i].string[len] = '\0';
		e->player[i].live = 0;
		if (close(fd) == -1)
			ft_exit(1, "Close error");
		i++;
	}
}
