/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 11:49:33 by ielbadao          #+#    #+#             */
/*   Updated: 2021/04/01 09:29:30 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
# define READLINE_H
# define KEY_UP 183
# define KEY_DOWN 184
# define KEY_LEFT 186
# define KEY_RIGHT 185
# define ENTER 10
# define KEY_REMOVE 127
# define KEY_TAB 9
# define CTRL_D 4
# define CTRL_C 3
# define BUFFER_SIZE 4096
# include <stdlib.h>
# include <stdio.h>
# include <termcap.h>
# include <termios.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/ioctl.h>

/*
* Typedefs
*/
typedef struct s_linked
{
	char			*cmd;
	char			*cmd_tmp;
	int				editing;
	int				already;
	int				is_visited;
	struct s_linked	*next;
	struct s_linked	*prev;
}				t_linked;

/*
* Globale variables
*/
int				g_history_file;
int				g_history_iter;
t_linked		*g_last;
t_linked		*g_history;
t_linked		*g_history_to_free;
t_linked		*g_history_the_oldest;
/*
* initiate termcaps
*/
char		*ft_strchr(const char *s, int c);
int			ft_strlen(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s);
void		ft_free(char **p);
void		fill_line(char **line, char *buffer);
int			process_line(char **line, char **remain);
int			process_remain(char **remain, char **line);
int			in(int fd, char **line);
int			init_caps(void);
int			ft_getchar(void);
char		*readline(void);
int			move_cursor(int d);
void		up_history(char **line, int line_length);
void		backspace(char **line,int line_length);
void		down_history(char **line, int line_length);
void		newline(char	*line, int *done);
void		add_node(char *cmd, int already);
void		add_node_to_free(char *cmd);
void		free_last(void);
void		free_linked_list(t_linked *history);
void		write_to_stdout(char *line);
t_linked	*get_previous(void);
t_linked	*get_next(void);
#endif
