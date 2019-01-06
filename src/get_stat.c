/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_stat.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 11:15:48 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/06 16:06:47 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_stat(t_info *st)
{
	ft_putchar(st->type);
	print_right(st->rwx);
	ft_putchar(' ');
	ft_putnbr(st->link);
	ft_putchar(' ');
	ft_putstr2(st->login, " ");
	ft_putstr2(st->group, " ");
	ft_putnbr(st->octet);
	ft_putchar(' ');
	ft_putstr2(st->time, " ");
}
