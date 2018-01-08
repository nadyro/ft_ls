/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 00:15:17 by nsehnoun          #+#    #+#             */
/*   Updated: 2017/11/21 04:08:37 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		elag_sorting(t_list **l, int *i)
{
	struct s_ds *d;

	d = (*l)->ds;
	(*l)->ds = (*l)->next->ds;
	(*l)->next->ds = d;
	*i = 1;
}

void		sort_ldi(t_list *ld)
{
	int			swp;
	t_list		*n_ld;
	struct s_ds	*d;
	struct s_ds	*d1;

	if (ld != NULL)
	{
		swp = 1;
		while (swp)
		{
			swp = 0;
			n_ld = ld;
			while (n_ld->next != NULL)
			{
				d = n_ld->ds;
				d1 = n_ld->next->ds;
				if (ft_strcmp(d->dname, d1->dname) > 0)
					elag_sorting(&n_ld, &swp);
				if (d->lf > d1->lf)
					d1->lf = d->lf;
				n_ld = n_ld->next;
			}
		}
	}
}

void		sort_ldinf(t_list *ld)
{
	int			swp;
	t_list		*n_ld;
	struct s_ds	*d;
	struct s_ds	*d1;

	if (ld != NULL)
	{
		swp = 1;
		while (swp)
		{
			swp = 0;
			n_ld = ld;
			while (n_ld->next != NULL)
			{
				d = n_ld->ds;
				d1 = n_ld->next->ds;
				if (ft_strcmp(d->dname, d1->dname) < 0)
					elag_sorting(&n_ld, &swp);
				if (d->lf > d1->lf)
					d1->lf = d->lf;
				n_ld = n_ld->next;
			}
		}
	}
}

void		sort_ldtime(t_list *ld)
{
	int			swp;
	t_list		*n_ld;
	struct s_ds	*d;
	struct s_ds	*d1;

	if (ld != NULL)
	{
		swp = 1;
		while (swp)
		{
			swp = 0;
			n_ld = ld;
			while (n_ld->next != NULL)
			{
				d = n_ld->ds;
				d1 = n_ld->next->ds;
				if (d->time.tv_sec < d1->time.tv_sec)
					elag_sorting(&n_ld, &swp);
				if (d->lf > d1->lf)
					d1->lf = d->lf;
				n_ld = n_ld->next;
			}
		}
	}
}

void		sort_ldtimerev(t_list *ld)
{
	int			swp;
	t_list		*n_ld;
	struct s_ds	*d;
	struct s_ds	*d1;

	if (ld != NULL)
	{
		swp = 1;
		while (swp)
		{
			swp = 0;
			n_ld = ld;
			while (n_ld->next != NULL)
			{
				d = n_ld->ds;
				d1 = n_ld->next->ds;
				if (d->time.tv_sec > d1->time.tv_sec)
					elag_sorting(&n_ld, &swp);
				if (d->lf > d1->lf)
					d1->lf = d->lf;
				n_ld = n_ld->next;
			}
		}
	}
}
