/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 11:12:16 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/29 11:50:47 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strccpy(char *dest, const char *src, char c)
{
	size_t		index;

	index = 0;
	while (src[index] && src[index] != c)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (index);
}
