/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 23:06:07 by nsehnoun          #+#    #+#             */
/*   Updated: 2017/11/21 07:57:23 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 == *str2++)
	{
		if (*str1++ == '\0')
			return (0);
	}
	return (*(const unsigned char *)str1 - *(const unsigned char *)(str2 - 1));
}
