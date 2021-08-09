/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:57:30 by fgeorgan          #+#    #+#             */
/*   Updated: 2020/12/27 18:41:52 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_copy(char *s1, char *s2, char *fresh)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i])
		fresh[j++] = s1[i++];
	i = 0;
	while (s2[i])
		fresh[j++] = s2[i++];
	fresh[j] = '\0';
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*fresh;

	if (!s1 || !s2)
	{
		if (!s1 && s2)
		{
			free(s2);
			return (NULL);
		}
		if (!s2 && !s1)
			return (NULL);
		free(s1);
		return (NULL);
	}
	if (!(fresh = (char *)malloc((ft_strlen(s1) +
	ft_strlen(s2) + 1) * sizeof(*fresh))))
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	ft_copy(s1, s2, fresh);
	free(s1);
	free(s2);
	return (fresh);
}
