/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 16:23:39 by fgeorgan          #+#    #+#             */
/*   Updated: 2021/01/10 11:53:11 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		count;
	char	*str;
	va_list args;

	if (!format)
		return (-1);
	if (!(str = ft_strdup(format)))
		return (-1);
	va_start(args, format);
	count = ft_parse(str, args);
	va_end(args);
	free(str);
	return (count);
}

// int main()
// {
// 	ft_printf("wqtefyejdj kfjwefkw %10s frkrfm %1.4d");
// 	return 0;
// }