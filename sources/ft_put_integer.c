/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:23:55 by fgeorgan          #+#    #+#             */
/*   Updated: 2020/12/29 19:13:18 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*pt_int(char *str, char *new_num, int ln, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[0] == '-')
	{
		new_num[i++] = '-';
		j++;
		ln++;
		size++;
	}
	while (ln)
	{
		new_num[i++] = '0';
		ln--;
	}
	while (i < size)
	{
		new_num[i++] = str[j++];
	}
	new_num[i] = '\0';
	free(str);
	return (new_num);
}

char		*ft_put_integer(int size, char *str)
{
	int		ln;
	char	*new_num;

	if (!(new_num = (char *)malloc((size + 1) * sizeof(*new_num))))
	{
		return (str);
	}
	if (size > 0 && (ln = size - ft_strlen(str)) >= 0)
		return (pt_int(str, new_num, ln, size));
	free(new_num);
	return (str);
}
