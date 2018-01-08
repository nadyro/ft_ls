/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 15:59:15 by nsehnoun          #+#    #+#             */
/*   Updated: 2017/11/21 19:20:00 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		is_link(char *file, struct stat st)
{
	char	ln[1024];
	ssize_t	l;

	ft_putstr(file);
	if (S_ISLNK(st.st_mode))
	{
		if ((l = readlink(file, ln, sizeof(ln) - 1)) != -1)
		{
			ln[l] = '\0';
			ft_putstr(" -> ");
			ft_putendl(ln);
		}
	}
	else
		ft_putchar('\n');
}

void		multi_paths(int o, struct s_f *f, char **av, t_list *l)
{
	char	**correct_paths;
	int		i;
	int		*y;

	i = 0;
	y = 0;
	correct_paths = (o > 0) ? paths_manager(o, av, f, y) : NULL;
	while (o > 0 && correct_paths[i] != NULL)
	{
		if (path_args(correct_paths[i]) == 0)
		{
			if (o > 1)
				print_typeflags(correct_paths[i]);
			read_dir_param(correct_paths[i], f, l);
		}
		else if (path_args(correct_paths[i]) == 1)
			is_file(correct_paths[i], f);
		free(correct_paths[i++]);
	}
	free(correct_paths);
}

void		read_dir_param(char *directory, struct s_f *flags, t_list *l)
{
	DIR				*dir;
	struct dirent	*dirc;
	struct stat		st;
	t_list			*listp;

	listp = NULL;
	if ((dir = opendir(directory)) && (lstat(directory, &st) != -1))
	{
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

int			main(int argc, char **argv)
{
	int			i;
	int			object;
	char		*flags;
	struct s_f	*turn_flags;
	t_list		*l;

	l = NULL;
	i = 0;
	(void)argc;
	flags = ft_strnew(0);
	if ((object = filter_args(argv, &flags)) == -1)
		exit(-1);
	turn_flags = tf(flags);
	if (object == 0)
		read_dir(".", turn_flags, l);
	else if (object > 0)
		multi_paths(object, turn_flags, argv, l);
	free(turn_flags);
	return (0);
}
