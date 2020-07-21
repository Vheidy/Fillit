/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:50:34 by vheidy            #+#    #+#             */
/*   Updated: 2019/10/15 21:50:43 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_del_list(t_lst **head)
{
	t_lst *tmp;

	while (*head)
	{
		tmp = (*head)->next;
		ft_memdel((void **)(head));
		*head = tmp;
	}
}

static void		ft_link(t_lst **head, t_lst *elem)
{
	elem->next = *head;
	*head = elem;
}

static t_lst	*ft_new_elem(t_tetr *tetr, int len, char alpha)
{
	t_lst	*list;
	int		a;

	if (!(list = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	list->next = NULL;
	a = -1;
	while (a++ < 3)
	{
		list->point[a] = tetr->coord[a].y * len + tetr->coord[a].x;
		list->start[a] = list->point[a];
	}
	list->leng = tetr->leng;
	list->wid = tetr->wid;
	list->vis_wid = tetr->wid - tetr->coord[0].x;
	list->alpha = alpha;
	return (list);
}

t_lst			*ft_new_list(t_tetr *tetr, int len, int count)
{
	t_lst	*list;
	t_lst	*head_lst;
	char	alpha;

	alpha = 'A' + count;
	list = NULL;
	head_lst = list;
	while (tetr)
	{
		list = ft_new_elem(tetr, len, --alpha);
		ft_link(&head_lst, list);
		tetr = tetr->next;
		list = list->next;
	}
	return (head_lst);
}
