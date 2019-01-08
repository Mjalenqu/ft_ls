/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_struct.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/02 10:54:37 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/02 13:48:21 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_flag	*init_flag(t_flag *flag)
{
	flag->nb = 1;
	flag->a = 0;
	flag->r = 0;
	flag->R = 0;
	flag->l = 0;
	flag->t = 0;
	flag->u = 0;
	flag->f = 0;
	flag->g = 0;
	flag->d = 0;
	flag->m = 0;
	flag->un = 0;
	return (flag);
}
