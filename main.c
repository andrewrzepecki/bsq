/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <anrzepec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:47:21 by anrzepec          #+#    #+#             */
/*   Updated: 2018/09/17 15:47:45 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

int     main(int ac, char **av)
{
    int     max[1];
    int     **map;
    t_elem  elem[1];
    char    **map_print;
    
    max[0] = 0;
    if (ac < 3)
    {
        if (ac == 2)
        {
            if(!(map = ft_init_map(av[1], elem)))
                return (1);
        }
        else
            if(!(map = ft_init_map("randomgiberishfoi_oo.bsQ", elem)))
                return (1);
    }
    else
    {
        ft_putstr("No valid file to open\n");
        return (1);
    }
    map = ft_solve_bsq(map, elem, max);
    map_print = ft_set_map(map, elem, max);
    ft_print_solved(map_print, elem[0].size, elem[0].size_y);
    free(map_print);
    free(map);
    return (0);
}
