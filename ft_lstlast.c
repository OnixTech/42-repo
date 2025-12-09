/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <lupetill@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:40:19 by luciano           #+#    #+#             */
/*   Updated: 2025/12/09 18:51:11 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
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
	ft_lstadd_front(&head, nx);
	t_list *tmp = ft_lstlast(head);
	printf("%s", (char *)tmp->content);
	printf("\n");
	return (0);
}*/
