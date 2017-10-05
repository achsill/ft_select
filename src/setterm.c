/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setterm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 09:26:37 by hlouar            #+#    #+#             */
/*   Updated: 2016/06/10 11:20:28 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int	ft_putcharremix(int i)
{
	return (write(1, &i, 1));
}

int	ft_setterm(t_env *e)
{
	if ((e->name_term = getenv("TERM")) == NULL)
	{
		ft_putendl("ENV NULL");
		exit(0);
	}
	if (tgetent(NULL, e->name_term) < 1)
		return (-1);
	if (tcgetattr(0, &(e->term)) == -1)
		return (-1);
	e->term.c_lflag &= ~(ICANON | ECHO);
	e->term.c_cc[VMIN] = 1;
	e->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &(e->term)) == -1)
		return (-1);
	tputs(tgetstr("ti", NULL), 1, ft_putcharremix);
	tputs(tgetstr("vi", NULL), 1, ft_putcharremix);
	return (1);
}
