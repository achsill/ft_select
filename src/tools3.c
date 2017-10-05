/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 23:15:14 by hlouar            #+#    #+#             */
/*   Updated: 2016/06/24 23:15:28 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	selectithelp(t_liste *tmp, t_env *e)
{
	if (tmp->tc == 1)
	{
		tmp->tc = 0;
		tmp->ts = 0;
		if (tmp->next == e->liste)
			tmp = tmp->next;
		tmp->next->ts = 1;
	}
	else if (tmp->tc == 0)
	{
		tmp->tc = 1;
		tmp->ts = 0;
		if (tmp->next == e->liste)
			tmp = tmp->next;
		tmp->next->ts = 1;
	}
}

void	init(t_env *e, int ac, char **av)
{
	fill_liste(e->liste, ac, av);
	fillint(e->liste);
	ft_strlenmax(e);
	stock(e, 0);
	getinf(e);
	ft_setterm(e);
}
