/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamofoke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:55:31 by kamofoke          #+#    #+#             */
/*   Updated: 2019/09/11 14:57:28 by kamofoke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

char	*make_path(char *dir, char file)
{
	char *new_path;
	size_t	l;

	new_path = NULL;
	l = ft_strlen(dir) + ft_strlen(file);

	l += 1;

	if (!(new_path) = (char*)malloc(sizeof(char) * l + 1))
		return NULL;
	if (file[0] == "/" || file[0] == "~")
		new_path = ft_strdup(file);
	else
	{
		new_path = ft_strcpy(new_path, dir);
		new_path = ft_strcat(new_path, "/");
		new_path = ft_strcat(new_path, file);
	}
	return (new_path);
	ft_strdel(&new_path);

}
