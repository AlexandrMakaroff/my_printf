/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:09:58 by fgeorgan          #+#    #+#             */
/*   Updated: 2021/04/24 05:41:05 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_len_minus(int cnt_chr, int len, size_t i, char *str)
{
	while ((int)i > len)
	{
		ft_putchar(' ');
		i--;
		cnt_chr++;
	}
	free(str);
	return (cnt_chr);
}

static int	put_minus_width(char *str, int cnt_chr, size_t i, t_flags *flags)
{
	int ln;

	ln = ft_strlen(str);
	while (str[i])
	{
		ft_putchar(str[i++]);
		cnt_chr++;
	}
	if (flags->width < 0)
		flags->width = -(flags->width);
	while (ln < flags->width)
	{
		ft_putchar(' ');
		ln++;
		cnt_chr++;
	}
	free(str);
	return (cnt_chr);
}

static int	putchar_pointer(char *str, int cnt_chr, t_flags *flags, size_t i)
{
	int ln;

	ln = ft_strlen(str);
	if (flags->zero)
		while (--flags->width)
		{
			ft_putchar('0');
			cnt_chr++;
		}
	if (flags->minus || flags->width < 0)
		return (put_minus_width(str, cnt_chr, i, flags));
	else if (flags->width > 0)
		while (ln < flags->width)
		{
			ft_putchar(' ');
			ln++;
			cnt_chr++;
		}
	while (str[i])
	{
		ft_putchar(str[i++]);
		cnt_chr++;
	}
	free(str);
	return (cnt_chr);
}

static int	wrapper(char *str, const char *sub_str)
{
	free(str);
	if (!(str = ft_strdup(sub_str)))
		return (0);
	return (1);
}

int			ft_print_p(t_flags *flags, va_list args)
{
	char	*str;
	int		cnt_chr;
	size_t	i;

	cnt_chr = 0;
	i = va_arg(args, size_t);
	if (!(str = ft_strjoin(ft_strdup("0x"), ft_to_hex(i, flags->type))))
		return (-1);
	i = 0;
	if (flags->type == '%')
		if (!(wrapper(str, "%")))
			return (-1);
	if (flags->dot == 1)
	{
		if (flags->len < 0)
			return (put_len_minus(cnt_chr, flags->len, i, str));
		if (!ft_strncmp(str, "0x0", 3))
			if (!(wrapper(str, "0x")))
				return (-1);
	}
	return (putchar_pointer(str, cnt_chr, flags, i));
}
