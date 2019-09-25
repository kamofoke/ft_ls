/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamofoke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:08:45 by kamofoke          #+#    #+#             */
/*   Updated: 2019/09/17 10:13:55 by kamofoke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define TRUE 1
# define FALSE 0

# include "../Libft/libft.h"
# include "../include/ft_ls.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/ioctl.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>

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
	struct dirent	*dptr;
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
}					t_main;

void				ft_exit(const char *message);
void				ft_folder_color_r(char *ptr);
void				ft_exec_color_r(char *ptr);
void				ft_symlinkcolor(t_files *file, t_flags flags);
void				ft_init_flags(t_flags *f);
void				ft_which_flags(char *ops, t_flags *f);
void				ft_printpermissions(struct stat st);
void				ft_printinfo(struct stat st);
void				ft_printtime(struct stat st);
void				ft_print_r(t_files *tmp, t_flags flags);
void				ft_lpb(t_files **b, struct dirent *d, char *p, t_flags f);
void				ft_list_swap(t_files **head, t_files **a, t_files **b);
void				insertion_sort(t_files **head, t_flags flags);
void				sorted_insert_time(t_files **head, t_files *new_node);
void				ft_select(char **av, t_main main);
void				*ft_select_check(char *name);
void				ft_symlink_path(t_files *file, char *path, t_flags f);
void				ft_is_directory(t_files *tmp, char *curr_dir, t_flags f);
void				ft_block(char *curr_dir, t_flags flags);
void				sorted_access_time(t_files **head, t_files *new_node);
char				*make_path_fl(char *dir, char *file);
t_start				ft_find_flags(char **options, t_flags *f);
t_files				*ft_listnew(struct dirent *ent, char *path, t_flags flags);
t_files				*reverse_lst(t_files *head);
t_files				*ft_setup_list(char *curr_dir, t_flags flags);
t_files				*ft_list(char *curr_dir, t_flags flags);
void				ft_free_lst(t_files *file);
void				ft_free_lst_rvrs(t_files *file);
void				ft_free_r(t_files *file);

#endif
