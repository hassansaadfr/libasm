/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 11:21:57 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/14 11:34:22 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	real_ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *tmp;
	t_list *entry;

	entry = *lst;
	while (entry)
	{
		tmp = entry->next;
		if (del)
		{
			del(entry->content);
		}
		free(entry);
		entry = tmp;
	}
	*lst = NULL;
}
