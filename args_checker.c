/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 17:52:36 by nsehnoun          #+#    #+#             */
/*   Updated: 2017/11/21 18:55:43 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			path_args(char *directory)
{
	struct stat st;

	lstat(directory, &st);
	if (S_ISDIR(st.st_mode))
		return (0);
	else
	{
		if (S_ISREG(st.st_mode) ||
				S_ISSOCK(st.st_mode) ||
				S_ISFIFO(st.st_mode) || S_ISLNK(st.st_mode)
				|| S_ISCHR(st.st_mode) || S_ISBLK(st.st_mode))
			return (1);
		else
		{
			print_errors(directory);
			return (-1);
		}
	}
}

void		add_flags(char **flags, char *flag)
{
	char	*tmp;

	tmp = flags[0];
	flags[0] = ft_strjoin(tmp, flag);
	free(tmp);
}

void		declare_struct(struct s_f *flags, char *sflags)
{
	if (!flags && !sflags)
		exit(1);
	flags->l = 0;
	flags->re = 0;
	flags->a = 0;
	flags->r = 0;
	flags->t = 0;
	if (ft_strchr(sflags, L))
		flags->l = 1;
	if (ft_strchr(sflags, R))
		flags->re = 1;
	if (ft_strchr(sflags, A))
		flags->a = 1;
	if (ft_strchr(sflags, R1))
		flags->r = 1;
	if (ft_strchr(sflags, T))
		flags->t = 1;
	free(sflags);
}

struct s_f	*tf(char *flags)
{
	struct s_f	*tf;

	if (!(tf = (struct s_f *)malloc(sizeof(struct s_f))))
		return (NULL);
	declare_struct(tf, flags);
	return (tf);
}
