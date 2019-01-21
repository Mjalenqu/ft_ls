/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 13:47:51 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 19:41:38 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_list(t_lst *lst, char *file, t_flag *flag)
{
	if (flag->er == 1)
		ft_putstr2(file, " :\n");
	while (lst->next != NULL)
	{
		if (lst->type == 'd' && lst->name[0] != '.')
			ft_putcolor2(CYAN, lst->name, RESET, "\t");
		else if (lst->type == 'l' && lst->name[0] != '.')
			ft_putcolor2(PURPLE, lst->name, RESET, "\t");
		else if (lst->name[0] != '.')
			ft_putstr2(lst->name, "\t");
		lst = lst->next;
	}
	if (lst->type == 'd' && lst->name[0] != '.')
		ft_putcolor2(CYAN, lst->name, RESET, "\n");
	else if (lst->type == 'l' && lst->name[0] != '.')
		print_link(lst->name, file);
	else if (lst->name[0] != '.')
		ft_putstr(lst->name);
	ft_putchar('\n');
	if (flag->er != 0)
		ft_putchar('\n');
}

void	print_l(t_lst *lst, char *file)
{
	t_disp disp;

	ft_putstr2(file, " :\n");
	disp = get_total(lst);
	while (lst->next != NULL)
	{
		if (lst->info && lst->name[0] != '.')
			print_stat(lst, disp, file);
		if (lst->type == 'd' && lst->name[0] != '.')
			ft_putcolor2(CYAN, lst->name, RESET, "\n");
		else if (lst->type == 'l' && lst->name[0] != '.')
			print_link(lst->name, file);
		else if (lst->name[0] != '.')
			ft_putstr2(lst->name, "\n");
		lst = lst->next;
	}
	if (lst->info && lst->name[0] != '.')
		print_stat(lst, disp, file);
	if (lst->type == 'l' && lst->name[0] != '.')
		print_link(lst->name, file);
	else if (lst->type == 'd' && lst->name[0] != '.')
		ft_putcolor2(CYAN, lst->name, RESET, "\n");
	else if (lst->name[0] != '.')
		ft_putstr2(lst->name, "\n");
}

void	print_la(t_lst *lst, char *file)
{
	t_disp disp;

	ft_putstr2(file, " :\n");
	disp = get_total_a(lst);
	while (lst->next != NULL)
	{
		if (lst)
			print_stat(lst, disp, file);
		if (lst->type == 'd')
			ft_putcolor2(CYAN, lst->name, RESET, "\n");
		else if (lst->type == 'l')
			print_link(lst->name, file);
		else
			ft_putstr2(lst->name, "\n");
		lst = lst->next;
	}
	if (lst->info && lst->name[0] != '.')
		print_stat(lst, disp, file);
	if (lst->type == 'l' && lst->name[0] != '.')
		print_link(lst->name, file);
	else if (lst->type == 'd' && lst->name[0] != '.')
		ft_putcolor2(CYAN, lst->name, RESET, "\n");
	else if (lst->name[0] != '.')
		ft_putstr2(lst->name, "\n");
}

void	print_un(t_lst *lst, char *file, t_flag *flag)
{
	if (flag->er == 1)
		ft_putstr2(file, " :\n");
	while (lst->next != NULL)
	{
		if (lst->type == 'd' && lst->name[0] != '.')
			ft_putcolor2(CYAN, lst->name, RESET, "\n");
		else if (lst->type == 'l' && lst->name[0] != '.')
			ft_putcolor2(PURPLE, lst->name, RESET, "\n");
		else if (lst->name[0] != '.')
			ft_putstr2(lst->name, "\n");
		lst = lst->next;
	}
	if (lst->type == 'd' && lst->name[0] != '.')
		ft_putcolor2(CYAN, lst->name, RESET, "\n");
	else if (lst->type == 'l' && lst->name[0] != '.')
		ft_putcolor2(PURPLE, lst->name, RESET, "\n");
	else if (lst->name[0] != '.')
		ft_putstr2(lst->name, "\n");
}

void	print_m(t_lst *lst, char *file, t_flag *flag)
{
	if (flag->er == 1)
		ft_putstr2(file, " :\n");
	while (lst->next != NULL)
	{
		if (lst->type == 'd' && lst->name[0] != '.')
			ft_putcolor2(CYAN, lst->name, RESET, ", ");
		else if (lst->type == 'l' && lst->name[0] != '.')
			ft_putcolor2(PURPLE, lst->name, RESET, ", ");
		else if (lst->name[0] != '.')
			ft_putstr2(lst->name, ", ");
		lst = lst->next;
	}
	if (lst->type == 'd' && lst->name[0] != '.')
		ft_putcolor2(CYAN, lst->name, RESET, "\n");
	else if (lst->type == 'l' && lst->name[0] != '.')
		ft_putcolor2(PURPLE, lst->name, RESET, "\n");
	else if (lst->name[0] != '.')
		ft_putstr2(lst->name, "\n");
}
