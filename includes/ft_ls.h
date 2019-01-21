/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/05 11:27:25 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 13:51:28 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>
# define CYAN "\033[1;36m"
# define RED "\033[1;31m"
# define RESET "\033[00m"
# define PURPLE "\033[0;35m"

typedef struct			s_lst
{
	char				*name;
	size_t				size;
	char				type;
	long				sec;
	struct s_lst		*next;
	struct s_lst		*son;
	struct s_info		*info;
	size_t				log;
	size_t				grp;
	size_t				len;
	size_t				lnk;

}						t_lst;

typedef struct			s_info
{
	char				*name;
	char				*login;
	char				*group;
	char				*octet;
	char				*link;
	char				*time;
	char				type;
	int					rwx;
	int					blk;
	int					maj;
	int					min;

}						t_info;

typedef struct			s_flag
{
	char				nb;
	char				a;
	char				aa;
	char				r;
	char				er;
	char				l;
	char				t;
	char				m;
	char				un;
}						t_flag;

typedef	struct			s_disp
{
	size_t				max_log;
	size_t				max_grp;
	size_t				max_len;
	size_t				max_lnk;
}						t_disp;

/*
******************************************************************************
**				display.c													**
******************************************************************************
*/
void					print_la(t_lst *lst, char *file);
void					print_l(t_lst *lst, char *file);
void					print_m(t_lst *lst, char *file, t_flag *flag);
void					print_un(t_lst *lst, char *file, t_flag *flag);
void					print_list(t_lst *lst, char *file, t_flag *flag);

/*
******************************************************************************
**				display_option.c											**
******************************************************************************
*/
void					print_aaa(t_lst *lst, char *file, t_flag *flag);
void					print_ma(t_lst *lst, char *file, t_flag *flag);
void					print_una(t_lst *lst, char *file, t_flag *flag);
void					print_laaa(t_lst *lst, char *file);

/*
******************************************************************************
**					sort_argv.c												**
******************************************************************************
*/
char					*year(time_t sec, char *date);
char					**sort_argv(char **av, int i);
void					get_acl(char *filename, char *name);
void					display_acl(acl_t acl);

/*
******************************************************************************
**							sort_list.c										**
******************************************************************************
*/
void					lst_sort(t_lst **lst, t_flag *flag);
void					lst_sort_ascii(t_lst **lst);
void					lst_sort_time(t_lst **lst);
t_lst					*sort_r(t_lst **lst);
t_lst					*lst_swap(t_lst *p1, t_lst *p2);

/*
******************************************************************************
**					opening.c												**
******************************************************************************
*/
t_lst					*openit(char *file, t_flag *flag);
t_lst					*ft_newlist(char *name, size_t size);
void					ft_free(t_info *info);
void					win_space(struct dirent *red, t_lst *lst, char *file);
int						ft_check_option(char *str, t_flag *flag);

/*
******************************************************************************
**				ft_get_l.c													**
******************************************************************************
*/
void					get_right(int nb);
char					get_type(char *file);
char					*init_right(char *str);
int						get_time(char *file);
t_info					*ft_inspect_file(char *file);

/*
******************************************************************************
**				get_stat.c													**
******************************************************************************
*/
t_disp					get_total_a(t_lst *lst);
t_disp					get_total(t_lst *lst);
void					print_space(int max, int size);
void					print_min(int maj, char *s, int min);
void					print_stat(t_lst *lst, t_disp disp, char *file);

/*
******************************************************************************
**							check_flags.c									**
******************************************************************************
*/
int						check_flags(t_flag *flag, char c);
int						check_flags_bis(t_flag *flag, char c);
void					error_flag(char c);
char					**sort_argv_time(char **av, int i);
char					**sort_argv_rev(char **av, int i);

/*
******************************************************************************
**					ft_init_struct.c										**
******************************************************************************
*/
t_flag					*init_flag(t_flag *flag);
t_lst					*chaipa(DIR *rep, t_lst *lst, char *file, t_flag *flag);
t_info					*flag_l(char *file, char *name);
void					get_files(char **file, t_flag *flag, int i);
void					choose_print(t_lst *save, char *file, t_flag *flag);

/*
******************************************************************************
**					ft_join_path.c											**
******************************************************************************
*/
void					print_option_a(t_lst *lst, char *file, t_flag *flag);
void					print_link(char *name, char *file);
char					*ft_join_path(char *s1, char *s2);
char					**choose_sort(char **av, int i, t_flag *flag);
void					earth_wind_and_fire(char **av, int i, t_flag flag);

/*
******************************************************************************
**							main.c											**
******************************************************************************
*/
void					print_start(t_info *info, char *file);
void					ft_free(t_info *info);
int						start(char **av, t_flag flag, int i, int j);
int						check_type(char **file, t_flag *flag, int i);
int						main(int argc, char **argv);

#endif
