/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 03:17:00 by aouichou          #+#    #+#             */
/*   Updated: 2023/01/05 16:26:35 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_free(char *s, unsigned int start, size_t len, int mod)
{
	char	*str;
	size_t	str_len;
	size_t	i;
	size_t	j;

	j = -1;
	i = ft_strlen(s);
	if (start > i)
		str_len = 0;
	else if (len > (i - start))
		str_len = i - start;
	else
		str_len = len;
	str = (char *)malloc((str_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s && s[++j])
		if (j >= start && i < len)
			str[i++] = s[j];
	str[i] = '\0';
	if (mod == 1)
		free(s);
	return (str);
}
