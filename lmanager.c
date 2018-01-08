/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmanager.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:09:34 by nsehnoun          #+#    #+#             */
/*   Updated: 2017/11/21 18:17:20 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

struct s_ds		*elag_stats(char *dn, struct stat st)
{
	struct s_ds	*d;

	if (!(d = (struct s_ds *)malloc(sizeof(struct s_ds))))
		return (NULL);
	d->dname = ft_strdup(dn);
	d->chmod = ft_chmod(st);
	d->lf = ft_strlen(dn);
	d->time = st.st_mtimespec;
	d->l = 0;
	d->fs = st.st_size;
	return (d);
}

struct s_ds		*stats_infos(char *dr, char *dn, struct s_f *f)
{
	struct group	*g;
	struct passwd	*p;
	struct s_ds		*d;
	struct stat		st;
	char			*path;

	path = path_return(dr, dn);
	lstat(path, &st);
	d = elag_stats(dn, st);
	if (f->l == 1)
	{
		g = getgrgid(st.st_gid);
		p = getpwuid(st.st_uid);
		d->hlink = st.st_nlink;
		d->gname = (g == NULL) ? ft_itoa(st.st_gid) : ft_strdup(g->gr_name);
		d->uname = (p == NULL) ? ft_itoa(st.st_uid) : ft_strdup(p->pw_name);
		d->maj = major(st.st_rdev);
		d->min = minor(st.st_rdev);
		d->blocks = st.st_blocks;
		if (S_ISLNK(st.st_mode))
			if ((d->l = readlink(path, d->ln, sizeof(d->ln) - 1)) != -1)
				d->ln[d->l] = '\0';
	}
	free(path);
	return (d);
}

char			**ft_chmod(struct stat st)
{
	char	**chmod;
	int		i;

	i = 1;
	if (!(chmod = (char **)malloc(sizeof(char *) * 4)))
		return (NULL);
	chmod[0] = ft_strdup("-");
	while (i < 4)
		chmod[i++] = ft_strnew(3);
	if (S_ISLNK(st.st_mode))
		chmod[0][0] = 'l';
	else if (S_ISDIR(st.st_mode))
		chmod[0][0] = 'd';
	else if (S_ISSOCK(st.st_mode))
		chmod[0][0] = 's';
	else if (S_ISFIFO(st.st_mode))
		chmod[0][0] = 'p';
	else if (S_ISCHR(st.st_mode))
		chmod[0][0] = 'c';
	else if (S_ISBLK(st.st_mode))
		chmod[0][0] = 'b';
	chmod[1] = chmod_usr(chmod[1], st);
	chmod[2] = chmod_grp(chmod[2], st);
	chmod[3] = chmod_oth(chmod[3], st);
	return (chmod);
}

int				*file_tosort(char **paths, int *y, struct stat st)
{
	int i;

	i = 0;
	while (paths[i])
	{
		stat(paths[i], &st);
		y[i] = (S_ISDIR(st.st_mode)) ? 0 : 1;
		i++;
	}
	return (y);
}
