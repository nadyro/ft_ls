/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirs_infos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 20:35:57 by nsehnoun          #+#    #+#             */
/*   Updated: 2017/11/21 13:54:54 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*path_return(char *d, char *dn)
{
	char	*path_r;
	char	*tmp;

	tmp = ft_strjoin(d, "/");
	path_r = tmp;
	tmp = ft_strjoin(tmp, dn);
	free(path_r);
	return (tmp);
}

int		check_dots(char *dname)
{
	if (ft_strcmp(dname, ".") == 0 || ft_strcmp(dname, "..") == 0)
		return (1);
	return (0);
}

void	recursive_flow(char *c, t_list **lp, struct s_f *f, t_list *l)
{
	char	*path_r;

	path_r = path_return(c, (*lp)->content);
	read_dir(path_r, f, l);
	free(path_r);
	(*lp) = ft_freelist(lp, f);
}

t_list	*ft_freelist(t_list **l, struct s_f *f)
{
	t_list	*tmp;

	free((*l)->content);
	if (f->l == 1)
	{
		free((*l)->ds->gname);
		free((*l)->ds->uname);
	}
	free((*l)->ds->dname);
	free((*l)->ds->chmod[0]);
	free((*l)->ds->chmod[1]);
	free((*l)->ds->chmod[2]);
	free((*l)->ds->chmod[3]);
	free((*l)->ds->chmod);
	free((*l)->ds);
	tmp = (*l)->next;
	free((*l));
	(*l) = tmp;
	return ((*l));
}
