/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 02:24:28 by nsehnoun          #+#    #+#             */
/*   Updated: 2017/11/21 19:42:02 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_paths(char **correct_paths)
{
	int		i;
	int		is_sorted;
	char	*tmp_char;

	i = 0;
	is_sorted = 1;
	while (is_sorted)
	{
		i = 0;
		is_sorted = 0;
		while (correct_paths[i] != NULL)
		{
			if (correct_paths[i + 1] != NULL &&
					(ft_strcmp(correct_paths[i], correct_paths[i + 1]) > 0))
			{
				tmp_char = correct_paths[i];
				correct_paths[i] = correct_paths[i + 1];
				correct_paths[i + 1] = tmp_char;
				is_sorted = 1;
			}
			i++;
		}
	}
}

void	sort_paths_rev(char **correct_paths)
{
	int		i;
	int		is_sorted;
	char	*tmp_char;

	i = 0;
	is_sorted = 1;
	while (is_sorted)
	{
		i = 0;
		is_sorted = 0;
		while (correct_paths[i] != NULL)
		{
			if (correct_paths[i + 1] != NULL &&
					(ft_strcmp(correct_paths[i], correct_paths[i + 1]) < 0))
			{
				tmp_char = correct_paths[i];
				correct_paths[i] = correct_paths[i + 1];
				correct_paths[i + 1] = tmp_char;
				is_sorted = 1;
			}
			i++;
		}
	}
}

void	sort_path_time(char **cp, int *time)
{
	int		i;
	char	*tmp_char;
	int		is_sorted;
	long	tim;

	is_sorted = 1;
	while (is_sorted)
	{
		i = 0;
		is_sorted = 0;
		while (cp[i] != NULL)
		{
			if (cp[i + 1] != NULL && time[i] < time[i + 1])
			{
				tmp_char = cp[i];
				cp[i] = cp[i + 1];
				cp[i + 1] = tmp_char;
				tim = time[i];
				time[i] = time[i + 1];
				time[i + 1] = tim;
				is_sorted = 1;
			}
			i++;
		}
	}
}

void	sort_path_timerev(char **cp, int *time)
{
	int		i;
	char	*tmp_char;
	int		is_sorted;
	long	tim;

	is_sorted = 1;
	while (is_sorted)
	{
		i = 0;
		is_sorted = 0;
		while (cp[i] != NULL)
		{
			if (cp[i + 1] != NULL && time[i] > time[i + 1])
			{
				tmp_char = cp[i];
				cp[i] = cp[i + 1];
				cp[i + 1] = tmp_char;
				tim = time[i];
				time[i] = time[i + 1];
				time[i + 1] = tim;
				is_sorted = 1;
			}
			i++;
		}
	}
}
