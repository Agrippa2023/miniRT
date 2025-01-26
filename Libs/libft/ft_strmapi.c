/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 00:40:40 by aouichou          #+#    #+#             */
/*   Updated: 2022/05/06 00:42:32 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	z;

	z = 0;
	if (s)
	{
		str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
		if (!str)
			return (NULL);
		while (s[z])
		{
			str[z] = f(z, s[z]);
			z++;
		}
		str[z] = '\0';
		return (str);
	}
	return (NULL);
}
