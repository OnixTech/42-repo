/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <lupetill@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:35:48 by luciano           #+#    #+#             */
/*   Updated: 2025/12/10 14:03:33 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*node;
	void	*content;

	if (!f || !del)
		return (NULL);
	nlst = NULL;
	while (lst)
	{
		content = f(lst->content);
		node = ft_lstnew(content);
		if (!node)
		{
			del(content);
			ft_lstclear(&nlst, del);
			return (NULL);
		}
		ft_lstadd_back(&nlst, node);
		lst = lst->next;
	}
	return (nlst);
}
/*
#include <stdio.h>

void	*tox(void *ptr)
{
	(void)ptr;
	return ("X");
}

int	main(void)
{
	char    *a = " como";
	char    *b = " estas";
	char    *c = " loco";
	char    *d = "?";
	char    *x = "Hola,";

	t_list  *n1;
	t_list  *n2;
	t_list  *n3;
	t_list  *n4;
	t_list  *head;

	n1 = ft_lstnew(ft_strdup(a));
	n2 = ft_lstnew(ft_strdup(b));
	n3 = ft_lstnew(ft_strdup(c));
	n4 = ft_lstnew(ft_strdup(d));

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	head = n1;

	t_list *nx = ft_lstnew(ft_strdup(x));
	ft_lstadd_front(&head, nx);
	t_list *tmp = head;
	while (tmp)
	{
		printf("%s", (char *)tmp->content);
				tmp = tmp->next;
	}
	printf("\nNew list:\n->");
	t_list *ntmp = ft_lstmap(head, tox, free);
	while (ntmp)
	{
				printf("%s", (char *)ntmp->content);
				ntmp = ntmp->next;
	}
	printf("\n");
	return (0);
}*/
