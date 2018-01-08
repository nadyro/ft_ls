/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_factory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 14:09:49 by nsehnoun          #+#    #+#             */
/*   Updated: 2017/11/21 18:27:26 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_dirs(char *directory, char *dn, t_list **list_dirs, struct s_f *f)
{
	t_list		*last;
	t_list		*d_node;
	struct s_ds	*d;

	last = *list_dirs;
	if (!(d_node = (t_list *)malloc(sizeof(t_list))))
		exit(1);
	d_node->content = ft_strdup(dn);
	d = stats_infos(directory, dn, f);
	d_node->ds = d;
	d_node->next = NULL;
	if (*list_dirs == NULL)
	{
		*list_dirs = d_node;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = d_node;
}

t_list	*get_folders(t_list **l, char *d, struct s_f *flags, t_list *lp)
{
	struct stat	st;
	char		*path;

	while ((*l))
	{
		path = path_return(d, (*l)->ds->dname);
		lstat(path, &st);
		free(path);
		if (flags->re == 1)
		{
			if (S_ISDIR(st.st_mode))
			{
				if (check_dots((*l)->ds->dname) == 1)
				{
					(*l) = ft_freelist(l, flags);
					continue;
				}
				get_dirs(d, (*l)->ds->dname, &lp, flags);
			}
		}
		(*l) = ft_freelist(l, flags);
	}
	return (lp);
}

void	elag_readdir(struct s_f *flags, t_list *l)
{
	sort_ldi(l);
	if (flags->r == 1 && flags->t == 1)
	{
		sort_ldinf(l);
		sort_ldtimerev(l);
	}
	else
	{
		if (flags->r == 1)
			sort_ldinf(l);
		if (flags->t == 1)
			sort_ldtime(l);
	}
}

t_list	*sort_print_listp(struct s_f *f, t_list **l, char *d, t_list *lp)
{
	elag_readdir(f, (*l));
	ft_printlist((*l), f);
	lp = get_folders(l, d, f, lp);
	return (lp);
}

void	read_dir(char *directory, struct s_f *flags, t_list *l)
{
	DIR				*dir;
	struct dirent	*dirc;
	struct stat		st;
	t_list			*listp;

	listp = NULL;
	if ((dir = opendir(directory)) && (lstat(directory, &st) != -1))
	{
		if (flags->re == 1)
			print_typeflags(directory);
		while ((dirc = readdir(dir)) != NULL)
		{
			if (flags->a == 0 && dirc->d_name[0] == '.')
				continue;
			get_dirs(directory, dirc->d_name, &l, flags);
		}
		listp = sort_print_listp(flags, &l, directory, listp);
		if (flags->re == 1)
			while (listp)
				recursive_flow(directory, &listp, flags, l);
		closedir(dir);
	}
	else
		print_errors(directory);
}
