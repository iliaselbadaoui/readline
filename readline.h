/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 11:49:33 by ielbadao          #+#    #+#             */
/*   Updated: 2021/03/27 14:25:03 by ielbadao         ###   ########.fr       */
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
# include <stdlib.h>
# include <stdio.h>
# include <termcap.h>
# include <termios.h>
# include <unistd.h>

/*
* Globale variables
*/
char		g_termcap_buffer[2048];
struct termios g_init;
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
int			init_caps();
int			ft_getchar();
char		*readline();
#endif
