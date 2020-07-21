/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:01:50 by vheidy            #+#    #+#             */
/*   Updated: 2019/10/15 19:05:56 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft/libft.h"

# define BUFF_SIZE 21

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_tetr
{
	t_coord			coord[4];
	int				leng;
	int				wid;
	struct s_tetr	*next;
}					t_tetr;

typedef struct		s_lst
{
	int				point[4];
	int				start[4];
	int				leng;
	int				wid;
	int				vis_wid;
	char			alpha;
	struct s_lst	*next;
}					t_lst;

void				ft_del_list(t_lst **head);
void				error(int i);
int					ft_istetriminos(char **a);
t_tetr				*ft_coordinate(char **line);
int					ft_bust(t_tetr **tetr_head, int count, char **line);
t_lst				*ft_new_list(t_tetr *tetr, int len, int count);
int					ft_body(t_lst **begin_list, char **line, int b);

#endif
