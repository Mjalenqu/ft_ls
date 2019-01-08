/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_flags.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 10:14:37 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/08 14:39:10 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	error_flag(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putchar('\n');
	ft_putendl("usage: ls [-Radfglrtu] [file ...]");
}

int		check_flags_bis(t_flag *flag, char c)
{
	if (c == '1')
	{
		flag->un = 1;
		flag->m = 0;
		flag->l = 0;
	}
	else if (c == 'm')
	{
		flag->un = 0;
		flag->m = 1;
		flag->l = 0;
	}
	else if (c == 'd')
		flag->d = 1;
	else
	{
		error_flag(c);
		return (-1);
	}
	return (1);
}

int		check_flags(t_flag *flag, char c)
{
	flag->nb = 1;
	if (c == 'l')
	{
		flag->l = 1;
		flag->un = 0;
		flag->m = 0;
	}
	else if (c == 'a')
		flag->a = 1;
	else if (c == 'r')
		flag->r = 1;
	else if (c == 'R')
		flag->R = 1;
	else if (c == 't')
		flag->t = 1;
	else if (c == 'u')
		flag->u = 1;
	else if (c == 'f')
		flag->f = 1;
	else if (c == 'g')
		flag->g = 1;
	else if ((check_flags_bis(flag, c)) == -1)
		return (-1);
	return (1);
}
