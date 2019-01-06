/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   opening.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/06 13:42:57 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/06 16:08:37 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_lst	*ft_newlist(char *name, size_t size)
{
	t_lst	*lst;

	if (!(lst = (t_lst*)malloc(sizeof(t_lst))))
		return (0);
	if (!(name) || !(size))
	{
		lst->name = 0;
		lst->size = 0;
	}
	else
	{
		if (name != NULL)
		{
			if (!(lst->name = (ft_strnew(size))))
				return (0);
			lst->name = ft_strcpy(lst->name, name);
		}
		else
			lst->name = NULL;
		lst->size = size;
	}
	lst->next = NULL;
	lst->son = NULL;
	return (lst);
}

void	print_list(t_lst *lst, char *file, t_flag *flag)
{
	if (flag->R == 1)
		ft_putstr2(file, " :\n");
	while (lst->next != NULL)
	{
		if (lst->info && lst->name[0] != '.')
			print_stat(lst->info);
		if (lst->type == 4 && lst->name[0] != '.')
		{
			ft_putcolor(CYAN, lst->name, RESET);
			ft_putstr("\t");
		}
		else if (lst->name[0] != '.')
			ft_putstr2(lst->name, "\t");
		lst = lst->next;
	}
	if (lst->info && lst->name[0] != '.')
		print_stat(lst->info);
	if (lst->name[0] != '.')
		ft_putstr(lst->name);
	ft_putchar('\n');
}

void	lst_free(t_lst *lst)
{
	t_lst *point;

	while (lst)
	{
		point = lst;
		if (lst->name != NULL)
			free(lst->name);
		if (lst->info)
		{
			free(lst->info->login);
			free(lst->info->group);
			free(lst->info->time);
			free(lst->info);
		}
		lst = lst->next;
		free(point);
	}
}

t_lst	*openit(char *file, t_flag *flag)
{
	DIR				*rep;
	struct dirent	*red;
	t_lst			*lst;
	t_lst			*save;
	char			*str;

	lst = NULL;
	if (lst == NULL)
		lst = ft_newlist(NULL, 0);
	save = lst;
	if ((rep = opendir(file)) == NULL)
	{
		ft_putcolor("ft_ls: ", file, " No such file or directory\n");
		return (NULL);
	}
	while ((red = readdir(rep)))
	{
		if (lst->name)
		{
			lst->next = ft_newlist(NULL, 0);
			lst = lst->next;
		}
		lst->size = ft_strlen(red->d_name);
		lst->name = ft_strdup(red->d_name);
		lst->type = red->d_type;
		if (red->d_type == 4 && red->d_name[0] != '.')
		{
			if (!(str = ft_join_path(file, lst->name)))
			{
				lst_free(save);
				return (0);
			}
			if (flag->R != 0)
			{
				lst->son = openit(str, flag);
			}
			free(str);
		}
		if (flag->l == 0)
			lst->info = NULL;
		else
		{
			str = ft_join_path(file, lst->name);
			lst->info = ft_inspect_file(str);
			free(str);
		}
	}
	closedir(rep);
	lst_sort(&save, flag);
	choose_print(save, file, flag);
	lst_free(save);
	return (save);
}

int		ft_check_option(char *str, t_flag *flag)
{
	int			i;
	int			j;

	i = 0;
	j = -1;
	if (str[i] == '-')
	{
		if (str[i + 1] == '\0')
		{
			return (0);
		}
		while (str[++i])
			if (check_flags(flag, str[i]) == -1)
				return (-1);
	}
	else
		return (0);
	return (1);
}
