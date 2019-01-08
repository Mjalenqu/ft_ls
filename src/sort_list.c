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

void	lst_sort_time(t_lst **lst)
{
	//printf("OK");
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
	if (flag->t != 0)
		lst_sort_time(lst);
	if (flag->r == 0)
		lst_sort_ascii(lst);
	else
		lst_sort_reverse(lst);
}
/*
int        sortt(t_ls *during, t_ls *last)
{
    int            i;
    struct stat    *sduring;
    struct stat    *slast;

    sduring = malloc(sizeof(struct stat));
    slast = malloc(sizeof(struct stat));
    i = 0;
    if (stat(during->path, sduring) < 0)
    {
        perror("during");
        return (-2);
    }
    if (stat(last->path, slast) < 0)
    {
        perror("last");
        return (-2);
    }
    if (sduring->st_mtime < slast->st_mtime)
        return (-1);
    else if (sduring->st_mtime > slast->st_mtime)
        return (1);
    else
        return (0);
}*/
