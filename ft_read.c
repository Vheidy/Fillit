/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:19:05 by vheidy            #+#    #+#             */
/*   Updated: 2019/10/15 19:19:14 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_connect_tetr(t_tetr **tetr_head, t_tetr *elem)
{
	elem->next = *tetr_head;
	*tetr_head = elem;
}

static int		ft_count_change(char **line, int rd)
{
	int		i;
	char	*tmp;
	int		in;

	i = 0;
	in = 21;
	tmp = *line;
	if ((rd == 21 && tmp[--in] == '\n') || rd == 20)
		while (in-- >= 0)
			if (tmp[in] == '\n' && ((in + 1) % 5) == 0)
			{
				tmp[in] = '\0';
				i++;
			}
	if (i == 4 && (rd == 20 || rd == 21))
		return (1);
	return (0);
}

static t_tetr	*ft_creat_elem(char *tmp, int rd)
{
	int		in;
	char	*line;

	line = ft_strnew(16);
	if ((ft_count_change(&tmp, rd)))
	{
		in = 0;
		while (in <= 15)
		{
			line = ft_strcat(line, tmp + in);
			in += 5;
		}
		if (ft_istetriminos(&line))
			return (ft_coordinate(&line));
	}
	error(1);
	return (NULL);
}

static int		ft_read_fill(const int fd, t_tetr **tetr_head)
{
	int		rd_prov;
	char	buff[BUFF_SIZE + 1];
	int		rd;
	t_tetr	*elem;
	int		count;

	count = 0;
	while ((rd = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rd] = '\0';
		rd_prov = rd;
		if ((elem = ft_creat_elem(buff, rd)))
		{
			ft_connect_tetr(tetr_head, elem);
			count++;
		}
		else
			error(1);
	}
	if (rd_prov != 20 || count > 26)
		error(1);
	return (count);
}

int				main(int ac, char **av)
{
	int		fd;
	t_tetr	*tetr_head;
	int		count;
	char	*line;
	int		i;

	tetr_head = NULL;
	if (ac != 2)
		error(0);
	if (!(fd = open(av[1], O_RDONLY)))
		error(1);
	count = ft_read_fill(fd, &tetr_head);
	count = ft_bust(&tetr_head, count, &line);
	i = -1;
	while (line[++i])
	{
		if (i != 0 && !(i % count))
			ft_putchar('\n');
		ft_putchar(line[i]);
	}
	ft_putchar('\n');
	close(fd);
	ft_strdel(&line);
	return (0);
}
