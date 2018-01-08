/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deleg_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 01:19:39 by nsehnoun          #+#    #+#             */
/*   Updated: 2017/11/21 19:24:18 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	elag_total_print(struct s_f *f, t_list *l)
{
	if (f->l == 1 && l)
	{
		ft_putstr("total ");
		ft_putnbr(get_total(l));
		ft_putchar('\n');
	}
}

void	ft_putspace(char *str)
{
	ft_putstr(str);
	ft_putstr("  ");
}

void	elag_l_printer_1(struct s_f *f, t_list *list)
{
	if (f->l == 1)
	{
		ft_putstr(list->ds->chmod[0]);
		ft_putstr(list->ds->chmod[1]);
		ft_putstr(list->ds->chmod[2]);
		ft_putspace(list->ds->chmod[3]);
		ft_putnbr(list->ds->hlink);
		ft_putstr(" ");
		ft_putspace(list->ds->uname);
		ft_putspace(list->ds->gname);
		if (list->ds->chmod[0][0] == 'c' || list->ds->chmod[0][0] == 'b')
		{
			ft_putnbr(list->ds->maj);
			ft_putstr(", ");
			ft_putnbr(list->ds->min);
		}
		else
			ft_putnbr(list->ds->fs);
		ft_putstr("  ");
	}
}

void	elag_l_printer_2(struct s_f *f, t_list *list)
{
	if (f->l == 1)
	{
		(list->ds->chmod[0][0] == 'd' ? ft_putstr(KBCYN) : ft_putstr(KNRM));
		(list->ds->l > 0) ? ft_putstr(KMAG) : list->ds->l;
		list->ds->chmod[0][0] == 's' ? ft_putstr(KGRE) : list->ds->chmod[0][0];
		ft_putstr(list->ds->dname);
		ft_putstr(KNRM);
		if (list->ds->l > 0)
		{
			ft_putstr(" -> ");
			ft_putstr(list->ds->ln);
		}
		ft_putchar('\n');
	}
	else
	{
		if (list->ds->chmod[0][0] == 'd')
			ft_putstr(KBCYN);
		if (list->next != NULL)
			ft_putspace(list->ds->dname);
		else
			ft_putendl(list->ds->dname);
		ft_putstr(KNRM);
	}
}

void	elag_time(struct s_f *f, t_list *list)
{
	int		x;
	char	*tim;
	char	*ctim;

	if (f->l == 1)
	{
		x = time(0) - list->ds->time.tv_sec;
		if (x > 15552000 || x < 0)
		{
			ctim = ctime(&list->ds->time.tv_sec);
			tim = ft_strsub(ctime(&list->ds->time.tv_sec), 4, 19);
			ft_memmove(&tim[7], &ctim[20], 4);
			ft_memset(&tim[11], '\0', 9);
			*tim = tim[0];
		}
		else
			tim = ft_strsub(ctime(&list->ds->time.tv_sec), 4, 12);
		ft_putspace(tim);
		free(tim);
	}
}
