/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/05 11:26:45 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/02 17:10:24 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	t_flag	flag;

	j = 0;
	i = 1;
	flag = *(init_flag(&flag));
	if (argc == 1)
	{
		openit(".", &flag);
		return (0);
	}
	while (argv[i])
	{
		j = ft_check_option(argv[i], &flag);
		if (j == -1)
			return (0);
		else if (j == 0)
			break ;
		else
			i++;
	}
	if (argv[i])
	{
		while (argv[i])
		{
			openit(argv[i], &flag);
			i++;
		}
	}
	else
		openit(".", &flag);
	return (0);
}
