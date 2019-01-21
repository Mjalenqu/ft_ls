/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_struct.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/02 10:54:37 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 13:45:44 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_flag	*init_flag(t_flag *flag)
{
	flag->nb = 1;
	flag->a = 0;
	flag->aa = 0;
	flag->r = 0;
	flag->er = 0;
	flag->l = 0;
	flag->t = 0;
	flag->m = 0;
	flag->un = 0;
	return (flag);
}

void	get_files(char **file, t_flag *flag, int i)
{
	int		c;
	t_info	*info;

	while (file[i])
	{
		if (get_type(file[i]) == '-')
		{
			c = 1;
			if (flag->l == 0)
				ft_putstr2(file[i], "  ");
			else
			{
				info = ft_inspect_file(file[i]);
				print_start(info, file[i]);
			}
		}
		i++;
	}
	if (c != 0)
		ft_putchar('\n');
}

t_lst	*chaipa(DIR *rep, t_lst *lst, char *file, t_flag *flag)
{
	char			*str;
	struct dirent	*red;

	while ((red = readdir(rep)))
	{
		if (lst->name)
		{
			lst->next = ft_newlist(NULL, 0);
			lst = lst->next;
		}
		win_space(red, lst, file);
		if ((lst->type == 'd') && red->d_name[0] != '.')
		{
			str = ft_join_path(file, lst->name);
			if (flag->er != 0)
				lst->son = openit(str, flag);
			free(str);
		}
		if (flag->l == 0)
			lst->info = NULL;
		else
			lst->info = flag_l(file, lst->name);
	}
	return (lst);
}

void	choose_print(t_lst *save, char *file, t_flag *flag)
{
	if (flag->l != 0)
	{
		if (flag->a != 0)
			print_la(save, file);
		else if (flag->aa != 0)
			print_laaa(save, file);
		else
			print_l(save, file);
	}
	else if (flag->m != 0)
		flag->a != 0 ? print_ma(save, file, flag) : print_m(save, file, flag);
	else if (flag->un != 0)
		flag->a != 0 ? print_una(save, file, flag) : print_un(save, file, flag);
	else if (flag->aa != 0)
		print_aaa(save, file, flag);
	else if (flag->a != 0)
		print_option_a(save, file, flag);
	else
		print_list(save, file, flag);
}

t_info	*flag_l(char *file, char *name)
{
	t_info	*info;
	char	*str;

	str = ft_join_path(file, name);
	info = ft_inspect_file(str);
	free(str);
	return (info);
}
