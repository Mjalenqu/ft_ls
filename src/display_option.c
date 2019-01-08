/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_option.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/07 13:19:08 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/08 1'd':39:'d'9 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_ma(t_lst *lst, char *file, t_flag *flag)
{
	if (flag->R == 1)
		ft_putstr2(file, " :\n");
	while (lst->next != NULL)
	{
		if (lst->type == 'd')
		{
			ft_putcolor(CYAN, lst->name, RESET);
			ft_putstr(" ,");
		}
		else if (lst->type == 'l')
			ft_putcolor(PURPLE, lst->name, RESET);
		else
			ft_putstr2(lst->name, ", ");
		lst = lst->next;
	}
	if (lst->name[0] != '.')
		ft_putstr(lst->name);
	ft_putchar('\n');
}

void	print_una(t_lst *lst, char *file, t_flag *flag)
{
	if (flag->R == 1)
		ft_putstr2(file, " :\n");
	while (lst->next != NULL)
	{
		if (lst->type == 'd')
		{
			ft_putcolor(CYAN, lst->name, RESET);
			ft_putstr("\n");
		}
		else if (lst->type == 'l')
			ft_putcolor(PURPLE, lst->name, RESET);
		else
			ft_putstr2(lst->name, "\n");
		lst = lst->next;
	}
	if (lst->name[0] != '.')
		ft_putstr(lst->name);
	ft_putchar('\n');
}
