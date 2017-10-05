/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 11:21:25 by hlouar            #+#    #+#             */
/*   Updated: 2016/06/10 14:18:56 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	stopsig(void)
{
	t_env	*e;
	char	fortl[2];

	e = NULL;
	e = stock(e, 1);
	fortl[0] = e->term.c_cc[VSUSP];
	fortl[1] = 0;
	e->term.c_lflag |= (ICANON | ECHO);
	signal(SIGTSTP, SIG_DFL);
	tputs(tgetstr("cl", NULL), 1, ft_putcharremix);
	tcsetattr(0, 0, &(e->term));
	tputs(tgetstr("te", NULL), 1, ft_putcharremix);
	tputs(tgetstr("ve", NULL), 1, ft_putcharremix);
	ioctl(0, TIOCSTI, fortl);
}

void	continuesig(void)
{
	t_env *e;

	e = NULL;
	e = stock(e, 1);
	e->term.c_lflag &= ~(ICANON | ECHO);
	e->term.c_cc[VMIN] = 1;
	e->term.c_cc[VTIME] = 0;
	tcsetattr(0, 0, &(e->term));
	tputs(tgetstr("ti", NULL), 1, ft_putcharremix);
	tputs(tgetstr("vi", NULL), 1, ft_putcharremix);
	signal(SIGTSTP, switchsig);
	tputs(tgetstr("cl", NULL), 1, ft_putcharremix);
	printlist(e);
}

void	stopsigz(void)
{
	t_env *e;

	e = NULL;
	e = stock(e, 1);
	e->term.c_lflag |= (ICANON | ECHO);
	tputs(tgetstr("te", NULL), 1, ft_putcharremix);
	tputs(tgetstr("ve", NULL), 1, ft_putcharremix);
	exit(0);
}

void	switchsig(int a)
{
	if (a == SIGWINCH)
		ressize();
	else if (a == SIGTSTP)
		stopsig();
	else if (a == SIGCONT)
		continuesig();
	else if (a == SIGINT || a == SIGQUIT)
		stopsigz();
}

void	abc(void)
{
	int i;

	i = 1;
	while (i < 32)
	{
		signal(i, switchsig);
		i++;
	}
}
