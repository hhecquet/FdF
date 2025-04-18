/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:02:52 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/13 10:10:19 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}
/* t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
t_list	*ft_lstnew(void *content)
{
	t_list	*str;

	str = (t_list *)malloc(sizeof(t_list));
	if (!str)
		return (NULL);
	str->content = content;
	str->next = NULL;
	return (str);
}
#include <stdio.h>
#include <stdlib.h>
int main() {
    t_list *list = NULL;
	int *value1 = (int *)malloc(sizeof(int));
    *value1 = 10;
    t_list *node1 = ft_lstnew(value1);
	int *value2 = (int *)malloc(sizeof(int));
    *value2 = 20;
    t_list *node2 = ft_lstnew(value2);
	int *value3 = (int *)malloc(sizeof(int));
    *value3 = 30;
    t_list *node3 = ft_lstnew(value3);

    ft_lstadd_front(&list, node1);
    ft_lstadd_front(&list, node2);
    ft_lstadd_front(&list, node3);
	t_list *current = list;
	
    while (current)
	{
        printf("%d -> ", *(int *)(current->content));  
        current = current->next;
    }
    printf("NULL\n");
	current = list;
    while (current)
	{
        t_list *tmp = current;
        current = current->next;
        free(tmp->content); 
        free(tmp);  
    }
    return 0;
}  */