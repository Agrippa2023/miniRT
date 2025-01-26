/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:19:10 by aouichou          #+#    #+#             */
/*   Updated: 2023/08/17 09:19:21 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** @brief Searches if a node in lst contains content and returns it.
 * In case content is not in lst, NULL is returned.
 * @param lst The list to search.
 * @param contnt The node to be found.
 * @return A pointer to the node in list or NULL.*/
t_list	*ft_lstfind(t_list *lst, void *content)
{
	while (lst != NULL && content != NULL)
	{
		if (lst->content == content)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
