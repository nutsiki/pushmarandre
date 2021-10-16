/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:06:07 by moakouda          #+#    #+#             */
/*   Updated: 2021/10/14 11:06:09 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define BUFFER_SIZE 1000
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

typedef struct s_piles
{
	t_list			*list_a;
	t_list			*list_b;
	t_list			*sorted;
	int				size;
	char			*action;
	int				pos;
	int				length;
}					t_piles;

int		ft_atoi(const char *str);

t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);

size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);

char	*ft_putstr_fd_err(char *s, int fd);
t_piles	*fill_buffer(t_piles *piles, char action);
int		fill_buffer_str(char *str, t_piles *piles);

t_piles	*reverse_a(t_piles *piles);
t_piles	*reverse_b(t_piles *piles);

t_piles	*rotate_a(t_piles *piles);
t_piles	*rotate_b(t_piles *piles);

t_piles	*push_a(t_piles *piles);
t_piles	*push_b(t_piles *piles);

t_piles	*swap_a(t_piles *piles);
t_piles	*swap_b(t_piles *piles);
t_piles	*init_piles(void);

t_list	*fill_piles_c(t_piles *piles);
t_list	*fill_list(int argc, char **argv);

t_list	*sort_piles(t_piles *piles);
int		is_already_sorted(t_piles *piles);

int		find_max(t_piles *piles, int i, int j);
int		find_min(t_piles *piles, int i, int j);
int		find_2min(t_piles *piles, int i, int j, int min);
int		find_sens(t_list **tmp, int *min, int *min_2);

void	make_chunk(t_piles *piles, int size, int index);

void	algo_other(t_piles *piles, int size, int fifth);
void	algo_100(t_piles *piles);
void	algo_500(t_piles *piles);

void	sort_below_five(t_piles *piles);
void	sort_three(t_piles *piles);

void	clean_action(t_piles *piles);

void	rr_fusion(int cpt, int old_cpt, char *buffer);
void	ss_fusion(int cpt, int old_cpt, char *buffer);
void	rrr_fusion(int cpt, int old_cpt, char *buffer);

#endif
