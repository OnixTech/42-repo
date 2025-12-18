/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <lupetill@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:32:57 by luciano           #+#    #+#             */
/*   Updated: 2025/12/10 12:19:17 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	node = *lst;
	while (node)
	{
		tmp = node->next;
		del(node->content);
		free(node);
		node = tmp;
	}
	*lst = NULL;
}
/*
#include <stdio.h>

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
	printf("\nAfter call ft_lstclear:\n->");
	ft_lstclear(&head, free);
	tmp = head;
	while (tmp)
	{
				printf("%s", (char *)tmp->content);
				tmp = tmp->next;
	}
	printf("\n");
	return (0);
}*/
