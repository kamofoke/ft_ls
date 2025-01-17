/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lg_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamofoke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 09:36:44 by kamofoke          #+#    #+#             */
/*   Updated: 2019/09/17 10:02:27 by kamofoke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

t_files			*ft_setup_list(char *curr_dir, t_flags flags)
{
	t_r		r;

	if (!(r.ds = opendir(curr_dir)))
	{
		ft_putstr("ls: ");
		ft_putstr(curr_dir);
		ft_putstr(": ");
		ft_putendl(strerror(errno));
		return (NULL);
	}
	if (!(r.dptr = readdir(r.ds)))
		ft_exit("readdir problem");
	if (!(r.files = ft_listnew(r.dptr, curr_dir, flags)))
		ft_exit("listnew problem");
	while ((r.dptr = readdir(r.ds)))
		ft_lpb(&r.files, r.dptr, curr_dir, flags);
	closedir(r.ds);
	return (r.files);
}

void			ft_list_b(t_files *files, char *curr_dir, t_flags flags)
{
	t_files		*tmp;

	tmp = files;
	while (tmp->next)
	{
		ft_is_directory(tmp, curr_dir, flags);
		tmp = tmp->next;
	}
	ft_is_directory(tmp, curr_dir, flags);
}

t_lists			ft_list_a(char *curr_dir, t_flags flags)
{
	t_lists		lists;

	if (!(lists.files = ft_setup_list(curr_dir, flags)))
		return (lists);
	lists.tmp = lists.files;
	if (flags.f == FALSE)
		insertion_sort(&lists.tmp, flags);
	if (flags.f == TRUE)
		lists.tmp2 = lists.files;
	else if (flags.sm_r == TRUE)
	{
		lists.tmp = reverse_lst(lists.tmp);
		lists.tmp2 = lists.tmp;
		lists.files = lists.tmp;
	}
	else if (flags.t)
	{
		lists.tmp2 = lists.tmp;
		lists.files = lists.tmp;
	}
	else
		lists.tmp2 = lists.files;
	return (lists);
}

t_files			*ft_list(char *curr_dir, t_flags flags)
{
	t_lists		lists;
	t_files		*tmp;

	if (flags.l == TRUE)
		ft_block(curr_dir, flags);
	lists = ft_list_a(curr_dir, flags);
	if (!lists.files)
		return (NULL);
	tmp = lists.tmp;
	while (lists.tmp->next)
	{
		ft_print_r(lists.tmp, flags);
		lists.tmp = lists.tmp->next;
	}
	ft_print_r(lists.tmp, flags);
	if (flags.lg_r == TRUE)
		ft_list_b(lists.tmp2, curr_dir, flags);
	return (lists.files);
}
