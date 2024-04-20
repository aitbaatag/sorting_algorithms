/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 01:31:36 by kait-baa          #+#    #+#             */
/*   Updated: 2024/01/06 03:26:17 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	push_to_stack_b(t_stack **stack_a, t_stack **stack_b, int i)
{
	t_stack	*best_node_x;

	best_node_x = best_node(*stack_a);
	if (best_node_x->above_below && best_node_x->target_node->above_below)
		while ((*stack_b)->data != best_node_x->target_node->data
			&& (*stack_a)->data != best_node_x->data)
			rr(stack_a, stack_b);
	else if (!(best_node_x->above_below)
		&& !(best_node_x->target_node->above_below))
		while ((*stack_b)->data != best_node_x->target_node->data
			&& (*stack_a)->data != best_node_x->data)
			rrr(stack_a, stack_b);
	rotation_b(stack_b, best_node_x->target_node);
	rotation_a(stack_a, best_node_x);
	if (i == 1)
		pb(stack_a, stack_b);
}

void	sort_2_3_node(t_stack **stack_a)
{
	t_stack	*highest_node;

	highest_node = find_largest(*stack_a);
	if (ft_mylstsize(*stack_a) == 2)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			sa(stack_a);
	}
	else if ((*stack_a) == highest_node)
		ra(stack_a, 1);
	else if ((*stack_a)->next == highest_node)
		rra(stack_a, 1);
	if ((*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a);
}

void	push_tow_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	size_x;

	push_tow_stack_b(stack_a, stack_b);
	size_x = ft_mylstsize((*stack_a));
	while (size_x-- > 3)
	{
		update_all_position(*stack_a, *stack_b);
		push_to_stack_b(stack_a, stack_b, 1);
	}
	sort_2_3_node(stack_a);
	size_x = ft_mylstsize((*stack_b));
	while (size_x-- > 0)
	{
		get_position(stack_a);
		get_position(stack_b);
		get_target_stack_a(*stack_a, *stack_b);
		if (*stack_b && (*stack_b)->target_node)
			rotation_a(stack_a, (*stack_b)->target_node);
		pa(stack_a, stack_b);
	}
	rotation_a(stack_a, find_smallest(*stack_a));
}
