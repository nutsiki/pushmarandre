/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <moakouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:02:32 by moakouda          #+#    #+#             */
/*   Updated: 2021/10/15 22:46:35 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_piles	*push_b(t_piles *piles)
{
	t_list	*tmp_lsta;
	t_list	*new;
	t_list	*tmp_lstb;
	int		tmp;

	if (piles->list_a == NULL)
		return (piles);
	tmp_lsta = piles->list_a;
	tmp_lstb = piles->list_b;
	new = NULL;
	tmp = piles->list_a->content;
	new = ft_lstnew(tmp);
	piles->list_b = new;
	piles->list_b->next = tmp_lstb;
	piles->list_a = tmp_lsta->next;
	free(tmp_lsta);
	fill_buffer_str("pb\n", piles);
	return (piles);
}

t_piles	*push_a(t_piles *piles)
{
	t_list	*tmp_lsta;
	t_list	*new;
	t_list	*tmp_lstb;
	int		tmp;

	if (piles->list_b == NULL)
		return (piles);
	new = NULL;
	tmp_lstb = piles->list_b;
	tmp_lsta = piles->list_a;
	tmp = piles->list_b->content;
	new = ft_lstnew(tmp);
	piles->list_a = new;
	piles->list_a->next = tmp_lsta;
	piles->list_b = tmp_lstb->next;
	free(tmp_lstb);
	fill_buffer_str("pa\n", piles);
	return (piles);
}
