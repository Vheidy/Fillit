/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_body.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:55:11 by vheidy            #+#    #+#             */
/*   Updated: 2019/10/15 21:55:42 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**ft_clean(char **line, int point[4])
{
	int i;

	i = -1;
	while (++i < 4)
		(*line)[point[i]] = '.';
	return (line);
}

static int		ft_check_ind(int point[4], char *line)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (line[point[i]] != '.')
			return (0);
	}
	return (1);
}

static void		ft_newstart(int start[4], int point[4], int mv_volue)
{
	int i;

	i = -1;
	if (mv_volue > 0)
	{
		while (++i < 4)
			point[i] = point[i] + mv_volue;
		i = -1;
	}
	if (mv_volue >= 0)
		while (++i < 4)
			start[i] = point[i];
}

static t_lst	**ft_change(t_lst **list, int size_sq, char *line)
{
	int		start_posit[4];
	int		a;

	ft_newstart(start_posit, (*list)->point, 0);
	while (1)
	{
		a = -1;
		if ((size_sq - ((*list)->point[0] % size_sq) - (*list)->vis_wid))
			while (++a < 4)
				(*list)->point[a] += 1;
		else if ((size_sq - (start_posit[0] / size_sq) - (*list)->leng))
			ft_newstart(start_posit, (*list)->point, (*list)->wid);
		else
		{
			ft_newstart((*list)->point, (*list)->start, 0);
			return (NULL);
		}
		if (ft_check_ind((*list)->point, line))
			break ;
	}
	return (list);
}

int				ft_body(t_lst **begin_list, char **line, int b)
{
	t_lst	*list;
	int		a;

	list = *begin_list;
	if (!(ft_check_ind(list->point, *line)))
		if (!(ft_change(&list, b, *line)))
			return (0);
	if (list)
	{
		a = -1;
		while (++a < 4)
			(*line)[list->point[a]] = list->alpha;
		if (list->next)
			if (!(ft_body(&(list->next), line, b)))
				if ((ft_clean(line, list->point) && !ft_change(&list, b, *line))
				|| !ft_body(&list, line, b))
					return (0);
	}
	return (1);
}
