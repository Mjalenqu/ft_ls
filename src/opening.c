/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   opening.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/06 13:42:57 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 15:46:14 by mjalenqu    ###    #+. /#+    ###.fr     */
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
	lst->info = NULL;
	return (lst);
}

void	lst_free(t_lst *lst)
{
	t_lst *point;

	while (lst)
	{
		point = lst;
		if (lst->name != NULL)
			free(lst->name);
		if (lst->info != NULL)
		{
			free(lst->info->login);
			free(lst->info->group);
			free(lst->info->time);
			free(lst->info->octet);
			free(lst->info->link);
			free(lst->info);
		}
		lst = lst->next;
		free(point);
	}
}

void	win_space(struct dirent *red, t_lst *lst, char *file)
{
	char	*str;

	lst->size = ft_strlen(red->d_name);
	lst->name = ft_strdup(red->d_name);
	str = ft_join_path(file, lst->name);
	lst->type = get_type(str);
	lst->sec = get_time(str);
	free(str);
}

t_lst	*openit(char *file, t_flag *flag)
{
	DIR				*rep;
	t_lst			*lst;
	t_lst			*save;

	lst = ft_newlist(NULL, 0);
	save = lst;
	if ((rep = opendir(file)) == NULL)
	{
		perror("ft_ls");
		lst_free(save);
		return (NULL);
	}
	lst = chaipa(rep, lst, file, flag);
	closedir(rep);
	lst_sort(&save, flag);
	if (flag->r != 0)
		save = sort_r(&save);
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
			return (0);
		if (str[i + 1] == '-' && str[i + 2] == '\0')
			return (2);
		while (str[++i])
			if (check_flags(flag, str[i]) == -1)
				return (-1);
	}
	else
		return (0);
	return (1);
}
