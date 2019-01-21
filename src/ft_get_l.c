/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_l.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/03 14:17:47 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/10 13:46:56 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*init_right(char *str)
{
	int i;

	i = 0;
	while (i < 9)
	{
		str[i] = '-';
		i++;
	}
	return (str);
}

void	get_right(int nb)
{
	static char right[9];

	init_right(right);
	right[0] = (nb & S_IRUSR) ? 'r' : '-';
	right[1] = (nb & S_IWUSR) ? 'w' : '-';
	right[2] = (nb & S_IXUSR) ? 'x' : '-';
	right[3] = (nb & S_IRGRP) ? 'r' : '-';
	right[4] = (nb & S_IWGRP) ? 'w' : '-';
	right[5] = (nb & S_IXGRP) ? 'x' : '-';
	right[6] = (nb & S_IROTH) ? 'r' : '-';
	right[7] = (nb & S_IWOTH) ? 'w' : '-';
	right[8] = (nb & S_IXOTH) ? 'x' : '-';
	if (nb & S_ISUID)
		right[2] = (nb & S_IXUSR) ? 's' : 'S';
	if (nb & S_ISGID)
		right[5] = (nb & S_IXGRP) ? 's' : 'l';
	if (nb & S_ISVTX)
		right[8] = (nb & S_IXOTH) ? 't' : 'T';
	ft_putstr(right);
}

char	get_type(char *file)
{
	struct stat	buf;
	int			red;
	char		type;

	type = 0;
	red = lstat(file, &buf);
	if (S_ISLNK(buf.st_mode))
		type = 'l';
	else
	{
		red = stat(file, &buf);
		if (S_ISDIR(buf.st_mode))
			type = 'd';
		else	if (S_ISCHR(buf.st_mode))
			type = 'c';
		else if (S_ISBLK(buf.st_mode))
			type = 'b';
		else if (S_ISFIFO(buf.st_mode))
			type = 'p';
		else if (S_ISREG(buf.st_mode))
			type = '-';
		else
			return (0);
	}
	return (type);
}

int		get_time(char *file)
{
	struct stat	*buf;
	int			red;
	long		sec;

	sec = 0;
	buf = malloc(sizeof(struct stat));
	red = lstat(file, buf);
	sec = buf->st_mtime;
	free(buf);
	return (sec);
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
	red = lstat(file, buf);
	groups = getgrgid(buf->st_gid);
	passwds = getpwuid(buf->st_uid);
	st->blk = buf->st_blocks;
	st->rwx = buf->st_mode;
	st->link = ft_itoa(buf->st_nlink);
	st->login = ft_strdup(passwds->pw_name);
	st->group = ft_strdup(groups->gr_name);
	st->octet = ft_itoa(buf->st_size);
	st->time = year(buf->st_mtime, st->time);
	st->maj = major(buf->st_rdev);
	st->min = minor(buf->st_rdev);
	free(buf);
	return (st);
}
