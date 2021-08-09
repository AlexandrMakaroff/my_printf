/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:17:07 by fgeorgan          #+#    #+#             */
/*   Updated: 2020/12/30 17:42:00 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_to_hex(long i, char type)
{
	if (i < 16)
	{
		if ((i %= 16) < 10)
			return (ft_itoa(i));
		else
		{
			if (i == 10)
				return (type == 'X') ? ft_strdup("A") : ft_strdup("a");
			if (i == 11)
				return (type == 'X') ? ft_strdup("B") : ft_strdup("b");
			if (i == 12)
				return (type == 'X') ? ft_strdup("C") : ft_strdup("c");
			if (i == 13)
				return (type == 'X') ? ft_strdup("D") : ft_strdup("d");
			if (i == 14)
				return (type == 'X') ? ft_strdup("E") : ft_strdup("e");
			if (i == 15)
				return (type == 'X') ? ft_strdup("F") : ft_strdup("f");
		}
	}
	return (ft_strjoin(ft_to_hex(i / 16, type), ft_to_hex(i % 16, type)));
}
