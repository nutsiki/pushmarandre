/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:25:31 by moakouda          #+#    #+#             */
/*   Updated: 2021/10/14 15:25:32 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_putstr_fd_err(char *s, int fd)
{
	if (!s && fd < 0)
		exit(1);
	write(fd, s, ft_strlen(s));
	exit(1);
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (n == 0 || dest == src)
		return (dest);
	while (n--)
		*d++ = *s++;
	return (dest);
}

t_piles	*more_size(t_piles *piles)
{
	char	*new_buff;

	new_buff = piles->action;
	piles->length += BUFFER_SIZE;
	piles->action = (char *)ft_calloc(sizeof(char), piles->length);
	piles->action = ft_memcpy(piles->action, new_buff, piles->pos);
	free((void *)new_buff);
	return (piles);
}

t_piles	*fill_buffer(t_piles *piles, char action)
{
	if (piles->pos + 1 >= piles->length)
		return (fill_buffer(more_size(piles), action));
	*(piles->action + piles->pos) = action;
	(piles->pos)++;
	return (piles);
}

int	fill_buffer_str(char *str, t_piles *piles)
{
	while (*str)
	{
		fill_buffer(piles, *str);
		if (!piles)
			return (-1);
		str++;
	}
	return (1);
}
