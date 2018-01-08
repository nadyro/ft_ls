/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 17:45:51 by nsehnoun          #+#    #+#             */
/*   Updated: 2017/11/21 18:25:56 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_total(t_list *l)
{
	int i;

	i = 0;
	while (l)
	{
		i += l->ds->blocks;
		l = l->next;
	}
	return (i);
}

void	ft_printlist(t_list *list, struct s_f *f)
{
	elag_total_print(f, list);
	while (list)
	{
		elag_l_printer_1(f, list);
		elag_time(f, list);
		elag_l_printer_2(f, list);
		list = list->next;
	}
}

void	ft_major_minor(struct stat st, char **chmod)
{
	if (chmod[0][0] == 'c' || chmod[0][0] == 'b')
	{
		ft_putnbr(major(st.st_rdev));
		ft_putstr(", ");
		ft_putnbr(minor(st.st_rdev));
	}
	else
		ft_putnbr(st.st_size);
}

void	print_typeflags(char *directory)
{
	ft_putstr(directory);
	ft_putendl(": ");
}

void	ft_putchmod(char **chmod)
{
	ft_putstr(chmod[0]);
	ft_putstr(chmod[1]);
	ft_putstr(chmod[2]);
	ft_putspace(chmod[3]);
}
