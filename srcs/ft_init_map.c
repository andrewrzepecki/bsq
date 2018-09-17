/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <anrzepec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:48:30 by anrzepec          #+#    #+#             */
/*   Updated: 2018/09/17 15:48:35 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

int     ft_skip_first(char *str)
{
    int x;

    x = 0;
    while (str[x] != '\n')
        x++;
    return (x + 1);
}

t_elem  *ft_init_elem(char *full_buff, t_elem *elem)
{
    int x;
    int c;

    x = 0;
    c = 0;
    elem[0].size = 0;
    while (full_buff[x] != '\n')
    {
        while (full_buff[x] >= '0' && full_buff[x] <= '9')
        {
            elem[0].size = elem[0].size * 10 + (full_buff[x] - 48);
            x++;
        }
        elem[0].free = full_buff[x++];
        elem[0].obs = full_buff[x++];
        elem[0].square = full_buff[x++];
    }
    while (full_buff[++x] != '\n')
        c++;
    elem[0].size_y = c;
    return (elem);
}

int     **ft_init_map(char *file_name, t_elem *elem)
{
    int     fd;
    int     c;
    int     i;
    int     x;
    int     ret;
    char    buff[BUFF_SIZE + 1];
    char    *full_buff;
    int     **map;

    if((fd = open(file_name, O_RDONLY)) == -1)
        fd = 0;

    if (!(full_buff = (char*)malloc(sizeof(char) * 1)))
        return (NULL);
    full_buff[0] = '\0';

    while ((ret = read(fd, buff, BUFF_SIZE)))
    {
        if (ret == -1)
        {
            write(2, "read() error\n", 13);
            return (NULL);
        }
        buff[ret] = '\0';
        full_buff = ft_strcat(full_buff, buff);
    }
    elem = ft_init_elem(full_buff, elem);
    if (!(map = (int**)malloc(sizeof(int*) * elem[0].size)))
        return (NULL);
    c = 0;
    while (c < elem[0].size)
    {
        if (!(map[c] = (int*)malloc(sizeof(int) * elem[0].size_y)))
            return (NULL);
        c++;
    }
    c = 0;
    x = ft_skip_first(full_buff);
    while(full_buff[x])
    {
        i = 0;
        while (full_buff[x] != '\n')
        {
            if (full_buff[x] == elem[0].free)
                map[c][i] = 1;
            if (full_buff[x] == elem[0].obs)
                map[c][i] = 0;
            x++;
            i++;
        }
        c++;
        x++;
    }
    free(full_buff);
    return (map);
}
