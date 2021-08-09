/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 16:34:54 by fgeorgan          #+#    #+#             */
/*   Updated: 2020/12/30 20:42:02 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(t_flags *flags, va_list args)
{
	int	i;
	int	cnt_chr;

	cnt_chr = 0;
	if ((i = flags->width) > 0 && flags->minus != 1)
	{
		while (i && --i)
		{
			ft_putchar(' ');
			cnt_chr++;
		}
	}
	ft_putchar(va_arg(args, int));
	cnt_chr++;
	if (flags->minus == 1 || flags->width < 0)
	{
		if ((i = flags->width) < 0)
			i = -i;
		while (i && --i)
		{
			ft_putchar(' ');
			cnt_chr++;
		}
	}
	return (cnt_chr);
}
