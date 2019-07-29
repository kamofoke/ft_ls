/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamofoke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 09:32:43 by kamofoke          #+#    #+#             */
/*   Updated: 2019/07/12 11:19:26 by kamofoke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_ls()
{
	struct dirent	*d;
	DIR				*dir;
	char			d_name[100];

	if ((dir = opendir (".")) == NULL)
		return (0);
	while ((d = readdir(dir)))
	{
		ft_putendl(d-> d_name);
	}
}

int	main (void)
{
	ft_ls();
}
