/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_option.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 13:44:20 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 13:26:10 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_ma(t_lst *lst, char *file, t_flag *flag)
{
	if (flag->er == 1)
		ft_putstr2(file, " :\n");
	while (lst->next != NULL)
	{
		if (lst->type == 'd')
		{
			ft_putcolor(CYAN, lst->name, RESET);
			ft_putstr(" ,");
		}
		else if (lst->type == 'l')
			ft_putcolor2(PURPLE, lst->name, RESET, ", ");
		else
			ft_putstr2(lst->name, ", ");
		lst = lst->next;
	}
	if (lst->type == 'd' && lst->name[0] != '.')
		ft_putcolor2(CYAN, lst->name, RESET, "\n");
	else if (lst->type == 'l' && lst->name[0] != '.')
		ft_putcolor(PURPLE, lst->name, RESET);
	else if (lst->name[0] != '.')
		ft_putstr(lst->name);
	ft_putchar('\n');
}

void	print_una(t_lst *lst, char *file, t_flag *flag)
{
	if (flag->er == 1)
		ft_putstr2(file, " :\n");
	while (lst->next != NULL)
	{
		if (lst->type == 'd')
			ft_putcolor2(CYAN, lst->name, RESET, "\n");
		else if (lst->type == 'l')
			ft_putcolor2(PURPLE, lst->name, RESET, "\n");
		else
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

void	print_laaa(t_lst *lst, char *file)
{
	t_disp disp;

	ft_putstr2(file, " :\n");
	disp = get_total_a(lst);
	while (lst->next != NULL)
	{
		if (lst && lst->name[1] != '.' && lst->name[1] != '\0')
			print_stat(lst, disp, file);
		if (lst->type == 'd' && lst->name[1] != '.' && lst->name[1] != '\0')
			ft_putcolor2(CYAN, lst->name, RESET, "\n");
		else if (lst->type == 'l' &&
					lst->name[1] != '.' && lst->name[1] != '\0')
			print_link(lst->name, file);
		else if (lst->name[1] != '.' && lst->name[1] != '\0')
			ft_putstr2(lst->name, "\n");
		lst = lst->next;
	}
	if (lst->info && lst->name[1] != '.' && lst->name[1] != '\0')
		print_stat(lst, disp, file);
	if (lst->type == 'l' && lst->name[1] != '.' && lst->name[1] != '\0')
		print_link(lst->name, file);
	else if (lst->type == 'd' && lst->name[1] != '.' && lst->name[1] != '\0')
		ft_putcolor2(CYAN, lst->name, RESET, "\n");
	else if (lst->name[1] != '.' && lst->name[1] != '\0')
		ft_putstr2(lst->name, "\n");
}

void	print_aaa(t_lst *lst, char *file, t_flag *flag)
{
	if (flag->er == 1)
		ft_putstr2(file, " :\n");
	while (lst->next != NULL)
	{
		if (lst->type == 'd' && lst->name[1] != '.' && lst->name[1] != '\0')
			ft_putcolor2(CYAN, lst->name, RESET, "  ");
		else if (lst->type == 'l' && lst->name[1] != '.'
				&& lst->name[1] != '\0')
			ft_putcolor2(PURPLE, lst->name, RESET, "  ");
		else if (lst->name[1] != '.' && lst->name[1] != '\0')
			ft_putstr2(lst->name, "  ");
		lst = lst->next;
	}
	if (lst->type == 'd' && lst->name[1] != '.' && lst->name[1] != '\0')
		ft_putcolor2(CYAN, lst->name, RESET, "\n");
	else if (lst->type == 'l' && lst->name[1] != '.' && lst->name[1] != '\0')
		ft_putcolor2(PURPLE, lst->name, RESET, "\n");
	else if (lst->name[0] != '.')
		ft_putstr2(lst->name, "\n");
}
