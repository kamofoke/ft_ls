/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamofoke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:40:55 by kamofoke          #+#    #+#             */
/*   Updated: 2019/09/12 14:03:33 by kamofoke         ###   ########.fr       */
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

typedef int			t_bool;

typedef struct		s_files
{
	char			*name;
	char			*link;
	struct s_files	*next;
	struct s_files	*prev;
	struct s_files	*sub_dir;
	struct stat		stat;
	time_t			mtime;
	time_t			atime;
	mode_t			st_mode;
	nlink_t			st_nlink;
	uid_t			st_uid;
	gid_t			st_gid;
	off_t			st_size;
	ino_t			st_ino;
	blkcnt_t		st_blocks;
	struct dirent	*dptr;
}					t_files;

typedef struct		s_flags
{
	t_bool			l;
	t_bool			a;
	t_bool			t;
	t_bool			sm_r;
	t_bool			lg_r;
	t_bool			f;
	t_bool			g;
	t_bool			u;
}					t_flags;

typedef struct		s_r
{
	DIR				*ds;
	struct dirent	*d;
	t_files			*files;
}					t_r;

typedef struct		s_start
{
	int				start;
	int				selected;
}					t_start;

typedef struct		s_lists
{
	t_files			*files;
	t_files			*tmp;
	t_files			*tmp2;
}					t_lists;

typedef struct		s_single
{
	t_files			*alist;
	struct stat		fstat;
	char			*nw_path;
}					t_single;

typedef struct		s_main
{
	t_flags			flags;
	int				start;
	char			*pwd;
}

#endif
