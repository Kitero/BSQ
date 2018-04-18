/*
** convert.c for  in /home/Kitero/delivery/CPE_2016_BSQ
** 
** Made by Theo CLEMENT
** Login   <Kitero@epitech.net>
** 
** Started on  Wed Dec  7 13:05:51 2016 Theo CLEMENT
** Last update Fri Dec 16 17:03:30 2016 Theo CLEMENT
*/

#include "my.h"

void	free_tab(int **tab, int nb_line, int sz_line)
{
  int	i;

  i = 0;
  while (i < nb_line)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}

int	convert(int **tab, int nb_line, int sz_line)
{
  int	i;
  int	j;

  i = 1;
  j = 1;
  while (i < nb_line && j < sz_line)
    {
      if (tab[i][j] == 1)
	{
	  tab[i][j] = tab[i - 1][j] + 1;
	  if (tab[i][j] > tab[i - 1][j - 1])
	    tab[i][j] = tab[i - 1][j - 1] + 1;
	  if (tab[i][j] > tab[i][j - 1])
	    tab[i][j] = tab[i][j - 1] + 1;
	}
      j++;
      if (j == sz_line)
	{
	  j = 1;
	  i++;
	}
    }
  squarre_det(tab, nb_line, sz_line);
}

int	squarre_det(int **tab, int nb_line, int sz_line)

{
  int		i;
  int		j;
  t_struct	stt;

  i = 0;
  j = 0;
  stt.value = 0;
  while (i < nb_line && j < sz_line)
    {
      if (stt.value < tab[i][j] && tab[i][j] != 0)
	{
	  stt.y = i;
	  stt.x = j;
	  stt.value = tab[i][j];
	}
      j++;
      if (j == sz_line)
	{
	  j = 0;
	  i++;
	}
    }
  squarre_create(tab, nb_line, sz_line, stt);
}

int	squarre_create(int **tab, int nb_line, int sz_line, t_struct stt)
{
  int	i;
  int	j;
  int	k;
  int	l;

  i = stt.y;
  j = stt.x;
  k = 1;
  l = 1;
  if (stt.value != 0)
    {
      tab[i][j] = -1;
      while (j >= (stt.x - stt.value) && i > (stt.y - stt.value))
	{
	  tab[i][j] = -1;
	  j--;
	  if (j == (stt.x - stt.value))
	    {
	      j = stt.x;
	      i--;
	    }
	}
    }
  disp(tab, nb_line, sz_line);
  free_tab(tab, nb_line, sz_line);
}
