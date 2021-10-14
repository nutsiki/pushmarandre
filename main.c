/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:37:00 by moakouda          #+#    #+#             */
/*   Updated: 2021/10/14 10:37:06 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_piles	*piles;

	piles = init_piles();
	if (argc < 2)
		exit(0);
	piles->list_a = fill_list(argc, argv);
	piles->size = ft_lstsize(piles->list_a);
	piles->sorted = sort_piles(piles);
	if (is_already_sorted(piles))
		return (1);
	if (piles->size <= 5)
		sort_below_five(piles);
	else if (piles->size == 100)
		algo_100(piles);
	else if (piles->size == 500)
		algo_500(piles);
	clean_action(piles);
//	free(piles->action);
	free(piles->list_a);
	free(piles->list_b);
	free(piles->sorted);
	free(piles);
}
