/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <lupetill@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:54:16 by luciano           #+#    #+#             */
/*   Updated: 2025/12/09 19:23:38 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return;
	}
	node = *lst;
	while (node->next)
		node = node->next;
	node->next = new;
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

		n1 = ft_lstnew(a);
		n2 = ft_lstnew(b);
		n3 = ft_lstnew(c);
		n4 = ft_lstnew(d);

		n1->next = n2;
		n2->next = n3;
		n3->next = n4;
		head = n1;

		t_list *nx = ft_lstnew(x);
		ft_lstadd_back(&head, nx);
		t_list *tmp = head;
		while (tmp)
		{
				printf("%s", (char *)tmp->content);
				tmp = tmp->next;
		}
		printf("\n");
		return (0);
}*/
