/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 01:31:31 by kait-baa          #+#    #+#             */
/*   Updated: 2024/01/05 22:29:47 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotation_a(t_stack **stack_a, t_stack *top_node)
{
	while ((*stack_a)->data != (top_node)->data)
	{
		if (top_node->above_below)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
	}
}

void	rotation_b(t_stack **stack_b, t_stack *top_node)
{
	while ((*stack_b)->data != top_node->data)
	{
		if (top_node->above_below)
			rb(stack_b, 1);
		else
			rrb(stack_b, 1);
	}
}

t_stack	*best_node(t_stack *stack_a)
{
	int		best_match_value;
	t_stack	*best_match_node;

	if (NULL == stack_a)
		return (NULL);
	best_match_value = INT_MAX;
	while (stack_a)
	{
		if (stack_a->move < best_match_value)
		{
			best_match_value = stack_a->move;
			best_match_node = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (best_match_node);
}
