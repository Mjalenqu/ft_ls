/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_join_path.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/08 07:38:59 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/06 16:07:27 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

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

void	print_option_a(t_lst *lst, char *file, t_flag *flag)
{
	if (flag->R == 1)
		ft_putstr2(file, " :\n");
	while (lst->next != NULL)
	{
		if (lst->info)
			print_stat(lst->info);
		if (lst->type == 4)
		{
			ft_putcolor(CYAN, lst->name, RESET);
			ft_putstr("\t");
		}
		else
			ft_putstr2(lst->name, "\t");
		lst = lst->next;
	}
	if (lst->info)
		print_stat(lst->info);
	ft_putstr(lst->name);
	ft_putchar('\n');
}
