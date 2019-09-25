/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_block.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamofoke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 11:22:54 by kamofoke          #+#    #+#             */
/*   Updated: 2019/09/20 12:30:51 by kamofoke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void			ft_print_block(int block, t_flags flags)
{
	if (flags.l == TRUE)
	{
		ft_putstr("total ");
		ft_putnbr(block);
		ft_putchar('\n');
	}
}

void			*ft_setup_block(char *curr_dir, t_flags flags, t_r *r)
{
	if (!(r->ds = opendir(curr_dir)))
		return (NULL);
	if (!(r->dptr = readdir(r->ds)))
		ft_exit("readdir problem");
	if (!(r->files = ft_listnew(r->dptr, curr_dir, flags)))
		ft_exit("listnew problem");
	while ((r->dptr = readdir(r->ds)))
		ft_lpb(&r->files, r->dptr, curr_dir, flags);
	return (r->files);
}

void			ft_block(char *curr_dir, t_flags flags)
{
	t_r			r;
	int			block;
	t_files		*tmp;

	block = 0;
	r.files = NULL;
	ft_setup_block(curr_dir, flags, &r);
	tmp = r.files;
	if (!r.files)
		return ;
	while (r.files->next)
	{
		if (ft_strcmp(r.files->name, ".") != 0 && ft_strcmp(r.files->name, "..")
			!= 0 && r.files->name[0] == '.' && flags.a != TRUE)
			r.files = r.files->next;
		else
		{
			block += (int)r.files->st_blocks;
			r.files = r.files->next;
		}
	}
	block += (int)r.files->st_blocks;
	closedir(r.ds);
	ft_free_lst(tmp);
	ft_print_block(block, flags);
}
