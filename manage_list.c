/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 18:00:57 by nsehnoun          #+#    #+#             */
/*   Updated: 2017/11/15 21:49:08 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_ld(t_list *ld)
{
	int			swp;
	t_list		*n_ld;
	void		*tmp_content;

	if (ld != NULL)
	{
		swp = 1;
		while (swp)
		{
			swp = 0;
			n_ld = ld;
			while (n_ld->next != NULL)
			{
				if (ft_strcmp(n_ld->content, n_ld->next->content) > 0)
				{
					tmp_content = n_ld->content;
					n_ld->content = n_ld->next->content;
					n_ld->next->content = tmp_content;
					swp = 1;
				}
				n_ld = n_ld->next;
			}
		}
	}
}

void	ft_lstdells(t_list **alst, void (*del)(void *, size_t))
{
	t_list *l;

	if ((*alst) != NULL)
	{
		while (*alst)
		{
			del((*alst)->content, ft_strlen((*alst)->content));
			l = (*alst)->next;
			free((*alst));
			(*alst) = l;
		}
		(*alst) = NULL;
	}
}
