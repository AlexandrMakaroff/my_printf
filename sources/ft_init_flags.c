/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 16:27:17 by fgeorgan          #+#    #+#             */
/*   Updated: 2020/12/28 19:44:21 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_init_flags(void)
{
	t_flags flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.width = 0;
	flags.len = 0;
	flags.dot = 0;
	flags.type = 0;
	return (flags);
}
