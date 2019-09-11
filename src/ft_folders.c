/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_folders.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamofoke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:54:53 by kamofoke          #+#    #+#             */
/*   Updated: 2019/09/11 14:55:21 by kamofoke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"


void	ft_foldername(char *ptr)
{
	ft_putstr(ptr);
	ft_putchar('\n');
}

void ft_symbolic_link(t_file *file, t_flags *flag)
{
	ft_putstr(file->name);
	if (flag.l == TRUE)
		ft_putstr(file->link);
	ft_putchar('\n');
}

void ft_execute(char *ptr)
{
	ft_putstr(ptr);
	ft_putchar('\n');
}
