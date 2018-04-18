/*
** my.h for  in /home/Kitero/delivery/CPE_2016_BSQ
** 
** Made by Theo CLEMENT
** Login   <Kitero@epitech.net>
** 
** Started on  Tue Dec  6 15:17:08 2016 Theo CLEMENT
** Last update Wed Dec 14 14:47:00 2016 Theo CLEMENT
*/

#ifndef _MY_H_
# define _MY_H_

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1

typedef struct	s_struct
{
  int		x;
  int		y;
  int		value;
}		t_struct;

typedef struct	s_struct2
{
  int		i;
  int		j;
  int		k;
  int		readi;
}		t_struct2;

int	nb_lines(int fd);
int     **alloc(int **tab, int nb_line, int sz_line);
int     sz_lines(int fd);
int     nb_lines(int fd);
void    disp(int **tab, int nb_line, int sz_line);
int     str_to_tab(int fd, int nb_line, int sz_line);
int     convert(int **tab, int nb_line, int sz_line);
int     squarre_det(int **tab, int nb_line, int sz_line);
int     squarre_create(int **tab, int nb_line, int sz_line, t_struct stt);
void	my_putchar(char c);
int	sort(char buffer);
void    init_stt(t_struct2 *stt);

#endif /* !_MY_H_ */
