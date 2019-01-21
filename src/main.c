/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/05 11:26:45 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 13:26:22 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_free(t_info *info)
{
	if (info)
	{
		free(info->login);
		free(info->group);
		free(info->time);
		free(info->octet);
		free(info->link);
		free(info);
	}
}

void	print_start(t_info *info, char *file)
{
	ft_putchar(get_type(file));
	get_right(info->rwx);
	ft_putcolor2(" ", info->link, " ", info->login);
	ft_putcolor2(" ", info->group, " ", info->octet);
	ft_putcolor2(" ", info->time, " ", file);
	ft_putchar('\n');
	ft_free(info);
}

int		check_type(char **file, t_flag *flag, int i)
{
	int		j;

	j = 0;
	get_files(file, flag, i);
	while (file[i])
	{
		if (get_type(file[i]) == 0)
			ft_putcolor("./ft_ls: ", file[i], ": No such file or directory\n");
		else if (get_type(file[i]) == 'd')
		{
			if (flag->l == 0)
				ft_putstr2(file[i], ":\n");
			openit(file[i], flag);
		}
		i++;
	}
	return (0);
}

int		start(char **av, t_flag flag, int i, int j)
{
	while (av[i])
	{
		j = ft_check_option(av[i], &flag);
		if (j == -1)
			return (0);
		else if (j == 0)
			break ;
		else if (j == 2)
		{
			i++;
			break ;
		}
		i++;
	}
	if (av[i])
		earth_wind_and_fire(av, i, flag);
	else
		openit(".", &flag);
	return (0);
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	t_flag	flag;

	j = 0;
	i = 1;
	flag = *(init_flag(&flag));
	if (argc == 1)
	{
		openit(".", &flag);
		return (0);
	}
	start(argv, flag, i, j);
	return (0);
}
