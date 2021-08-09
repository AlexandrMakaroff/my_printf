/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:13:13 by fgeorgan          #+#    #+#             */
/*   Updated: 2020/12/28 19:44:43 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(t_flags *flags, va_list args)
{
	char	*str;
	int		cnt_chr;

	cnt_chr = 0;
	if ((str = va_arg(args, char*)) == NULL)
		str = "(null)";
	cnt_chr = ft_put_string(str, flags);
	return (cnt_chr);
}
