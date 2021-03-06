/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <anrzepec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:49:24 by anrzepec          #+#    #+#             */
/*   Updated: 2018/09/17 15:49:27 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

void    ft_putstr(char *str)
{
    int c;

    c = -1;
    while (str[++c])
        ft_putchar(str[c]);
}
