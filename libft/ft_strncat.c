/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:30:17 by rtacos            #+#    #+#             */
/*   Updated: 2019/09/13 12:37:11 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *s;

	s = s1;
	while (*s)
		s++;
	while (n-- && *s2)
		*s++ = *s2++;
	*s = '\0';
	return (s1);
}
