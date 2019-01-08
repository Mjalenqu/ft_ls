/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_stat.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 11:15:48 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/08 14:41:02 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_disp	get_total(t_lst *lst)
{
	t_lst	*save;
	t_disp	disp;
	int		total;

	save = lst;
	total = 0;
	disp.max_log = ft_strlen(lst->info->login);
	disp.max_grp = ft_strlen(lst->info->group);
	disp.max_len = ft_strlen(lst->info->octet);
	disp.max_lnk = ft_strlen(lst->info->link);
	while (lst)
	{
		total += lst->info->blk;
		if (ft_strlen(lst->info->login) > disp.max_log)
			disp.max_log = ft_strlen(lst->info->login);
		if (ft_strlen(lst->info->group) > disp.max_grp)
			disp.max_grp = ft_strlen(lst->info->group);
		if (ft_strlen(lst->info->octet) > disp.max_len)
			disp.max_len = ft_strlen(lst->info->octet);
		if (ft_strlen(lst->info->link) > disp.max_lnk)
			disp.max_lnk = ft_strlen(lst->info->link);
		lst->log = ft_strlen(lst->info->login);
		lst->grp = ft_strlen(lst->info->group);
		lst->len = ft_strlen(lst->info->octet);
		lst->lnk = ft_strlen(lst->info->link);
		lst = lst->next;
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putchar('\n');
	return (disp);
}

void	print_stat(t_lst *lst, t_disp disp)
{
	ft_putchar(lst->info->type);
	print_right(lst->info->rwx);
	ft_putchar(' ');
	while (disp.max_lnk > lst->lnk)
	{
		ft_putchar(' ');
		lst->lnk += 1;
	}
	ft_putstr2(lst->info->link, " ");
	ft_putstr2(lst->info->login, " ");
	while (disp.max_log > lst->log)
	{
		ft_putchar(' ');
		lst->log += 1;
	}
	ft_putstr2(lst->info->group, " ");
	while (disp.max_grp > lst->grp)
	{
		ft_putchar(' ');
		lst->grp += 1;
	}
	while (disp.max_len > lst->len)
	{
		ft_putchar(' ');
		lst->len += 1;
	}
	ft_putstr2(lst->info->octet, " ");
	ft_putstr2(lst->info->time, " ");
}
