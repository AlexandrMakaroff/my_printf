/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:21:58 by fgeorgan          #+#    #+#             */
/*   Updated: 2021/01/10 11:49:18 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_put(char *str, char *new_num, int ln, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
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

char		*ft_put_unsigned(size_t size, char *str, t_flags *flags)
{
	size_t	ln;
	char	*new_num;

	if (size == 0 && !ft_strncmp(str, "0", 1) && flags->dot == 1)
	{
		free(str);
		return (ft_strdup(""));
	}
	if (!(new_num = (char *)malloc((size + 1) * sizeof(*new_num))))
	{
		free(str);
		return (NULL);
	}
	if (size > 0 && (ln = size - ft_strlen(str)) > 0)
		return (ft_put(str, new_num, ln, size));
	free(new_num);
	return (str);
}
