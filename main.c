/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <moakouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:37:00 by moakouda          #+#    #+#             */
/*   Updated: 2021/10/15 22:49:14 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_piles(t_piles *piles)
{
	t_list	*tmp;

	while (piles->list_a)
	{
		tmp = piles->list_a->next;
		free(piles->list_a);
		piles->list_a = tmp;
	}
	while (piles->sorted)
	{
		tmp = piles->sorted->next;
		free(piles->sorted);
		piles->sorted = tmp;
	}
	free(piles);
}

int	main(int argc, char **argv)
{
	t_piles	*piles;

	if (argc < 2)
		return (0);
	piles = init_piles();
	piles->list_a = fill_list(argc, argv);
	piles->size = ft_lstsize(piles->list_a);
	piles->sorted = sort_piles(piles);
	if (is_already_sorted(piles))
	{
		free_piles(piles);
		return (0);
	}
	if (piles->size <= 5)
		sort_below_five(piles);
	else if (piles->size == 500)
		algo_500(piles);
	else
		algo_other(piles, piles->size, piles->size / 5);
	while (piles->list_b)
		push_a(piles);
	clean_action(piles);
	free_piles(piles);
	return (0);
}
