/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deleg_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 20:48:10 by nsehnoun          #+#    #+#             */
/*   Updated: 2017/11/21 20:19:02 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		*get_time(int x)
{
	int		i;
	int		*time;

	i = 0;
	if (!(time = malloc(sizeof(int) * (x + 1))))
		return (NULL);
	time[x] = '\0';
	return (time);
}

int		*alloc_y(int *y, int x)
{
	if (!(y = malloc(sizeof(int) * (x + 1))))
		return (NULL);
	y[x - 1] = '\0';
	return (y);
}

void	sort_filendir(char **cp, int *x)
{
	int		i;
	char	*tmp_char;
	int		is_sorted;
	int		tim;

	is_sorted = 1;
	while (is_sorted)
	{
		i = 0;
		is_sorted = 0;
		while (cp[i] != NULL)
		{
			if (cp[i + 1] != NULL && x[i] < x[i + 1])
			{
				tmp_char = cp[i];
				cp[i] = cp[i + 1];
				cp[i + 1] = tmp_char;
				tim = x[i];
				x[i] = x[i + 1];
				x[i + 1] = tim;
				is_sorted = 1;
			}
			i++;
		}
	}
}

void	free_timenfiles(int *x, int *y, char **str)
{
	int i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	free(x);
	free(y);
}
