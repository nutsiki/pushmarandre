/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:49:04 by moakouda          #+#    #+#             */
/*   Updated: 2021/10/14 13:49:09 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_piles *piles, int i, int j)
{
	int		max;
	t_list	*tmp;

	if (!piles->list_b)
		return (0);
	tmp = piles->list_b;
	max = tmp->content;
	while (tmp && i++ < j)
	{
		if (max < tmp->content)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
}

int	find_min(t_piles *piles, int i, int j)
{
	int		min;
	t_list	*tmp;

	tmp = piles->sorted;
	min = tmp->content;
	while (i++ < j)
	{
		if (min > tmp->content)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

int	find_2min(t_piles *piles, int i, int j, int min)
{
	int		min_2;
	t_list	*tmp;

	tmp = piles->sorted;
	if (tmp->content != min)
		min_2 = tmp->content;
	else
		min_2 = tmp->next->content;
	while (i++ < j)
	{
		if (tmp->content != min && min_2 > tmp->content)
			min_2 = tmp->content;
		tmp = tmp->next;
	}
	return (min_2);
}

int	find_sens(t_list **tmp, int *min, int *min_2)
{
	int	i;

	i = 0;
	while ((*tmp) && ((*tmp)->content != *min && (*tmp)->content != *min_2))
	{
		(*tmp) = (*tmp)->next;
		i++;
	}
	if ((*tmp) && (*tmp)->content == *min)
		*min = *min_2;
	return (i);
}
