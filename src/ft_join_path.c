/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_join_path.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/08 07:38:59 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 07:55:05 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	earth_wind_and_fire(char **av, int i, t_flag flag)
{
	if (av[i + 1])
	{
		av = choose_sort(av, i, &flag);
		check_type(av, &flag, i);
	}
	else
		check_type(av, &flag, i);
}

void	print_link(char *name, char *file)
{
	char	*str;
	char	link[1000];
	int		i;

	str = ft_join_path(file, name);
	i = readlink(str, link, 1000);
	link[i] = '\0';
	free(str);
	ft_putcolor(PURPLE, name, RESET);
	ft_putstr2(" -> ", link);
	ft_putchar('\n');
}

char	*ft_join_path(char *s1, char *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	if (!(s1 && s2))
		return (0);
	i = -1;
	j = 0;
	if (!(dest = (char*)malloc(sizeof(char) *
					(ft_strlen((char*)s1) + ft_strlen((char*)s2) + 2))))
		return (0);
	while (s1[++i])
		dest[i] = s1[i];
	dest[i] = '/';
	i++;
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**choose_sort(char **av, int i, t_flag *flag)
{
	av = sort_argv(av, i);
	if (flag->t != 0)
		av = sort_argv_time(av, i);
	if (flag->r != 0)
		av = sort_argv_rev(av, i);
	return (av);
}

void	print_option_a(t_lst *lst, char *file, t_flag *flag)
{
	if (flag->er == 1)
		ft_putstr2(file, " :\n");
	while (lst->next != NULL)
	{
		if (lst->type == 'd')
		{
			ft_putcolor(CYAN, lst->name, RESET);
			ft_putstr("\t");
		}
		else if (lst->type == 'l')
		{
			ft_putcolor(PURPLE, lst->name, RESET);
			ft_putchar('\t');
		}
		else
			ft_putstr2(lst->name, "\t");
		lst = lst->next;
	}
	if (lst->type == 'd' && lst->name[0] != '.')
		ft_putcolor2(CYAN, lst->name, RESET, "\n");
	else if (lst->type == 'l' && lst->name[0] != '.')
		ft_putcolor(PURPLE, lst->name, RESET);
	else
		ft_putstr(lst->name);
	ft_putchar('\n');
}
