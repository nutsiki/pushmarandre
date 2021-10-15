/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_piles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:21:42 by moakouda          #+#    #+#             */
/*   Updated: 2021/10/14 11:21:44 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_list(int i, char **argv, int *tab)
{
	int	j;
	int	nb;

	j = 0;
	while (ft_isdigit(argv[i][j]) || ((argv[i][j] == '+' || argv[i][j] == '-')
			&& j == 0))
		j++;
	if ((size_t)j != ft_strlen(argv[i]))
		ft_putstr_fd_err("Error\n", 2);
	nb = ft_atoi(argv[i]);
	if (nb > 2147483647 || nb < -2147483648)
		ft_putstr_fd_err("Error\n", 2);
	j = -1;
	while (tab[++j])
		if (tab[j] == nb)
			ft_putstr_fd_err("Error\n", 2);
	return (nb);
}

t_list	*fill_list(int argc, char **argv)
{
	int		i;
	int		*tab;
	t_list	*new;
	t_list	*tmp;

	i = argc - 1;
	new = NULL;
	tmp = NULL;
	tab = ft_calloc(argc - 1, sizeof(int));
	while (i > 0)
	{
		tab[(argc - 1) - i] = check_list(i, argv, tab);
		new = ft_lstnew(tab[(argc - 1) - i]);
		new->next = tmp;
		tmp = new;
		i--;
	}
	free(tab);
	return (tmp);
}

t_list	*fill_piles_c(t_piles *piles)
{
	t_list	*c;
	t_list	*tmp_a;

	c = NULL;
	tmp_a = piles->list_a;
	while (tmp_a != NULL)
	{
		ft_lstadd_back(&c, ft_lstnew(tmp_a->content));
		tmp_a = tmp_a->next;
	}
	return (c);
}

t_piles	*init_piles(void)
{
	t_piles	*piles;

	piles = (t_piles *)malloc(sizeof(t_piles));
	if (!piles)
		exit(1);
	ft_bzero(piles, sizeof(t_piles));
	piles->action = ft_calloc(sizeof(char), BUFFER_SIZE);
	piles->pos = 0;
	piles->length = BUFFER_SIZE;
	return (piles);
}
