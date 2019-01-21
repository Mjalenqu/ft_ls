/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_stat.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 11:15:48 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 19:42:25 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_disp	get_total(t_lst *lst)
{
	t_disp	disp;
	int		total;

	total = 0;
	disp.max_log = ft_strlen(lst->info->login);
	disp.max_grp = ft_strlen(lst->info->group);
	disp.max_len = ft_strlen(lst->info->octet);
	disp.max_lnk = ft_strlen(lst->info->link);
	while (lst)
	{
		if (lst->name[0] != '.')
			total += lst->info->blk;
		lst->log = ft_strlen(lst->info->login);
		lst->grp = ft_strlen(lst->info->group);
		lst->len = ft_strlen(lst->info->octet);
		lst->lnk = ft_strlen(lst->info->link);
		disp.max_log = (lst->log > disp.max_log) ? lst->log : disp.max_log;
		disp.max_grp = (lst->grp > disp.max_grp) ? lst->grp : disp.max_grp;
		disp.max_len = (lst->len > disp.max_len) ? lst->len : disp.max_len;
		disp.max_lnk = (lst->lnk > disp.max_lnk) ? lst->lnk : disp.max_lnk;
		lst = lst->next;
	}
	ft_putsnb("total ", total, "\n");
	return (disp);
}

t_disp	get_total_a(t_lst *lst)
{
	t_disp	disp;
	int		total;

	total = 0;
	disp.max_log = ft_strlen(lst->info->login);
	disp.max_grp = ft_strlen(lst->info->group);
	disp.max_len = ft_strlen(lst->info->octet);
	disp.max_lnk = ft_strlen(lst->info->link);
	while (lst)
	{
		total += lst->info->blk;
		lst->log = ft_strlen(lst->info->login);
		lst->grp = ft_strlen(lst->info->group);
		lst->len = ft_strlen(lst->info->octet);
		lst->lnk = ft_strlen(lst->info->link);
		disp.max_log = (lst->log > disp.max_log) ? lst->log : disp.max_log;
		disp.max_grp = (lst->grp > disp.max_grp) ? lst->grp : disp.max_grp;
		disp.max_len = (lst->len > disp.max_len) ? lst->len : disp.max_len;
		disp.max_lnk = (lst->lnk > disp.max_lnk) ? lst->lnk : disp.max_lnk;
		lst = lst->next;
	}
	ft_putsnb("total ", total, "\n");
	return (disp);
}

void	print_min(int maj, char *s, int min)
{
	if (maj < 10)
		ft_putchar(' ');
	ft_putnbr(maj);
	ft_putstr(s);
	if (min > 9 && min < 100)
		ft_putstr(" ");
	else if (min < 10)
		ft_putstr("  ");
	ft_putnbr(min);
	ft_putchar(' ');
}

void	print_space(int max, int size)
{
	while (size < max)
	{
		ft_putchar(' ');
		size++;
	}
}

void	print_stat(t_lst *lst, t_disp disp, char *file)
{
	static int i = 0;

	ft_putchar(lst->type);
	get_right(lst->info->rwx);
	get_acl(file, lst->name);
	ft_putchar(' ');
	print_space(disp.max_lnk, lst->lnk);
	ft_putcolor2(lst->info->link, " ", lst->info->login, " ");
	print_space(disp.max_log, lst->log);
	ft_putstr2(lst->info->group, " ");
	print_space(disp.max_grp, lst->grp);
	if (lst->type == 'c' || lst->type == 'b')
	{
		print_min(lst->info->maj, ", ", lst->info->min);
		i = 1;
	}
	else
	{
		if (i == 1)
			ft_putstr("  ");
		print_space(disp.max_len, lst->len);
		ft_putcolor(" ", lst->info->octet, " ");
	}
	ft_putstr2(lst->info->time, " ");
}
