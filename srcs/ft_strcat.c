/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <anrzepec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:50:45 by anrzepec          #+#    #+#             */
/*   Updated: 2018/09/17 15:50:48 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

char    *ft_strcat(char *full_buff, char *buff)
{
    int     c;
    int     i;
    char    *tmp;

    c = 0;
    i = 0;
    while (full_buff[c])
        c++;
    while (buff[i])
        i++;
    if (!(tmp = (char*)malloc(sizeof(char) * (i + c + 1))))
        return (NULL);
    c = 0;
    while (full_buff[c])
    {
        tmp[c] = full_buff[c];
        c++;
    }
    i = 0;
    while (buff[i])
    {
        tmp[c] = buff[i];
        c++;
        i++;
    }
    tmp[c] = '\0';
    return (tmp);
}
