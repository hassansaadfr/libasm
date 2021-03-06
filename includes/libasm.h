/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:08:40 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/14 11:24:45 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBASM_H
# define _LIBASM_H

# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int			real_ft_lstsize(t_list *lst);
void		real_ft_lstclear(t_list **lst, void (*del)(void*));
t_list		*real_ft_lstlast(t_list *lst);

size_t		ft_strlen(char *str);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strdup(const char *s);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fd, const void *buf, size_t count);
ssize_t		ft_read(int fd, void *buf, size_t count);
int			ft_list_size(t_list *begin_list);

#endif
