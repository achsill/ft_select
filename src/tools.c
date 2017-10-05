/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 10:25:41 by hlouar            #+#    #+#             */
/*   Updated: 2016/06/10 11:25:06 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	ft_strlenmax(t_env *e)
{
	int		i;
	int		o;
	t_liste	*tmp;

	o = 0;
	i = 0;
	tmp = e->liste;
	while (tmp->next != e->liste)
	{
		tmp = tmp->next;
		i = ft_strlen(tmp->str);
		if (o < i)
			o = i;
	}
	e->strl = o;
}

int		windowtoosmall(t_env *e)
{
	int a;
	int b;

	a = ((e->bmax) / (e->strl + 1));
	b = (a * (e->amax - 1));
	if (b >= (e->i))
		return (1);
	return (0);
}

void	writeend(t_env *e)
{
	t_liste	*tmp;

	tmp = e->liste;
	tputs(tgetstr("te", NULL), 1, ft_putcharremix);
	tputs(tgetstr("ve", NULL), 1, ft_putcharremix);
	while (tmp->next != e->liste)
	{
		tmp = tmp->next;
		if (tmp->tc == 1)
		{
			ft_putstr(tmp->str);
			ft_putstr(" ");
		}
	}
	exit(0);
}

void	helpdelete(t_env *e, t_liste *tmp)
{
	free(tmp->str);
	free(tmp);
	printlist(e);
}

void	deletestring(t_env *e)
{
	t_liste	*tmp;

	tmp = e->liste;
	while (tmp->next != e->liste)
	{
		tmp = tmp->next;
		if (tmp->ts == 1)
		{
			tputs(tgetstr("cl", NULL), 1, ft_putcharremix);
			if (tmp->next == e->liste)
				tmp->next->next->ts = 1;
			else
				tmp->next->ts = 1;
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			helpdelete(e, tmp);
			if (countmaille(e) == 0)
			{
				tputs(tgetstr("te", NULL), 1, ft_putcharremix);
				tputs(tgetstr("ve", NULL), 1, ft_putcharremix);
				exit(0);
			}
			return ;
		}
	}
}
