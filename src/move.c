/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 12:43:57 by hlouar            #+#    #+#             */
/*   Updated: 2016/06/10 11:17:51 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

t_env	*stock(t_env *e, int i)
{
	static t_env *tmp = NULL;

	if (i == 0)
		tmp = e;
	return (tmp);
}

void	moveflecheb(t_env *e)
{
	t_liste	*tmp;

	tmp = e->liste;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->ts == 1)
		{
			tmp->ts = 0;
			if (tmp->next == e->liste)
				tmp->next->next->ts = 1;
			else
				tmp->next->ts = 1;
			return ;
		}
	}
}

void	selectit(t_env *e)
{
	t_liste	*tmp;

	tmp = e->liste;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->ts == 1)
		{
			selectithelp(tmp, e);
			return ;
		}
	}
}

void	moveflecheh(t_env *e)
{
	t_liste *tmp;

	tmp = e->liste;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->ts == 1)
		{
			tmp->ts = 0;
			if (tmp->prev == e->liste)
				tmp->prev->prev->ts = 1;
			else
				tmp->prev->ts = 1;
			return ;
		}
	}
}

void	ressize(void)
{
	t_env *e;

	e = NULL;
	e = stock(e, 1);
	getinf(e);
	tputs(tgetstr("cl", NULL), 1, ft_putcharremix);
	if (windowtoosmall(e) == 1)
	{
		printlist(e);
	}
	else
	{
		ft_putendl_fd("window is too small", 2);
	}
}
