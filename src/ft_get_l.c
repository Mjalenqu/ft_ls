/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_l.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/03 14:17:47 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/06 16:05:56 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_l(t_lst *lst, char *file, t_flag *flag)
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
			ft_putstr("\n");
		}
		else if (lst->name[0] != '.')
			ft_putstr2(lst->name, "\n");
		lst = lst->next;
	}
	if (lst->info && lst->name[0] != '.')
		print_stat(lst->info);
	if (lst->name[0] != '.')
		ft_putstr(lst->name);
	ft_putchar('\n');
}

void	print_la(t_lst *lst, char *file, t_flag *flag)
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
			ft_putstr("\n");
		}
		else
			ft_putstr2(lst->name, "\n");
		lst = lst->next;
	}
	if (lst->info && lst->name[0] != '.')
		print_stat(lst->info);
	if (lst->name[0] != '.')
		ft_putstr(lst->name);
	ft_putchar('\n');
}

void	choose_print(t_lst *save, char *file, t_flag *flag)
{
	if (flag->l != 0)
	{
		if (flag->a != 0)
			print_la(save, file, flag);
		else
			print_l(save, file, flag);
	}
	else if (flag->a != 0)
		print_option_a(save, file, flag);
	else
		print_list(save, file, flag);
}

void	print_right(int nb)
{
	int i;
	int c[3];

	i = 3;
	while (i--)
	{
		c[i] = nb % 8;
		nb /= 8;
	}
	i = 0;
	while (i < 3)
	{
		(c[i] & 4) ? write(1, "r", 1) : write(1, "-", 1);
		(c[i] & 2) ? write(1, "w", 1) : write(1, "-", 1);
		(c[i] & 1) ? write(1, "x", 1) : write(1, "-", 1);
		i++;
	}
}

t_info	*ft_inspect_file(char *file)
{
	t_info			*st;
	struct stat		*buf;
	struct group	*groups;
	struct passwd	*passwds;
	int				red;

	st = malloc(sizeof(t_info));
	buf = ((struct stat*)malloc(sizeof(struct stat)));
	red = stat(file, buf);
	groups = getgrgid(buf->st_gid);
	passwds = getpwuid(buf->st_uid);
	if (S_ISDIR(buf->st_mode))
		st->type = 'd';
	else if (S_ISLNK(buf->st_mode))
		st->type = 'l';
	else
		st->type = '-';
	st->rwx = buf->st_mode;
	st->link = buf->st_nlink;
	st->login = ft_strdup(passwds->pw_name);
	st->group = ft_strdup(groups->gr_name);
	st->octet = buf->st_size;
	st->time = (ft_strsub((ctime(&buf->st_mtimespec.tv_sec)), 4, 12));
	free(buf);
	return (st);
}
