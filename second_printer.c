/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:14:34 by nsehnoun          #+#    #+#             */
/*   Updated: 2017/11/21 19:21:45 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_errors(char *directory)
{
	ft_putstr("ft_ls: ");
	perror(directory);
}

void	ft_putdots(char *str)
{
	ft_putstr(str);
	ft_putendl(":");
}

void	print_usages(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putchar('\n');
	ft_putstr("usage: ft_ls [-ABCFGHLOPRSTUWa");
	ft_putendl("bcdefghiklmnopqrstuwx1] [file ...]");
	ft_putendl("Commandes valables : -lRtar");
	exit(1);
}

void	get_timefile(struct s_f *f, time_t timef)
{
	int		x;
	char	*tim;
	char	*ctim;

	if (f->l == 1)
	{
		x = time(0) - timef;
		if (x > 15552000 || x < 0)
		{
			ctim = ctime(&timef);
			tim = ft_strsub(ctime(&timef), 4, 19);
			ft_memmove(&tim[7], &ctim[20], 4);
			ft_memset(&tim[11], '\0', 9);
			*tim = tim[0];
		}
		else
			tim = ft_strsub(ctime(&timef), 4, 12);
		ft_putspace(tim);
		free(tim);
	}
}

void	is_file(char *file, struct s_f *f)
{
	struct stat		st;
	char			**chmod;
	struct group	*g;
	struct passwd	*p;

	lstat(file, &st);
	chmod = ft_chmod(st);
	if (f->l == 1)
	{
		g = getgrgid(st.st_gid);
		p = getpwuid(st.st_uid);
		ft_putchmod(chmod);
		ft_putnbr(st.st_nlink);
		ft_putstr("  ");
		(p == NULL ? ft_putnbr(st.st_uid) : ft_putspace(p->pw_name));
		(g == NULL ? ft_putnbr(st.st_gid) : ft_putspace(g->gr_name));
		ft_major_minor(st, chmod);
		ft_putstr("  ");
		get_timefile(f, st.st_mtimespec.tv_sec);
		is_link(file, st);
		free_chmod(chmod);
	}
	else
		ft_putendl(file);
}
