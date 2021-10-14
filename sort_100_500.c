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

void	algo_100(t_piles *piles)
{
	int	i;

	i = 0;
	while (i++ < 20)
		make_chunk(piles, ft_lstsize(piles->list_a), 19);
	clean_b(piles, find_max(piles, 0, 20), 20);
	while (i++ < 41)
		make_chunk(piles, ft_lstsize(piles->list_a), 39);
	clean_b(piles, find_max(piles, 0, 40), 40);
	while (i++ < 62)
		make_chunk(piles, ft_lstsize(piles->list_a), 59);
	clean_b(piles, find_max(piles, 0, 60), 60);
	while (i++ < 83)
		make_chunk(piles, ft_lstsize(piles->list_a), 79);
	clean_b(piles, find_max(piles, 0, 80), 80);
	while (i++ < 101)
		make_chunk(piles, ft_lstsize(piles->list_a), 96);
	clean_b(piles, find_max(piles, 0, 97), 97);
	sort_three(piles);
	while (piles->list_b)
		push_a(piles);
	return ;
}
