/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_factory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 22:27:01 by nsehnoun          #+#    #+#             */
/*   Updated: 2017/11/21 18:48:54 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		filter_args(char **a, char **flags)
{
	int		i;
	int		y;
	int		x;
	char	c;

	i = 0;
	x = 0;
	while (a[++i])
	{
		y = 1;
		if (a[i][0] == '-' && a[i][y] != '\0')
		{
			while (a[i][y] != '\0' && (c = a[i][y]) && ft_isascii(a[i][y++]))
				if (c != L && c != R && c != A && c != R1 && c != T && c != '1')
					print_usages(a[i][y - 1]);
			add_flags(flags, a[i]);
		}
		else if (a[i][0] == '-' && a[i][y] == '\0')
			ft_putendl("ft_ls: -: No such file or directory");
		else
			x++;
	}
	return (x);
}

char	**get_paths(int x, char **argv)
{
	int		i;
	int		y;
	char	**paths;

	i = 1;
	y = 0;
	if (!(paths = (char **)malloc(sizeof(char *) * (x + 1))))
		return (NULL);
	paths[x] = NULL;
	while (argv[i])
	{
		if (argv[i][0] != '-')
			paths[y++] = ft_strdup(argv[i]);
		i++;
	}
	return (paths);
}

char	**clean_paths(char **paths, int x)
{
	int		i;
	int		y;
	char	**correct_paths;

	i = 0;
	y = 0;
	if (!(correct_paths = (char **)malloc(sizeof(char *) * (x + 1))))
		return (NULL);
	while (paths[i] != NULL)
	{
		if (path_args(paths[i]) == -1 && paths[i] != NULL)
			ft_bzero(paths[i], ft_strlen(paths[i]));
		else
			correct_paths[y++] = ft_strdup(paths[i]);
		i++;
	}
	correct_paths[y] = NULL;
	return (correct_paths);
}

void	sort_paths_flags(struct s_f *f, char **paths, int *time)
{
	if (paths)
	{
		if (f->r == 1 && f->t == 1)
		{
			sort_path_timerev(paths, time);
			sort_paths_rev(paths);
		}
		else
		{
			if (f->r == 1)
				sort_paths_rev(paths);
			if (f->t == 1)
				sort_path_time(paths, time);
		}
	}
}

char	**paths_manager(int x, char **args, struct s_f *f, int *y)
{
	int			i;
	struct stat	st;
	int			*time;
	char		**paths;
	char		**tmp;

	i = 0;
	tmp = get_paths(x, args);
	paths = tmp;
	sort_paths(paths);
	paths = clean_paths(paths, x);
	time = get_time(x);
	y = alloc_y(y, x);
	while (paths[i])
	{
		stat(paths[i], &st);
		time[i] = st.st_mtimespec.tv_sec;
		i++;
	}
	sort_paths_flags(f, paths, time);
	y = file_tosort(paths, y, st);
	sort_filendir(paths, y);
	free_timenfiles(time, y, tmp);
	return (paths);
}
