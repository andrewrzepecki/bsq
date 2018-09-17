/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_bsq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <anrzepec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:50:26 by anrzepec          #+#    #+#             */
/*   Updated: 2018/09/17 15:50:27 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

int     ft_set_number(int **map, int x, int y, int *max)
{
    int num;

    num = (map[x][y - 1] < map[x - 1][y - 1]) ? map[x][y - 1] : map[x - 1][y - 1];
    num = (num < map[x - 1][y]) ? num : map[x - 1][y];
    num++;

    max[0] = (num > max[0]) ? num : max[0];
    return (num);
}

int     **ft_solve_bsq(int **map, t_elem *elem, int *max)
{
    int x;
    int y;

    x = 0;
    while (x < elem[0].size)
    {
        y = 0;
        while (y < elem[0].size_y)
        {
            if (map[x][y] == 0)
                y++;
            else if (x == 0 || y == 0)
                y++;
            else
            {
                map[x][y] = ft_set_number(map, x, y, max);
                y++;
            }
        }
        x++;
    }
    return (map);
}
