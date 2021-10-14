/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:07:21 by moakouda          #+#    #+#             */
/*   Updated: 2021/10/14 13:07:23 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_piles	*rotate_a(t_piles *piles)
{
	t_list	*tmp_lst;
	int		tmp;

	tmp_lst = piles->list_a;
	if (tmp_lst == NULL || tmp_lst->next == NULL)
		return (piles);
	tmp = tmp_lst->content;
	piles->list_a = tmp_lst->next;
	while (tmp_lst->next != NULL)
		tmp_lst = tmp_lst->next;
	tmp_lst->next = ft_lstnew(tmp);
	fill_buffer_str("ra\n", piles);
	return (piles);
}

t_piles	*rotate_b(t_piles *piles)
{
	t_list	*tmp_lst;
	int		tmp;

	tmp_lst = piles->list_b;
	if (tmp_lst == NULL || tmp_lst->next == NULL)
		return (piles);
	tmp = tmp_lst->content;
	piles->list_b = tmp_lst->next;
	while (tmp_lst->next != NULL)
		tmp_lst = tmp_lst->next;
	tmp_lst->next = ft_lstnew(tmp);
	fill_buffer_str("rb\n", piles);
	return (piles);
}
