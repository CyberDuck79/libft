/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:40:52 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/29 14:01:36 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t len, size_t size)
{
	void	*ptr;

	if (!len)
		len++;
	if (!(ptr = malloc(size * len)))
		return (NULL);
	ft_bzero(ptr, size * len);
	return (ptr);
}
