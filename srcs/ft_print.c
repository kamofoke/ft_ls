/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamofoke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:57:40 by kamofoke          #+#    #+#             */
/*   Updated: 2019/09/20 12:42:19 by kamofoke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void			ft_printinfo(struct stat st)
{
	struct group		*p;

	ft_putnbr((int)st.st_nlink);
	ft_putchar('\t');
	p = getgrgid(st.st_gid);
	ft_putstr(p->gr_name);
	ft_putchar('\t');
	ft_putnbr((long long)st.st_size);
	ft_putchar('\t');
}

void			ft_printtime(struct stat st)
{
	int			c;
	char		date_time[100];

	ft_memset(date_time, 0, sizeof(date_time));
	ft_strncpy(date_time, ctime(&st.st_mtime), sizeof(date_time));
	c = 0;
	while (date_time[c] != '\0')
	{
		if (date_time[c] == '\n')
		{
			date_time[c] = '\0';
		}
		c++;
	}
	ft_putstr(date_time);
	ft_putchar(' ');
}

void			ft_print_type(t_files *tmp, t_flags flags)
{
	if (S_ISDIR((tmp)->st_mode))
		ft_folder_color_r((tmp)->name);
	else if (S_ISLNK((tmp)->st_mode))
		ft_symlinkcolor(tmp, flags);
	else if (((tmp)->st_mode > 0) && (S_IEXEC & (tmp)->st_mode))
		ft_exec_color_r((tmp)->name);
	else if (S_ISREG((tmp)->st_mode))
		ft_putendl((tmp)->name);
	else
		ft_putchar('\0');
}

void			ft_print_r(t_files *tmp, t_flags flags)
{
	if (!flags.a)
	{
		if (tmp->name[0] != '.')
		{
			if (flags.l == TRUE)
			{
				ft_printpermissions(tmp->stat);
				ft_printinfo(tmp->stat);
				ft_printtime(tmp->stat);
			}
			ft_print_type(tmp, flags);
		}
	}
	else
	{
		if (flags.l == TRUE)
		{
			ft_printpermissions(tmp->stat);
			ft_printinfo(tmp->stat);
			ft_printtime(tmp->stat);
		}
		ft_print_type(tmp, flags);
	}
}
