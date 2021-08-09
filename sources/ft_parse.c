/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 16:30:48 by fgeorgan          #+#    #+#             */
/*   Updated: 2020/12/29 22:10:05 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_percent(char c, int *i, int *count)
{
	if (c == '%')
	{
		ft_putchar(c);
		(*i)++;
		(*count)++;
		return (1);
	}
	return (0);
}

static void	put_ordinary_chars(const char *str, int *i, int *count)
{
	ft_putchar(str[*i]);
	(*i)++;
	(*count)++;
}

int			ft_parse(const char *str, va_list args)
{
	int		i;
	int		count;
	t_flags	flags;
	int		check;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			if (check_percent(str[++i], &i, &count))
				continue;
			flags = ft_init_flags();
			i = ft_set_flags(str, i, args, &flags);
			if ((check = ft_put_type(&flags, args)) == -1)
				return (-1);
			count += check;
			continue;
		}
		put_ordinary_chars(str, &i, &count);
	}
	return (count);
}
