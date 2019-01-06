/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/05 11:27:25 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 10:54:48 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H

#include "../libft/libft.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
# define CYAN "\033[1;36m"
# define RED "\033[1;31m"
# define RESET "\033[00m"

typedef struct			s_lst
{
	char				*name;
	size_t				size;
	int					type;
	struct s_lst		*next;
	struct s_lst		*son;
	struct s_info		*info;
}						t_lst;

typedef struct			s_info
{
	char				*name;
	char				*login;
	char				*group;
	int					octet;
	int					link;
	char				*time;
	char				type;
	int					rwx;
}						t_info;

typedef struct			s_flag
{
	char				nb;
	char				a;
	char				r;
	char				R;
	char				l;
	char				t;
	char				u;
	char				f;
	char				g;
	char				d;
}						t_flag;

void					lst_sort(t_lst **lst, t_flag *flag);
void					lst_sort_ascii(t_lst **lst);
t_lst					*ft_newlist(char *name, size_t size);
t_lst					*openit(char *file, t_flag *flag);
t_lst					*readit(char *file);
t_lst					*sort_list(t_lst *lst);
t_info					*get_stat(t_lst *lst, char *path);
t_flag					*init_flag(t_flag *flag);
t_info					*get_l(t_lst *lst, char *path);
t_info 					*ft_inspect_file(char *file);
int						ft_check_option(char *str, t_flag *flag);
int						check_flags(t_flag *flag, char c);
char					*ft_join_path(char *s1, char *s2);
char					*ft_get_name(int userid);
char					*ft_get_name(int groupid);
void					print_stat(t_info *st);
void  				print_right(int nb);
void					ft_swap_data(t_lst *lst, t_lst *tmp);
void					print_list(t_lst *lst, char *file, t_flag *flag);
void					print_option_a(t_lst *lst, char *file, t_flag *flag);
void					choose_print(t_lst *save, char *file, t_flag *flag);
void					print_la(t_lst *lst, char *file, t_flag *flag);
void					print_l(t_lst *lst, char *file, t_flag *flag);
#endif