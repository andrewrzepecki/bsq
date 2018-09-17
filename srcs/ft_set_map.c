/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <anrzepec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:50:11 by anrzepec          #+#    #+#             */
/*   Updated: 2018/09/17 15:50:13 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

char    **ft_set_square(char **print_map, int x, int y, int num, t_elem *elem)
{
    int c;
    int i;
    int t_y;

    c = 0;
    t_y = y;
    while (c < num)
    {
        i = 0;
        y = t_y;
        while (i < num)
        {
            print_map[x][y] = elem[0].square;
            y--;
            i++;
        }
        c++;
        x--;
    }
    return (print_map);
}

char    **ft_set_map(int **map, t_elem *elem, int *max)
{
    int     x;
    int     y;
    int     set;
    char    **print_map;

    if (!(print_map = (char**)malloc(sizeof(char*) * (elem[0].size))))
        return (NULL);
    x = -1;
    while (++x < elem[0].size)
        if (!(print_map[x] = (char*)malloc(sizeof(char) * (elem[0].size_y + 1))))
            return (NULL);
    x = 0;
    set = 1;
    while (x < elem[0].size)
     {
         y = 0;
         while (y < elem[0].size_y)
         {
             if (map[x][y] == 0)
                 print_map[x][y] = elem[0].obs;
             else if (map[x][y] == max[0] && set)
             {
                print_map = ft_set_square(print_map, x, y, max[0], elem);
                set = 0;
             }
             else
                 print_map[x][y] = elem[0].free;
             y++;
         }
         print_map[x][y] = '\0';
         x++;
     }
    return (print_map);
}
