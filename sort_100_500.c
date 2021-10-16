/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_500.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:08:23 by moakouda          #+#    #+#             */
/*   Updated: 2021/10/14 15:08:25 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_b(t_piles *piles, int max, int size)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = piles->list_b;
	while (tmp && tmp->content != max)
	{
		tmp = tmp->next;
		i++;
	}
	if (i < (size / 2))
		while (i--)
			rotate_b(piles);
	else
		while (i++ < size)
			reverse_b(piles);
	return ;
}

void	algo_500_bis(t_piles *piles, int i)
{
	while (i++ < 271)
		make_chunk(piles, ft_lstsize(piles->list_a), 265);
	clean_b(piles, find_max(piles, 0, 266), 266);
	while (i++ < 318)
		make_chunk(piles, ft_lstsize(piles->list_a), 311);
	clean_b(piles, find_max(piles, 0, 312), 312);
	while (i++ < 365)
		make_chunk(piles, ft_lstsize(piles->list_a), 357);
	clean_b(piles, find_max(piles, 0, 358), 358);
	while (i++ < 412)
		make_chunk(piles, ft_lstsize(piles->list_a), 403);
	clean_b(piles, find_max(piles, 0, 404), 404);
	while (i++ < 459)
		make_chunk(piles, ft_lstsize(piles->list_a), 449);
	clean_b(piles, find_max(piles, 0, 450), 450);
	while (i++ < 507)
		make_chunk(piles, ft_lstsize(piles->list_a), 496);
	clean_b(piles, find_max(piles, 0, 497), 497);
}

void	algo_500(t_piles *piles)
{
	int	i;

	i = 0;
	while (i++ < 46)
		make_chunk(piles, ft_lstsize(piles->list_a), 45);
	clean_b(piles, find_max(piles, 0, 46), 46);
	while (i++ < 93)
		make_chunk(piles, ft_lstsize(piles->list_a), 91);
	clean_b(piles, find_max(piles, 0, 92), 92);
	while (i++ < 140)
		make_chunk(piles, ft_lstsize(piles->list_a), 137);
	clean_b(piles, find_max(piles, 0, 138), 138);
	while (i++ < 177)
		make_chunk(piles, ft_lstsize(piles->list_a), 173);
	clean_b(piles, find_max(piles, 0, 174), 174);
	while (i++ < 224)
		make_chunk(piles, ft_lstsize(piles->list_a), 219);
	clean_b(piles, find_max(piles, 0, 220), 220);
	algo_500_bis(piles, i);
	sort_three(piles);
	while (piles->list_b)
		push_a(piles);
	return ;
}

void	algo_other(t_piles *piles, int size, int fifth)
{
	int	i;

	i = 0;
	while (i++ < (fifth * 1))
		make_chunk(piles, ft_lstsize(piles->list_a), (fifth * 1) - 1);
	clean_b(piles, find_max(piles, 0, fifth * 1), fifth * 1);
	while (i++ < (fifth * 2) + 1)
		make_chunk(piles, ft_lstsize(piles->list_a), (fifth * 2) - 1);
	clean_b(piles, find_max(piles, 0, fifth * 2), fifth * 2);
	while (i++ < (fifth * 3) + 2)
		make_chunk(piles, ft_lstsize(piles->list_a), (fifth * 3) - 1);
	clean_b(piles, find_max(piles, 0, fifth * 3), fifth * 3);
	while (i++ < (fifth * 4) + 3)
		make_chunk(piles, ft_lstsize(piles->list_a), (fifth * 4) - 1);
	clean_b(piles, find_max(piles, 0, fifth * 4), fifth * 4);
	while (i++ < size - 3 + 4)
		make_chunk(piles, ft_lstsize(piles->list_a), size - 3 - 1);
	clean_b(piles, find_max(piles, 0, size - 3), size - 3);
	if (ft_lstsize(piles->list_a) == 3)
		sort_three(piles);
	else if (piles->list_a->next
		&& piles->list_a->next->content < piles->list_a->content)
		swap_a(piles);
	return ;
}
