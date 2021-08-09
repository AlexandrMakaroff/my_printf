/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:23:41 by fgeorgan          #+#    #+#             */
/*   Updated: 2020/12/28 19:45:01 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_dot(char *str, int cnt_chr, int *i, t_flags *flags)
{
	while (*i > flags->len)
	{
		ft_putchar(' ');
		(*i)--;
		cnt_chr++;
	}
	free(str);
	return (cnt_chr);
}

static void	put_null(char *str, t_flags *flags, int *count)
{
	int ln;

	ln = ft_strlen(str);
	while (ln < flags->width)
	{
		ft_putchar(' ');
		ln++;
		(*count)++;
	}
}

static int	put_minus(char *str, int cnt_chr, int *i, t_flags *flags)
{
	int ln;

	ln = ft_strlen(str);
	while (str[*i])
	{
		ft_putchar(str[(*i)++]);
		cnt_chr++;
	}
	if (flags->width < 0)
		flags->width = -(flags->width);
	put_null(str, flags, &cnt_chr);
	free(str);
	return (cnt_chr);
}

int			ft_put_string(char *str, t_flags *flags)
{
	int i;
	int cnt_chr;

	i = 0;
	cnt_chr = 0;
	if (!(str = ft_strdup(str)))
		return (-1);
	if (flags->dot == 1)
	{
		if (flags->len < 0)
			return (put_dot(str, cnt_chr, &i, flags));
		if (!(str = ft_strcpy(str, flags)))
			return (-1);
	}
	if (flags->minus || flags->width < 0)
		return (put_minus(str, cnt_chr, &i, flags));
	else if (flags->width > 0)
		put_null(str, flags, &cnt_chr);
	while (str[i])
	{
		ft_putchar(str[i++]);
		cnt_chr++;
	}
	free(str);
	return (cnt_chr);
}
