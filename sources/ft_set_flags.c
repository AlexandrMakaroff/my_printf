/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:19:14 by fgeorgan          #+#    #+#             */
/*   Updated: 2020/12/29 18:59:04 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_width(const char *str, t_flags *flags, int *i)
{
	int	count;

	count = 0;
	while (ft_isdigit(str[*i]))
	{
		count = count * 10 + (str[*i] - '0');
		(*i)++;
	}
	if (flags->minus == 1)
		flags->width = -count;
	else
		flags->width = count;
}

static int	set_dot_len(const char *str, int *i)
{
	int count;

	count = 0;
	while (ft_isdigit(str[*i]))
	{
		count = count * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (count);
}

static void	set_dot(const char *str, int *i, t_flags *flags, va_list args)
{
	if (str[++(*i)] == '*')
	{
		if ((flags->len = ft_star_arg(args)) < 0)
		{
			flags->dot = -1;
			(*i)++;
			return ;
		}
		(*i)++;
	}
	else
		flags->len = (str[*i] == '-') ? \
		-set_dot_len(str, i + 1) : set_dot_len(str, i);
	flags->dot = 1;
}

static void	set_zero(t_flags *flags, int *i)
{
	flags->zero = 1;
	(*i)++;
}

int			ft_set_flags(const char *str, int i, va_list args, t_flags *flags)
{
	if (str[i] == '0')
		set_zero(flags, &i);
	while (str[i])
	{
		if (str[i] == '-')
			flags->minus = 1;
		if (str[i] == '*')
			flags->width = ft_star_arg(args);
		else if (ft_isdigit(str[i]))
			set_width(str, flags, &i);
		if (str[i] == '.')
		{
			set_dot(str, &i, flags, args);
			continue;
		}
		if (ft_isalpha(str[i]) || str[i] == '%')
		{
			flags->type = (str[i] == '%') ? '%' : str[i];
			break ;
		}
		i++;
	}
	return (i + 1);
}
