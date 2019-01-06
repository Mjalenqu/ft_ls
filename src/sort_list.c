/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort_list.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/08 09:04:17 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/02 17:09:05 by mjalenqu    ###    #+. /#+    ###.fr     */
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

void	lst_sort_reverse(t_lst **lst)
{
	if (!(*lst))
		return ;
	if ((*lst)->next && ft_strcmp((*lst)->name, (*lst)->next->name) < 0)
		*lst = lst_swap(*lst, (*lst)->next);
	lst_sort_reverse(&(*lst)->next);
	if ((*lst)->next && ft_strcmp((*lst)->name, (*lst)->next->name) < 0)
	{
		*lst = lst_swap(*lst, (*lst)->next);
		lst_sort_reverse(&(*lst)->next);
	}
}

void	lst_sort(t_lst **lst, t_flag *flag)
{
	if (flag->r == 0)
		lst_sort_ascii(lst);
	else
		lst_sort_reverse(lst);
}
