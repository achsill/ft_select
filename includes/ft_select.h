/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 14:24:26 by hlouar            #+#    #+#             */
/*   Updated: 2016/06/24 23:16:46 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <termios.h>
# include <unistd.h>
# include <term.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <curses.h>
# include "../libft/libft.h"
# define BUFFER *(unsigned int*)buffer
# define FB 4348699
# define FH 4283163
# define SP 32
# define ENTER 10
# define DELETE 127
# define DELETE2 2117294875
# define ECHAP 27

typedef struct	s_liste
{
	char			*str;
	int				ts;
	int				tc;
	struct s_liste	*next;
	struct s_liste	*prev;
}				t_liste;

typedef struct	s_env
{
	int				i;
	int				strl;
	int				amax;
	int				bmax;
	int				tmpx;
	int				tmpy;
	char			**buff;
	struct termios	term;
	char			*name_term;
	struct s_liste	*liste;
}				t_env;

int				ft_setterm(t_env *e);
void			init(t_env *e, int ac, char **av);
void			selectithelp(t_liste *tmp, t_env *e);
void			fill_liste(t_liste *liste, int ac, char **av);
void			ft_strlenmax(t_env *e);
int				windowtoosmall(t_env *e);
int				countmaille(t_env *e);
void			addelem(t_liste *liste, char *str);
int				ft_putcharremix(int i);
void			fillint(t_liste *liste);
t_liste			*ft_createlist(void);
void			ft_ex(void);
void			switchsig(int a);
void			stopsig(void);
void			continuesig(void);
void			switchsig(int a);
void			abc(void);
void			deletestring(t_env *e);
void			moveflecheb(t_env *e);
void			setread(t_env *e);
void			abc(void);
void			selectit(t_env *e);
void			writeend(t_env *e);
void			moveflecheh(t_env *e);
void			printdashi(t_liste *liste);
void			getinf(t_env *e);
void			ressize();
void			printlist(t_env *e);
t_env			*stock(t_env *e, int i);
#endif
