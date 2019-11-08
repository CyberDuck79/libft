/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstrrsort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:16:33 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/08 14:26:43 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabstrrsort(char **tab)
{
	t_bool	sort;
	char	**head;
	char	*swp;

	if (!tab || !*tab || !tab[1])
		return ;
	sort = true;
	head = tab;
	while (sort)
	{
		sort = false;
		while (*tab)
		{
			while (tab[1] && ft_strcmp(*tab, tab[1]) < 0)
			{
				sort = true;
				swp = tab[1];
				tab[1] = *tab;
				*tab = swp;
			}
			tab++;
		}
		tab = head;
	}
}
