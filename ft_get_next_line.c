/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 14:55:38 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/29 13:54:59 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		read_fd(const int fd, char **rmn, char **line, size_t offset)
{
	char		buf[BUFFER_SIZE + 1];
	long		next;
	ssize_t		count;

	if ((count = ft_strcpy(buf, *rmn)))
		**rmn = 0;
	else if (!(count = read(fd, buf, BUFFER_SIZE)))
		return ((*line = ft_calloc(offset, sizeof(char))) ? END : ERROR);
	else if (count == ERROR)
		return (ERROR);
	else
		buf[count] = '\0';
	if ((next = ft_strchri(buf, '\n')) != NOT_FOUND)
	{
		ft_strcpy(*rmn, &buf[next + 1]);
		if ((*line = ft_calloc(offset + next, sizeof(char))))
			ft_strccpy(*line + offset, buf, '\n');
		return (*line ? LINE : ERROR);
	}
	if ((next = read_fd(fd, rmn, line, offset + count)) == ERROR)
		return (ERROR);
	ft_memcpy(*line + offset, buf, count);
	return (next);
}

int				get_next_line(const int fd, char **line)
{
	static char	*rmn;
	int			ret;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 0)
		return (ERROR);
	if (rmn == NULL)
	{
		if ((rmn = malloc(BUFFER_SIZE + 1)) == NULL)
			return (ERROR);
		*rmn = 0;
	}
	if ((ret = read_fd(fd, &rmn, line, 0)) < LINE)
	{
		free(rmn);
		rmn = NULL;
	}
	return (ret);
}
