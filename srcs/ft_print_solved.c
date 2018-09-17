/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_solved.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <anrzepec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:48:46 by anrzepec          #+#    #+#             */
/*   Updated: 2018/09/17 15:48:48 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

void    ft_print_solved(char **map, int size, int y)
{
    int x;

    x = -1;
    while (++x < size)
    {
        ft_putstrb(map[x], y);
        ft_putchar('\n');
    }
}
