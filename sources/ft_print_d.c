/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 16:57:39 by fgeorgan          #+#    #+#             */
/*   Updated: 2020/12/30 20:42:56 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_num(char *num_str, int cnt_chr)
{
	int i;

	i = 0;
	while (num_str[i])
	{
		ft_putchar(num_str[i++]);
		cnt_chr++;
	}
	return (cnt_chr);
}

static int	treat_zero(t_flags *flags, char *num_str)
{
	int	cnt_chr;
	int i;

	i = 0;
	cnt_chr = 0;
	if (num_str[0] == '-')
		num_str = ft_put_integer(flags->width - 1, num_str);
	else
		num_str = ft_put_integer(flags->width, num_str);
	if (!(num_str))
		return (-1);
	while (num_str[i])
	{
		ft_putchar(num_str[i++]);
		cnt_chr++;
	}
	free(num_str);
	return (cnt_chr);
}

static char	*treat_dot(char *num_str, t_flags *flags)
{
	if (!(ft_strncmp(num_str, "0", 1)) && flags->len == 0)
		return (ft_strdup(""));
	else
		return (ft_put_integer(flags->len, num_str));
}

static int	put_width(t_flags *flags, char *num_str, int cnt_chr, long ln)
{
	if ((flags->width > 0 && flags->minus) || \
	flags->width < 0 || (flags->dot == 1 && flags->len < 0))
	{
		if ((flags->width < 0 && (ln = -(flags->width) - \
		ft_strlen(num_str)) > 0) || (flags->len < 0 && \
		(ln = -(flags->len) - ft_strlen(num_str)) > 0 && !flags->dot) || \
		(flags->width > 0 && (ln = flags->width - ft_strlen(num_str)) > 0))
			while (ln--)
			{
				ft_putchar(' ');
				cnt_chr++;
			}
	}
	free(num_str);
	return (cnt_chr);
}

int			ft_print_d(t_flags *flags, va_list args)
{
	char	*num_str;
	int		cnt_chr;
	int		ln;
	int		i;

	cnt_chr = 0;
	i = va_arg(args, int);
	if (!(num_str = ft_itoa(i)))
		return (-1);
	if (flags->dot == 1)
	{
		if (!(num_str = treat_dot(num_str, flags)))
			return (-1);
	}
	else if (flags->zero && flags->width >= 0)
		return (treat_zero(flags, num_str));
	if ((ln = flags->width - ft_strlen(num_str)) > 0 \
	&& (flags->width > 0 && !flags->minus))
		while (ln--)
		{
			ft_putchar(' ');
			cnt_chr++;
		}
	cnt_chr = put_num(num_str, cnt_chr);
	return (put_width(flags, num_str, cnt_chr, ln));
}
