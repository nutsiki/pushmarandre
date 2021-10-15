/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:11:01 by moakouda          #+#    #+#             */
/*   Updated: 2021/10/14 15:11:04 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_checkspace(char *str)
{
	while (*str == '\n' || *str == '\f' || *str == '\r'
		|| *str == '\t' || *str == '\v' || *str == ' ')
		str++;
	return (str);
}

static int	ft_checkull(const char *str, int j)
{
	int		i;
	char	*tab;
	int		k;
	int		m;

	m = 0;
	tab = "18446744073709551615";
	i = ft_strlen(str);
	k = ft_strlen(tab);
	if (i < k)
		return (1);
	while (m++ < i)
	{
		if (!(str[m] >= '0' && str[m] <= '9'))
			return (1);
		if (str[m] > tab[m] && j == 1)
			return (-1);
		if (str[m] > tab[m] && j == -1)
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int					j;
	int					k;
	unsigned long long	nb;

	j = 1;
	nb = 0;
	str = ft_checkspace((char *)str);
	if (*str == '-')
		j = -1;
	if (*str == '+' || *str == '-')
		str++;
	k = ft_checkull(str, j);
	if (k != 1)
		return (k);
	while (*str && *str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		if (nb > 9223372036854775807 && j == 1)
			return (-1);
		if (nb > 9223372036854775807 && j == -1)
			return (0);
		str++;
	}
	return ((int)(nb * j));
}
