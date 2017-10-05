/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listefunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 10:59:45 by hlouar            #+#    #+#             */
/*   Updated: 2016/06/10 11:12:55 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

t_liste		*ft_createlist(void)
{
	t_liste *liste;

	liste = malloc(sizeof(t_liste));
	if (liste != NULL)
	{
		liste->prev = liste;
		liste->next = liste;
	}
	return (liste);
}

void		addelem(t_liste *liste, char *str)
{
	t_liste *new_elem;

	new_elem = malloc(sizeof(t_liste));
	if (new_elem != NULL)
	{
		new_elem->str = ft_strdup(str);
		new_elem->prev = liste->prev;
		new_elem->next = liste;
		liste->prev->next = new_elem;
		liste->prev = new_elem;
	}
}
