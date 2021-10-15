/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:43:40 by moakouda          #+#    #+#             */
/*   Updated: 2021/10/14 10:43:43 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_fusion(int cpt, int old_cpt, char *buffer)
{
	char	action;

	action = *buffer;
	if (*buffer == *(buffer + 1))
		rrr_fusion(cpt, old_cpt, buffer);
	else if (action == 's')
		ss_fusion(cpt, old_cpt, buffer);
	else if (action == 'r')
		rr_fusion(cpt, old_cpt, buffer);
}

char	*make_previous(t_piles *piles, char *str)
{
	char	*previous;

	if (str)
		free(str);
	previous = ft_calloc(sizeof(char), 5);
	if (!previous)
		exit(1);
	str = previous;
	while (piles->action && *piles->action != '\n')
		*previous++ = *piles->action++;
	*previous = '\n';
	piles->action++;
	return (str);
}

int	find_fusion(t_piles *piles, char *str, int cpt, int *old_cpt)
{
	if (str && !*old_cpt && (*str != *piles->action || *piles->action == 'p'
			|| (*(str + 1) == 'r' && *(piles->action + 1) != 'r')
			|| ((*(piles->action + 1) == 'r' && *(str + 1) != 'r'))))
	{
		while (cpt--)
			write(1, str, ft_strlen(str));
		cpt = 1;
	}
	else if (str && (strncmp(piles->action, str, 3) == -1
			|| strncmp(piles->action, str, 3) == 1) && (*piles->action == *str))
	{
		*old_cpt = cpt;
		cpt = 1;
	}
	else if (*old_cpt)
	{
		write_fusion(cpt, *old_cpt, str);
		*old_cpt = 0;
		cpt = 1;
	}
	return (cpt);
}

void	clean_action(t_piles *piles)
{
	int		cpt;
	int		old_cpt;
	char	*str;
	char	*tmp;

	cpt = 1;
	old_cpt = 0;
	str = NULL;
	tmp = piles->action;
	while (*piles->action)
	{
		if (str && !ft_strncmp(piles->action, str, 3))
			cpt++;
		else
			cpt = find_fusion(piles, str, cpt, &old_cpt);
		str = make_previous(piles, str);
		if (!*piles->action)
			while (cpt--)
				write(1, str, 3);
	}
	if (str)
		free(str);
	free(tmp);
	return ;
}
