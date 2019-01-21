/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort_argv.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/14 10:54:40 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 21:04:49 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	**sort_argv(char **av, int i)
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
			if (ft_strcmp(av[i], av[i + 1]) > 0)
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

char	*year(time_t sec, char *date)
{
	char *tmp;
	char *str;

	if (((time(0) - sec) > 15768000) || ((time(0) - sec) < 0))
	{
		tmp = (ft_strsub((ctime(&sec)), 4, 7));
		str = (ft_strsub((ctime(&sec)), 19, 5));
		date = ft_strjoin(tmp, str);
		free(tmp);
		free(str);
	}
	else
		date = (ft_strsub((ctime(&sec)), 4, 12));
	return (date);
}

void	display_acl(acl_t acl)
{
	if (acl != NULL)
		ft_putstr("+");
	else
		ft_putstr(" ");
}

void	get_acl(char *filename, char *name)
{
	acl_t			acl;
	acl_entry_t		dummy;
	ssize_t			ret;
	char			str[1000];
	char			*tmp;

	tmp = ft_join_path(filename, name);
	ret = listxattr(tmp, str, 1000, 0);
	if (ret > 0)
		ft_putchar('@');
	else if (ret == 0)
	{
		acl = acl_get_link_np(tmp, ACL_TYPE_EXTENDED);
		if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
		{
			acl_free(acl);
			acl = NULL;
		}
		display_acl(acl);
		free(acl);
	}
	else
		ft_putstr(" ");
	free(tmp);
}
