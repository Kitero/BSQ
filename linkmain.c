/*
** linkmain.c for  in /home/Kitero/delivery/CPE_2016_BSQ
** 
** Made by Theo CLEMENT
** Login   <Kitero@epitech.net>
** 
** Started on  Fri Dec  9 14:35:46 2016 Theo CLEMENT
** Last update Wed Dec 14 14:46:26 2016 Theo CLEMENT
*/

#include "my.h"

int	sort(char buffer)
{
  if (buffer == 'o')
    return (0);
  if (buffer == '\n')
    return (-2);
  else if (buffer == '.')
    return (1);
  else
    return (84);
}

void	init_stt(t_struct2 *stt)
{
  stt->k = 0;
  stt->i = 0;
  stt->j = 0;
}

int	**alloc(int **tab, int nb_line, int sz_line)
{
  int	i;

  i = 0;
  if ((tab = malloc(sizeof(int *) * nb_line)) == NULL)
    exit(EXIT_FAILURE);
  while (i < nb_line)
    {
      if ((tab[i] = malloc(sizeof(int) * (sz_line + 0))) == NULL)
	exit(EXIT_FAILURE);
      i++;
    }
  return (tab);
}
