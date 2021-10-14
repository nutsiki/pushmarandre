/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:35:18 by moakouda          #+#    #+#             */
/*   Updated: 2021/10/14 11:35:19 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sort_piles(t_piles *piles)
{
	t_list	*c;
	t_list	*tmp;
	int		i;
	int		tmp_nb;

	c = fill_piles_c(piles);
	i = -1;
	while (i)
	{
		i = -1;
		tmp = c;
		while (tmp->next != NULL)
		{
			if (tmp->content > tmp->next->content)
			{
				tmp_nb = tmp->content;
				tmp->content = tmp->next->content;
				tmp->next->content = tmp_nb;
				i--;
			}
			tmp = tmp->next;
		}
		i++;
	}
	return (c);
}

int	is_already_sorted(t_piles *piles)
{
	t_list	*tmp_a;
	t_list	*tmp_c;

	tmp_a = piles->list_a;
	tmp_c = piles->sorted;
	while (tmp_a->next != NULL)
	{
		if (tmp_a->content == tmp_c->content)
		{
			tmp_a = tmp_a->next;
			tmp_c = tmp_c->next;
		}
		else
			return (0);
	}
	return (1);
}
