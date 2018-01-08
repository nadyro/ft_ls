/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 15:48:01 by nsehnoun          #+#    #+#             */
/*   Updated: 2017/11/21 21:36:12 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define L 'l'
# define R 'R'
# define A 'a'
# define R1 'r'
# define T 't'
# define BUFF_SIZE 1
# define KMAG  "\x1B[35m"
# define KNRM  "\x1B[0m"
# define KCYN  "\x1B[36m"
# define KBCYN "\x1B[96m"
# define KGRE  "\x1B[32m"

# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

struct		s_f {
	int	l;
	int re;
	int a;
	int r;
	int t;
};
struct		s_ds {
	char			**chmod;
	unsigned long	hlink;
	char			*gname;
	char			*uname;
	long long		fs;
	struct timespec	time;
	char			*dname;
	size_t			lf;
	int64_t			blocks;
	ssize_t			l;
	int				maj;
	int				min;
	char			ln[1024];
};
void		sort_paths(char **correct_paths);
void		sort_paths_rev(char **correct_paths);
void		sort_path_time(char **cp, int *time);
void		sort_path_timerev(char **cp, int *time);
void		sort_filendir(char **cp, int *x);
void		sort_paths_flags(struct s_f *f, char **paths, int *time);
void		sort_ld(t_list	*ld);
void		sort_ldi(t_list *ld);
void		sort_ldinf(t_list *ld);
void		sort_ldtime(t_list *ld);
void		sort_ldtimerev(t_list *ld);
t_list		*sort_print_listp(struct s_f *f, t_list **l, char *d, t_list *lp);
int			*file_tosort(char **paths, int *y, struct stat st);
void		ft_printlist(t_list *list, struct s_f *f);
void		ft_putchmod(char **chmod);
void		ft_putdots(char *str);
char		**ft_chmod(struct stat st);
void		ft_putspace(char *str);
void		print_errors(char *directory);
void		print_usages(char c);
void		print_typeflags(char *directory);
void		is_file(char *file, struct s_f *f);
void		is_link(char *file, struct stat st);
int			path_args(char *directory);
int			filter_args(char **argv, char **flags);
void		add_flags(char **flags, char *flag);
char		**paths_manager(int x, char **args, struct s_f *f, int *y);
struct s_f	*tf(char *flags);
char		**get_paths(int x, char **argv);
char		**clean_paths(char **paths, int x);
char		*path_return(char *d, char *dn);
char		*chmod_usr(char *chmod, struct stat st);
char		*chmod_grp(char *chmod, struct stat st);
char		*chmod_oth(char *chmod, struct stat st);
void		free_chmod(char **chmod);
void		elag_total_print(struct s_f *f, t_list *l);
void		elagprinter(struct s_f *f, t_list *list);
void		elag_l_printer_1(struct s_f *f, t_list *list);
void		elag_l_printer_2(struct s_f *f, t_list *list);
void		elag_time(struct s_f *f, t_list *list);
void		read_dir_param(char *directory, struct s_f *flags, t_list *l);
void		recursive_flow(char *c, t_list **lp, struct s_f *f, t_list *l);
void		read_dir(char *directory, struct s_f *flags, t_list *l);
void		get_dirs(char *d, char *dn, t_list **ld, struct s_f *f);
t_list		*get_folders(t_list	**l, char *d, struct s_f *flags, t_list *lp);
struct s_ds	*stats_infos(char *d, char *dn, struct s_f *f);
void		ft_major_minor(struct stat st, char **chmod);
t_list		*ft_freelist(t_list **l, struct s_f *f);
void		free_timenfiles(int *x, int *y, char **paths);
int			*get_time(int x);
int			*alloc_y(int *y, int x);
int			get_total(t_list *l);
void		declare_struct(struct s_f *flags, char *sflags);
int			check_dots(char *dname);
#endif
