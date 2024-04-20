/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 01:31:44 by kait-baa          #+#    #+#             */
/*   Updated: 2024/01/02 05:17:01 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_mylstadd_back(t_stack **list, t_stack *new)
{
	t_stack	*ptr;

	if (!(*list))
	{
		*list = new;
		return ;
	}
	ptr = *list;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = new;
	new->prev = ptr;
	new->next = NULL;
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*head;

	if (lst == NULL)
		return (NULL);
	head = lst;
	while (head->next != NULL)
	{
		head = head->next;
	}
	return (head);
}

int	ft_mylstsize(t_stack *lst)
{
	int		count;
	t_stack	*ptr;

	count = 0;
	ptr = lst;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		count++;
	}
	return (count);
}

t_stack	*find_smallest(t_stack *stack_x)
{
	long	smallest;
	t_stack	*smallest_node;

	if (NULL == stack_x)
		return (NULL);
	smallest = LONG_MAX;
	while (stack_x)
	{
		if (stack_x->data < smallest)
		{
			smallest = stack_x->data;
			smallest_node = stack_x;
		}
		stack_x = stack_x->next;
	}
	return (smallest_node);
}

t_stack	*find_largest(t_stack *stack_x)
{
	int		largest;
	t_stack	*largest_node;

	largest = INT_MIN;
	largest_node = NULL;
	if (stack_x == NULL)
		return (NULL);
	while (stack_x)
	{
		if (stack_x->data > largest)
		{
			largest = stack_x->data;
			largest_node = stack_x;
		}
		stack_x = stack_x->next;
	}
	return (largest_node);
}
