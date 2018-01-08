/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chmod_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 00:53:13 by nsehnoun          #+#    #+#             */
/*   Updated: 2017/11/21 18:15:59 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*chmod_usr(char *chmod, struct stat st)
{
	chmod[0] = ((st.st_mode & S_IRUSR)) ? 'r' : '-';
	chmod[1] = ((st.st_mode & S_IWUSR)) ? 'w' : '-';
	chmod[2] = '-';
	if (st.st_mode & S_ISUID)
		chmod[2] = (st.st_mode & S_IXUSR) ? 's' : 'S';
	else if (st.st_mode & S_IXUSR)
		chmod[2] = 'x';
	return (chmod);
}

char	*chmod_grp(char *chmod, struct stat st)
{
	chmod[0] = ((st.st_mode & S_IRGRP)) ? 'r' : '-';
	chmod[1] = ((st.st_mode & S_IWGRP)) ? 'w' : '-';
	chmod[2] = '-';
	if (st.st_mode & S_ISGID)
		chmod[2] = (st.st_mode & S_IXGRP) ? 's' : 'S';
	else if (st.st_mode & S_IXGRP)
		chmod[2] = 'x';
	return (chmod);
}

char	*chmod_oth(char *chmod, struct stat st)
{
	chmod[0] = ((st.st_mode & S_IROTH)) ? 'r' : '-';
	chmod[1] = ((st.st_mode & S_IWOTH)) ? 'w' : '-';
	chmod[2] = '-';
	if (st.st_mode & S_ISVTX)
		chmod[2] = (st.st_mode & S_IXOTH) ? 't' : 'T';
	else if (st.st_mode & S_IXOTH)
		chmod[2] = 'x';
	return (chmod);
}

void	free_chmod(char **chmod)
{
	ft_strdel(&chmod[0]);
	ft_strdel(&chmod[1]);
	ft_strdel(&chmod[2]);
	ft_strdel(&chmod[3]);
	free(chmod);
}
