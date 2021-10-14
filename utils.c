/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:46:40 by moakouda          #+#    #+#             */
/*   Updated: 2021/10/14 11:46:41 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = (char *)s;
	while (n-- > 0)
		p[n] = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	char	*pp;

	p = (char *)malloc(count * size);
	if (!p)
		exit(1);
	count *= size;
	pp = p;
	while (count--)
		*p++ = 0;
	return (pp);
}

int	ft_isdigit(int c)
{
	return ((c >= 48) && (c <= 57));
}

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (ps1[i] != '\0' && ps2[i] != '\0' && i < n - 1 && ps1[i] == ps2[i])
	{
		i++;
	}
	return (ps1[i] - ps2[i]);
}
