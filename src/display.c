/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/07 10:10:08 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/08 1'd':'d'1:38 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_list(t_lst *lst, char *file, t_flag *flag)
{
	if (flag->R == 1)
		ft_putstr2(file, " :\n");
	while (lst->next != NULL)
	{
		if (lst->type == 'd' && lst->name[0] != '.')
		{
			ft_putcolor(CYAN, lst->name, RESET);
			ft_putstr("\t");
		}
		else if (lst->type == 'l' && lst->name[0] != '.')
			ft_putcolor(PURPLE, lst->name, RESET);
		else if (lst->name[0] != '.')
			ft_putstr2(lst->name, "\t");
		lst = lst->next;
	}
	if (lst->name[0] != '.')
		ft_putstr(lst->name);
	ft_putchar('\n');
}

void	print_l(t_lst *lst, char *file, t_flag *flag)
{
	t_disp disp;

	if (flag->R == 1)
		ft_putstr2(file, " :\n");
	disp = get_total(lst);
	while (lst->next != NULL)
	{
		if (lst->info && lst->name[0] != '.')
			print_stat(lst, disp);
		if (lst->type == 'd' && lst->name[0] != '.')
		{
			ft_putcolor(CYAN, lst->name, RESET);
			ft_putstr("\n");
		}
		else if (lst->type == 'l' && lst->name[0] != '.')
			ft_putcolor(PURPLE, lst->name, RESET);
		else if (lst->name[0] != '.')
			ft_putstr2(lst->name, "\n");
		lst = lst->next;
	}
	if (lst->info && lst->name[0] != '.')
		print_stat(lst, disp);
	if (lst->name[0] != '.')
		ft_putstr(lst->name);
	ft_putchar('\n');
}

void	print_la(t_lst *lst, char *file, t_flag *flag)
{
	t_disp disp;

	if (flag->R == 1)
		ft_putstr2(file, " :\n");
	disp = get_total(lst);
	while (lst->next != NULL)
	{
		if (lst)
			print_stat(lst, disp);
		if (lst->type == 'd')
		{
			ft_putcolor(CYAN, lst->name, RESET);
			ft_putstr("\n");
		}
		else
			ft_putstr2(lst->name, "\n");
		lst = lst->next;
	}
	if (lst->info && lst->name[0] != '.')
		print_stat(lst, disp);
	if (lst->name[0] != '.')
		ft_putstr(lst->name);
	ft_putchar('\n');
}

void	print_un(t_lst *lst, char *file, t_flag *flag)
{
	if (flag->R == 1)
		ft_putstr2(file, " :\n");
	while (lst->next != NULL)
	{
		if (lst->type == 'd' && lst->name[0] != '.')
		{
			ft_putcolor(CYAN, lst->name, RESET);
			ft_putstr("\n");
		}
		else if (lst->type == 'l' && lst->name[0] != '.')
			ft_putcolor(PURPLE, lst->name, RESET);
		else if (lst->name[0] != '.')
			ft_putstr2(lst->name, "\n");
		lst = lst->next;
	}
	if (lst->name[0] != '.')
		ft_putstr(lst->name);
	ft_putchar('\n');
}

void	print_m(t_lst *lst, char *file, t_flag *flag)
{
	if (flag->R == 1)
		ft_putstr2(file, " :\n");
	while (lst->next != NULL)
	{
		if (lst->type == 'd' && lst->name[0] != '.')
		{
			ft_putcolor(CYAN, lst->name, RESET);
			ft_putstr(", ");
		}
		else if (lst->type == 'l' && lst->name[0] != '.')
			ft_putcolor(PURPLE, lst->name, RESET);
		else if (lst->name[0] != '.')
			ft_putstr2(lst->name, ", ");
		lst = lst->next;
	}
	if (lst->name[0] != '.')
		ft_putstr(lst->name);
	ft_putchar('\n');
}
