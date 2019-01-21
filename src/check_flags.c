/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_flags.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 10:14:37 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 18:59:01 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	**sort_argv_rev(char **av, int i)
{
	char	*str;
	int		b;
	int		j;

	j = i;
	while (1)
	{
		b = 0;
		i = j;
		while (av[i + 1])
		{
			if (ft_strcmp(av[i], av[i + 1]) < 0)
			{
				str = av[i];
				av[i] = av[i + 1];
				av[i + 1] = str;
				b = 1;
			}
			i++;
		}
		if (b == 0)
			break ;
	}
	return (av);
}

char	**sort_argv_time(char **av, int i)
{
	char	*str;
	int		b;
	int		j;

	j = i;
	while (1)
	{
		b = 0;
		i = j;
		while (av[i + 1])
		{
			if (get_time(av[i]) < get_time(av[i + 1]))
			{
				str = av[i];
				av[i] = av[i + 1];
				av[i + 1] = str;
				b = 1;
			}
			i++;
		}
		if (b == 0)
			break ;
	}
	return (av);
}

void	error_flag(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putchar('\n');
	ft_putendl("usage: ls [-ARalmrt1] [file ...]");
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
	else if (c == 'A')
		flag->aa = 1;
	else if (c == 'a')
	{
		flag->aa = 0;
		flag->a = 1;
	}
	else if (c == 'r')
		flag->r = 1;
	else if (c == 'R')
		flag->er = 1;
	else if (c == 't')
		flag->t = 1;
	else if ((check_flags_bis(flag, c)) == -1)
		return (-1);
	return (1);
}
