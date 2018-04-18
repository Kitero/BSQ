/*
** my_putchar.c for  in /home/Kitero/delivery/CPE_2016_BSQ
** 
** Made by Theo CLEMENT
** Login   <Kitero@epitech.net>
** 
** Started on  Fri Dec  9 14:10:38 2016 Theo CLEMENT
** Last update Mon Dec 12 14:08:21 2016 Theo CLEMENT
*/

#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
