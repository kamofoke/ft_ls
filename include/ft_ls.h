/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamofoke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:40:55 by kamofoke          #+#    #+#             */
/*   Updated: 2019/09/10 11:42:09 by kamofoke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H		
# define FT_LS_H
#include "./Libft/libft.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>
#include <pwd.h>
#include <fcntl.h>

typedef		int t_bool

typedef 	struct s_files
{
	char 			*name;
	char			*link;
	struct			s_files *next;
	struct			s_files *preview;
	struct			s_files *sub_dir;
	struct			stat  stat;
	time_t			mtime;
	time_t			atime;

}					t_files

typedef		struct s_flags
{
	t_bool			a;
	t_bool			l;
	t_bool			R;
	t_bool			r;
	t_bool			t;

}					t_flags

typedef		struct	s_r
{
	DIR				*ds;
	struct	dirent 	*d;
	t_files			*files;

}					t_r

typedef 	struct	s_start
{
	int		start;
	int		selected;

}					t_start

typedef		struct	s_list
{
	t_files			*files;
	t_files			tmp;
	t_files			tmp2;
}					t_list

typedef		struct	s_single
{
	t_files			*alist;
	struct	stat  	fstat;
	char			*nw_path;

}					t_single


typedef		struct	s_main
{
	t_flags			cflags;
	int 			start;
	char			*pwd;
}					t_main


#endif
