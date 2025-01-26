/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:47:06 by aouichou          #+#    #+#             */
/*   Updated: 2022/05/06 02:04:51 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	str_len;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
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
	while (s[++j])
		if (j >= start && i < len)
			str[i++] = s[j];
	str[i] = '\0';
	return (str);
}
