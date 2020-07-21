/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coordinate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:51:57 by vheidy            #+#    #+#             */
/*   Updated: 2019/10/15 21:51:58 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tetr		*ft_new_tetr(void)
{
	t_tetr	*tetr;

	if (!(tetr = (t_tetr *)malloc(sizeof(t_tetr))))
		return (NULL);
	tetr->next = NULL;
	return (tetr);
}

static void			ft_leng_width(int *leng, int *wid, t_coord coord[4])
{
	int	i;

	*leng = 0;
	*wid = 0;
	i = -1;
	while (++i < 4)
	{
		if (*leng <= coord[i].y)
			*leng = coord[i].y + 1;
		if (*wid <= coord[i].x)
			*wid = coord[i].x + 1;
	}
}

static t_tetr		*ft_check_cord(t_tetr **tetr)
{
	int		lol;
	int		b;
	int		i;

	i = 0;
	while (++i < 4)
		if ((*tetr)->coord[i].x < 0)
		{
			b = -1;
			lol = (*tetr)->coord[i].x;
			while (++b < 4)
				(*tetr)->coord[b].x = (*tetr)->coord[b].x - lol;
		}
	ft_leng_width(&((*tetr)->leng), &((*tetr)->wid), ((*tetr)->coord));
	return (*tetr);
}

t_tetr				*ft_coordinate(char **line)
{
	t_tetr	*tetr;
	int		i;
	int		a;

	a = 0;
	i = -1;
	tetr = ft_new_tetr();
	while ((*line)[++i])
		if ((*line)[i] == '#')
		{
			tetr->coord[a].x = i % 4;
			tetr->coord[a].y = i / 4;
			a++;
		}
	ft_strdel(line);
	while (a-- >= 0)
	{
		tetr->coord[a].x = tetr->coord[a].x - tetr->coord[0].x;
		tetr->coord[a].y = tetr->coord[a].y - tetr->coord[0].y;
	}
	return (ft_check_cord(&tetr));
}
