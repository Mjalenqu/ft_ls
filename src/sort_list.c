/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort_list.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/08 09:04:17 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 17:45:36 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_lst	*lst_swap(t_lst *p1, t_lst *p2)
{
	p1->next = p2->next;
	p2->next = p1;
	return (p2);
}

void	lst_sort_ascii(t_lst **lst)
{
	if (!(*lst))
		return ;
	if ((*lst)->next && ft_strcmp((*lst)->name, (*lst)->next->name) > 0)
		*lst = lst_swap(*lst, (*lst)->next);
	lst_sort_ascii(&(*lst)->next);
	if ((*lst)->next && ft_strcmp((*lst)->name, (*lst)->next->name) > 0)
	{
		*lst = lst_swap(*lst, (*lst)->next);
		lst_sort_ascii(&(*lst)->next);
	}
}

t_lst	*sort_r(t_lst **lst)
{
	t_lst	*sorted;
	t_lst	*tmp;

	sorted = NULL;
	while (*lst)
	{
		tmp = (*lst)->next;
		(*lst)->next = sorted;
		sorted = *lst;
		*lst = tmp;
	}
	return (sorted);
}

void	lst_sort_time(t_lst **lst)
{
	if (!(*lst))
		return ;
	if ((*lst)->next && (*lst)->sec < (*lst)->next->sec)
		*lst = lst_swap(*lst, (*lst)->next);
	lst_sort_time(&(*lst)->next);
	if ((*lst)->next && (*lst)->sec < (*lst)->next->sec)
	{
		*lst = lst_swap(*lst, (*lst)->next);
		lst_sort_time(&(*lst)->next);
	}
}

void	lst_sort(t_lst **lst, t_flag *flag)
{
	lst_sort_ascii(lst);
	if (flag->t != 0)
		lst_sort_time(lst);
}
