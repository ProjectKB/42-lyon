/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   puissance4.h                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/01 10:23:34 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/02 21:34:50 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PUISSANCE4_H
# define PUISSANCE4_H

# include <stdlib.h>
# include <time.h>
# include <stdio.h>
# include "../libft/libft.h"

int			create_board(int x, int y);
void		ft_free2dtab(char **board, int i);
void		ft_usage(void);
void		ft_usage_play(void);
void		draw_map(char **board, int x, int y);
void		lets_play(char **str, int x, int y, int start);
int			check_input(char**board, int nb, int y);
void		put_coin(char **board, int x, int y, char c);
int			check_win(char **board, int y, int x);
int			check_win_line(char **board, int y, int x, char c);
int			check_win_column(char **board, int y, int x, char c);
int			check_win_diagonal(char **board, int y, int x, char c);
int			check_draw(char **board, int y);
void		solve(char **str, int x, int y, int ctr);
int			check_threat_line(char **board, int y, int x);
int			check_threat_line_trap(char **board, int y);
int			check_threat_column(char **board, int y, int x);
int			check_threat_diagonal(char **board, int y, int x);
int			check_threat_diagonal_bis(char **board, int y, int x, int c);
int			check_threat_line_bis(char **board, int y, int x, int c);
int			find_threat(char a, char b, char c);
int			check_under_threat(char a, char b, char c, char d);
int			check_threat_block(char a, char b, char c, char d);
int			check_threat_block_line_trap(char **board, int i, int c);
int			check_threat_block_line(char a, char b, char c, char d);
int			check_strat(char **board, int y, int i);
int			check_threat(char **str, int y, int x);
int			column_is_full(char **board, int y, int x);
int			give_win(char **board, int x, int y);

#endif
