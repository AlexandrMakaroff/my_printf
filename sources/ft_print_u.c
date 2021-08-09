/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:24:59 by fgeorgan          #+#    #+#             */
/*   Updated: 2021/01/10 11:45:45 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_null(int ln, int *cnt_chr)
{
	while (ln--)
	{
		ft_putchar(' ');
		(*cnt_chr)++;
	}
}

static int	put_num(size_t i, char *num_str, int cnt_chr)
{
	while (num_str[i])
	{
		ft_putchar(num_str[i++]);
		cnt_chr++;
	}
	return (cnt_chr);
}

static int	put_zero(char *num_str, t_flags *flags, int cnt_chr, size_t i)
{
	if (!(num_str = ft_put_unsigned(flags->width, num_str, flags)))
		return (-1);
	cnt_chr = put_num(i, num_str, cnt_chr);
	free(num_str);
	return (cnt_chr);
}

static int	put_width(t_flags *flags, char *num_str, int cnt_chr, long ln)
{
	if ((flags->width > 0 && flags->minus) || \
	flags->width < 0 || (flags->dot == 1 && flags->len < 0))
	{
		if ((flags->width < 0 && (ln = -(flags->width) - \
		ft_strlen(num_str)) > 0) || (flags->len < 0 && \
		(ln = -(flags->len) - ft_strlen(num_str)) > 0 && !flags->dot) \
		|| (flags->width > 0 && (ln = flags->width - ft_strlen(num_str)) > 0))
			while (ln--)
			{
				ft_putchar(' ');
				cnt_chr++;
			}
	}
	free(num_str);
	return (cnt_chr);
}

int			ft_print_u(t_flags *flags, va_list args)
{
	char			*num_str;
	size_t			i;
	long			ln;
	int				cnt_chr;

	ln = 0;
	cnt_chr = 0;
	i = va_arg(args, size_t);
	if (!(num_str = ft_itoa(i)))
		return (-1);
	i = 0;
	if (flags->dot == 1)
	{
		if (!(num_str = ft_put_unsigned(flags->len, num_str, flags)))
			return (-1);
	}
	else if (flags->zero)
		return (put_zero(num_str, flags, cnt_chr, i));
	if ((flags->width > 0 && !flags->minus) \
	&& (ln = flags->width - ft_strlen(num_str)) > 0)
		put_null(ln, &cnt_chr);
	cnt_chr = put_num(i, num_str, cnt_chr);
	return (put_width(flags, num_str, cnt_chr, ln));
}
