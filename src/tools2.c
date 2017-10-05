/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 10:23:48 by hlouar            #+#    #+#             */
/*   Updated: 2016/06/10 14:21:02 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int		countmaille(t_env *e)
{
	int		i;
	t_liste	*tmp;

	i = 0;
	tmp = e->liste;
	while (tmp->next != e->liste)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	fillint(t_liste *liste)
{
	t_liste	*tmp;
	int		i;

	i = 0;
	tmp = liste;
	while (tmp->next != liste)
	{
		tmp = tmp->next;
		if (i == 0)
			tmp->ts = 1;
		else
			tmp->ts = 0;
		tmp->tc = 0;
		i++;
	}
}
