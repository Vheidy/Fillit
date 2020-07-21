/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bust.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:57:46 by vheidy            #+#    #+#             */
/*   Updated: 2019/10/15 21:57:47 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_del_tetr(t_tetr **head)
{
	t_tetr *tmp;

	while (*head)
	{
		tmp = (*head)->next;
		ft_memdel((void **)head);
		*head = tmp;
	}
}

static char	*ft_strdot(size_t size)
{
	char	*str;

	if (!(str = ft_strnew(size)))
		return (NULL);
	str = ft_memset(str, '.', size);
	return (str);
}

void		ft_check_max(int *c, t_tetr *head)
{
	t_tetr *tmp;

	tmp = head;
	while (tmp)
	{
		if (*c < tmp->wid)
			*c = tmp->wid;
		if (*c < tmp->leng)
			*c = tmp->leng;
		tmp = tmp->next;
	}
}

static int	ft_sqrt(int a, t_tetr *tetr_head)
{
	int c;

	c = 1;
	while (c * c <= a)
	{
		if (c * c == a)
			break ;
		c++;
	}
	ft_check_max(&c, tetr_head);
	return (c);
}

int			ft_bust(t_tetr **tetr_head, int count, char **line)
{
	t_lst	*head_list;
	int		a;

	a = ft_sqrt(count * 4, *tetr_head);
	*line = ft_strdot(a * a);
	head_list = ft_new_list(*tetr_head, a, count);
	while (!(ft_body(&head_list, line, a)))
	{
		a++;
		free(*line);
		*line = ft_strdot(a * a);
		ft_del_list(&head_list);
		head_list = ft_new_list(*tetr_head, a, count);
	}
	ft_del_tetr(tetr_head);
	ft_del_list(&head_list);
	return (a);
}
