/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:30:12 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/24 23:41:21 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>

typedef struct s_heredoc
{
	char	**envp;
	int		outfile;
	char	**path;
	char	*l_a;
	char	*h_d;
	char	*line;
	char	*limiter;
}				t_heredoc;

typedef struct s_vars
{
	int		ac;
	char	**av;
	char	**envp;
	char	*f_a;
	char	*l_a;
	int		infile;
	int		outfile;
	char	**path;
	int		fd[2];
	int		res;
}				t_vars;

void	here_doc(int ac, char **av, char **envp);
char	*get_name(t_heredoc *vars, char **cmd);
void	execute_child(t_heredoc *vars, char **cmd);
char	**get_file_name_bonus(char **envp);
char	**join_commands(t_heredoc *vars, char *arg);
int		get_paths_len(char **str);
void	check_last_arg(t_heredoc *vars);
void	multiple_pipes(int ac, char **av, char **envp, int i);
void	check_first(t_vars *vars);
void	check_last(t_vars *vars);
void	execute_first_cmd(t_vars *vars, char **envp, char **cmd);
char	*get_name_multi(t_vars *vars, char **cmd);
void	ft_free(char **p);
void	free_args(t_heredoc *vars, char **cmd1, char **cmd2, char **path);
void	here_loop(t_heredoc *vars, int tmp);
char	**sep_first(char *arg);
char	**check_path(char	**p);

#endif