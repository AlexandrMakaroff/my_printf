/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:23:33 by fgeorgan          #+#    #+#             */
/*   Updated: 2020/12/28 19:45:04 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_type(t_flags *flags, va_list args)
{
	int i;

	i = 0;
	if (flags->type == 'c')
		i = ft_print_c(flags, args);
	else if (flags->type == 'd' || flags->type == 'i')
		i = ft_print_d(flags, args);
	else if (flags->type == 's')
		i = ft_print_s(flags, args);
	else if (flags->type == 'x' || flags->type == 'X')
		i = ft_print_x(flags, args);
	else if (flags->type == 'u')
		i = ft_print_u(flags, args);
	else
		i = ft_print_p(flags, args);
	return (i);
}
