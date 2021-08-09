/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:18:04 by fgeorgan          #+#    #+#             */
/*   Updated: 2020/12/28 19:45:17 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcpy(char *str, t_flags *flags)
{
	int		i;
	char	*new_str;

	i = 0;
	while (str[i] && i < flags->len)
		i++;
	if (!(new_str = (char*)malloc((i + 1) * sizeof(*new_str))))
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (str[i] && i < flags->len)
	{
		new_str[i] = str[i];
		i++;
	}
	free(str);
	new_str[i] = '\0';
	return (new_str);
}
