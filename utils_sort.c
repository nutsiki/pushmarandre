/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:34:58 by moakouda          #+#    #+#             */
/*   Updated: 2021/10/14 14:35:00 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index_sorted(t_piles *piles, int i)
{
	t_list	*tmp;

	tmp = piles->sorted;
	while (i--)
		tmp = tmp->next;
	return (tmp->content);
}

int	hold_first(t_piles *piles, int index)
{
	t_list	*tmp;
	int		i;
	int		j;
	int		index_sorted;

	i = 0;
	j = -1;
	index_sorted = get_index_sorted(piles, index);
	tmp = piles->list_a;
	while (tmp)
	{
		if (tmp->content <= index_sorted)
		{
			j = i;
			break ;
		}
		tmp = tmp->next;
		i++;
	}
	return (j);
}

int	hold_second(t_piles *piles, int index)
{
	t_list	*tmp;
	int		i;
	int		j;
	int		index_sorted;

	i = 0;
	j = 0;
	index_sorted = get_index_sorted(piles, index);
	tmp = piles->list_a;
	while (tmp)
	{
		if (tmp->content <= index_sorted)
			j = i;
		tmp = tmp->next;
		i++;
	}
	return (j);
}

void	prepare_b(t_piles *piles, int size, int max, int previous)
{
	t_list	*tmp;
	int		i;

	tmp = piles->list_b;
	i = 0;
	while (tmp && ((piles->list_a->content < tmp->content)
			|| (piles->list_a->content > previous)))
	{
		previous = tmp->content;
		tmp = tmp->next;
		i++;
	}
	if (!tmp && i == size)
	{
		while (piles->list_b->content != max)
			reverse_b(piles);
		push_b(piles);
		return ;
	}
	if (i <= (size / 2))
		while (i--)
			rotate_b(piles);
	else if (i)
		while (i++ < size)
			reverse_b(piles);
}

void	make_chunk(t_piles *piles, int size, int index)
{
	int	i;
	int	j;
	int	size_b;
	int	previous;

	i = hold_first(piles, index);
	j = hold_second(piles, index);
	size_b = ft_lstsize(piles->list_b);
	if ((size - j) > i)
		while (i--)
			rotate_a(piles);
	else
		while (j++ < size)
			reverse_a(piles);
	if (!piles->list_b || !piles->list_b->next)
	{
		push_b(piles);
		return ;
	}
	if (!piles->list_b->next->next
		&& (piles->list_b->content < piles->list_b->next->content))
		swap_b(piles);
	previous = ft_lstlast(piles->list_b)->content;
	prepare_b(piles, size_b, find_max(piles, 0, size_b), previous);
	push_b(piles);
}
