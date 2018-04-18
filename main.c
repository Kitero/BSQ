/*
** main.c for  in /home/Kitero/delivery/CPE_2016_BSQ
** 
** Made by Theo CLEMENT
** Login   <Kitero@epitech.net>
** 
** Started on  Thu Dec  1 10:27:26 2016 Theo CLEMENT
** Last update Sun Dec 18 17:46:31 2016 Theo CLEMENT
*/

#include "my.h"

int	sz_lines(int fd)
{
  int	i;
  int	k;
  char	buffer;

  i = 0;
  if ((k = read(fd, &buffer, 1)) == -1)
    return (84);
  while (k != -1 && buffer != '\n')
    {
      if ((k = read(fd, &buffer, 1)) == -1)
	return (-1);
      i++;
    }
  return (i);
}

int	nb_lines(int fd)
{
  int	i;
  int	k;
  char	buffer;

  i = 0;
  if ((k = read(fd, &buffer, 1)) == -1)
    return (-1);
  i = ((i + (buffer - 48)) * 10);
  while (read(fd, &buffer, 1) != -1 && buffer != '\n')
    {
      i = ((i + (buffer - 48)) * 10);
    }
  i = i / 10;
  return (i);
}

void	disp(int **tab, int nb_line, int sz_line)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i < nb_line)
    {
      if (tab[i][j] == 0)
	my_putchar('o');
      else if (tab[i][j] == -1)
	my_putchar('x');
      else if (tab[i][j] == -2)
	my_putchar('\n');
      else
	my_putchar('.');
      j++;
      if (j == sz_line)
	{
	  j = 0;
	  i++;
	}
    }
}

int		str_to_tab(int fd, int nb_line, int sz_line)
{
  t_struct2	stt;
  char		buffer;
  int		**tab;

  init_stt(&stt);
  if ((tab = alloc(tab, nb_line, sz_line)) == NULL)
    return (84);
  if ((stt.readi = read(fd, &buffer, 1)) == -1)
    return (84);
  while (stt.readi > 0)
    {
      if (sort(buffer) == 84)
	return (84);
      tab[stt.i][stt.j] = sort(buffer);
      stt.j++;
      if (buffer == '\n')
	{
	  stt.j = 0;
	  stt.i++;
	}
      if ((stt.readi = read(fd, &buffer, 1)) == -1)
	return (84);
    }
  convert(tab, nb_line, sz_line);
  return (0);
}

int	main(int ac, char **av)
{
  int	fd;
  int	nb_line;
  int	sz_line;

  if (ac != 2 || (fd = open(av[1], O_RDONLY)) == -1)
    return (84);
  if ((nb_line = nb_lines(fd)) == -1 || (sz_line = sz_lines(fd) + 1) == -1)
    return (84);
  close (fd);
  if ((fd = open(av[1], O_RDONLY)) == -1 || (nb_line = nb_lines(fd)) == -1)
    return (84);
  if ((str_to_tab(fd, nb_line, sz_line)) == 84)
    return (84);
  close (fd);
  return (0);
}
