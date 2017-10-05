/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 15:03:26 by hlouar            #+#    #+#             */
/*   Updated: 2016/06/24 23:15:37 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	printlisthelp(t_liste *tmp, char *ptr)
{
	if (tmp->ts == 0 && tmp->tc == 0)
		ft_putendl_fd(tmp->str, 2);
	else if (tmp->ts == 1 && tmp->tc == 0)
	{
		ptr = (ft_joinfree(ft_strjoin("\033[31m", tmp->str), "\033[0m", 1));
		ptr = (ft_joinfree(ft_joinfree("\033[4m", ptr, 2), "\033[0m", 1));
		ft_putendl_fd(ptr, 2);
		free(ptr);
	}
	else if (tmp->tc == 1 && tmp->ts == 0)
	{
		ptr = (ft_joinfree(ft_strjoin("\033[41;30m", tmp->str), "\033[0m", 1));
		ptr = (ft_joinfree(ft_joinfree("\033[0m", ptr, 2), "\033[0m", 1));
		ft_putendl_fd(ptr, 2);
		free(ptr);
	}
	else if (tmp->tc == 1 && tmp->ts == 1)
	{
		ptr = (ft_joinfree(ft_strjoin("\033[41;30m", tmp->str), "\033[0m", 1));
		ptr = (ft_joinfree(ft_joinfree("\033[4m", ptr, 2), "\033[0m", 1));
		ft_putendl_fd(ptr, 2);
		free(ptr);
	}
}

void	printlist(t_env *e)
{
	t_liste	*tmp;
	int		x;
	int		y;
	char	*ptr;

	tmp = e->liste;
	x = 0;
	y = 0;
	ptr = NULL;
	while (tmp->next != e->liste)
	{
		tmp = tmp->next;
		tputs(tgoto(tgetstr("cm", NULL), x, y), 1, ft_putcharremix);
		printlisthelp(tmp, ptr);
		y++;
		if ((y + 1) == e->amax)
		{
			y = 0;
			x = (e->strl + x) + 1;
		}
	}
}

void	fill_liste(t_liste *liste, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		addelem(liste, av[i]);
		i++;
	}
}

void	mainhelp(t_env *e, char **buffer)
{
	if (BUFFER == FB)
		moveflecheb(e);
	else if (BUFFER == FH)
		moveflecheh(e);
	else if (BUFFER == SP)
		selectit(e);
	else if (BUFFER == ENTER)
		writeend(e);
	else if (BUFFER == DELETE || BUFFER == DELETE2)
		deletestring(e);
	else if (BUFFER == ECHAP)
	{
		e->term.c_lflag |= (ICANON | ECHO);
		if (tcsetattr(0, 0, &(e->term)) == -1)
			exit(0);
		tputs(tgetstr("te", NULL), 1, ft_putcharremix);
		tputs(tgetstr("ve", NULL), 1, ft_putcharremix);
		exit(0);
	}
}

int		main(int ac, char **av)
{
	t_env	e;
	char	*buffer[5];

	if (ac >= 2)
	{
		e.liste = ft_createlist();
		e.i = (ac - 1);
		init(&e, ac, av);
		while (42)
		{
			getinf(&e);
			if (windowtoosmall(&e) == 1)
				printlist(&e);
			else
				ft_putendl_fd("window is too small", 2);
			abc();
			ft_bzero(buffer, 5);
			read(2, buffer, 4);
			mainhelp(&e, buffer);
		}
	}
	return (0);
}
