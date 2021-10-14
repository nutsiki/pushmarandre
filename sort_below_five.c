/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_below_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:52:11 by moakouda          #+#    #+#             */
/*   Updated: 2021/10/14 13:52:13 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_piles *piles)
{
	if (piles->list_a->content < piles->list_a->next->content
		&& piles->list_a->next->content < piles->list_a->next->next->content)
		return ;
	else if (piles->list_a->content < piles->list_a->next->content
		&& piles->list_a->content < piles->list_a->next->next->content)
	{
		swap_a(piles);
		rotate_a(piles);
	}
	else if (piles->list_a->content < piles->list_a->next->content)
		reverse_a(piles);
	else if (piles->list_a->content > piles->list_a->next->content
		&& piles->list_a->next->content > piles->list_a->next->next->content)
	{
		swap_a(piles);
		reverse_a(piles);
	}
	else if (piles->list_a->content > piles->list_a->next->content
		&& piles->list_a->content > piles->list_a->next->next->content)
		rotate_a(piles);
	else
		swap_a(piles);
	return ;
}

void	sort_four(t_piles *piles)
{
	t_list	*tmp;
	int		i;
	int		min;

	min = find_min(piles, 0, 4);
	tmp = piles->list_a;
	i = find_sens(&tmp, &min, &min);
	if (i < 2)
		while (i--)
			rotate_a(piles);
	else
		while (i++ < 4)
			reverse_a(piles);
	push_b(piles);
	return ;
}

void	before_push_b(t_piles *piles, int size)
{
	int		min;
	int		min_2;
	t_list	*tmp;
	int		i;

	tmp = piles->list_a;
	min = find_min(piles, 0, size);
	min_2 = find_2min(piles, 0, size, min);
	i = find_sens(&tmp, &min, &min_2);
	if (i <= 2)
		while (i--)
			rotate_a(piles);
	else if (i)
		while (i++ < 5)
			reverse_a(piles);
	push_b(piles);
	i = find_sens(&tmp, &min, &min);
	if (i && i <= 2)
		while (--i)
			rotate_a(piles);
	else if (i)
		while (i++ < 5)
			reverse_a(piles);
	return ;
}

void	sort_below_five(t_piles *piles)
{
	if (piles->size == 2)
		swap_a(piles);
	else if (piles->size == 3)
		sort_three(piles);
	else if (piles->size == 4)
	{
		sort_four(piles);
		sort_three(piles);
		push_a(piles);
	}
	else if (piles->size == 5)
	{
		before_push_b(piles, 5);
		push_b(piles);
		if (piles->list_b->content < piles->list_b->next->content)
			swap_b(piles);
		sort_three(piles);
		push_a(piles);
		push_a(piles);
	}
}
