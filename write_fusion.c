/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_fusion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:58:30 by moakouda          #+#    #+#             */
/*   Updated: 2021/10/14 10:58:32 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr_fusion(int cpt, int old_cpt, char *buffer)
{
	while (cpt && old_cpt)
	{
		write(1, "rrr\n", 4);
		cpt--;
		old_cpt--;
	}
	if (*(buffer + 2) == 'a')
	{
		while (cpt--)
			write(1, buffer, 4);
		while (old_cpt--)
			write(1, "rrb\n", 4);
	}
	else
	{
		while (cpt--)
			write(1, buffer, 4);
		while (old_cpt--)
			write(1, "rra\n", 4);
	}
}

void	ss_fusion(int cpt, int old_cpt, char *buffer)
{
	while (cpt && old_cpt)
	{
		write(1, "ss\n", 3);
		cpt--;
		old_cpt--;
	}
	if (*(buffer + 1) == 'a')
	{
		while (cpt--)
			write(1, buffer, 3);
		while (old_cpt--)
			write(1, "sb\n", 3);
	}
	else
	{
		while (cpt--)
			write(1, buffer, 3);
		while (old_cpt--)
			write(1, "sa\n", 3);
	}
}

void	rr_fusion(int cpt, int old_cpt, char *buffer)
{
	while (cpt && old_cpt)
	{
		write(1, "rr\n", 3);
		cpt--;
		old_cpt--;
	}
	if (*(buffer + 1) == 'a')
	{
		while (cpt--)
			write(1, buffer, 3);
		while (old_cpt--)
			write(1, "rb\n", 3);
	}
	else
	{
		while (cpt--)
			write(1, buffer, 3);
		while (old_cpt--)
			write(1, "ra\n", 3);
	}
}
