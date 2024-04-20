/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_myoperations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 01:30:56 by kait-baa          #+#    #+#             */
/*   Updated: 2024/01/04 03:51:54 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **list)
{
	int	temp;

	if (*list != NULL && (*list)->next != NULL)
	{
		temp = (*list)->data;
		(*list)->data = (*list)->next->data;
		(*list)->next->data = temp;
	}
	ft_putstr("sa\n");
}

void	sb(t_stack **list)
{
	int	temp;

	if (*list != NULL && (*list)->next != NULL)
	{
		temp = (*list)->data;
		(*list)->data = (*list)->next->data;
		(*list)->next->data = temp;
	}
	ft_putstr("sb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	ft_putstr("rrr\n");
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*new_node;
	t_stack	*temp;

	if (*stack_b)
	{
		new_node = ft_mylstnew((*stack_b)->data);
		ft_mylstadd_front(stack_a, new_node);
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		free(temp);
		temp = NULL;
	}
	ft_putstr("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*new_node;
	t_stack	*temp;

	if (*stack_a)
	{
		new_node = ft_mylstnew((*stack_a)->data);
		ft_mylstadd_front(stack_b, new_node);
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(temp);
	}
	ft_putstr("pb\n");
}
