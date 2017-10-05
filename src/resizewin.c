/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resizewin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 09:41:38 by hlouar            #+#    #+#             */
/*   Updated: 2016/06/10 11:19:25 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	getinf(t_env *e)
{
	struct winsize	win;
	short			a;
	short			b;

	ioctl(0, TIOCGWINSZ, &win);
	a = win.ws_row;
	b = win.ws_col;
	e->amax = a;
	e->bmax = b;
}
