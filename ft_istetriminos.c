/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istetriminos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:08:45 by vheidy            #+#    #+#             */
/*   Updated: 2019/10/15 19:09:51 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(int i)
{
	if (i == 1)
		write(1, "error\n", 6);
	else
		write(1, "usege: ./fillite input_file\n", 28);
	exit(1);
}

int		ft_istetriminos(char **a)
{
	int count;
	int i;
	int dot;

	i = 0;
	dot = 0;
	count = 0;
	while ((*a)[i])
	{
		if ((*a)[i] == '.')
			dot++;
		if (i < 12 && (*a)[i] == '#' && (*a)[i + 4] == '#')
			count++;
		if (i != 15 && (i + 1) % 4 != 0 && (*a)[i] == '#' && (*a)[i + 1] == '#')
			count++;
		i++;
	}
	if ((count == 3 || count == 4) && dot == 12)
		return (1);
	return (0);
}
