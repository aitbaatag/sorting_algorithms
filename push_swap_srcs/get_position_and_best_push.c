/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position_and_best_push.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 01:39:36 by kait-baa          #+#    #+#             */
/*   Updated: 2024/01/05 22:41:13 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_position(t_stack **stack_x)
{
	int		i;
	int		size;
	t_stack	*head;

	size = ft_mylstsize(*stack_x);
	head = *stack_x;
	i = 0;
	head = *stack_x;
	while (head)
	{
		head->posn = i;
		if (i <= size / 2)
		{
			head->po = i;
			head->above_below = true;
		}
		else
		{
			head->po = size - i;
			head->above_below = false;
		}
		i++;
		head = head->next;
	}
}

void	get_number_move(t_stack **stack_a)
{
	t_stack	*head_a;

	head_a = *stack_a;
	while (head_a)
	{
		if (head_a->above_below && head_a->target_node->above_below)
		{
			if (head_a->po >= head_a->target_node->po)
				head_a->move = head_a->po;
			else
				head_a->move = head_a->target_node->po;
		}
		else if (!(head_a->above_below)
			&& !(head_a->target_node->above_below))
		{
			if (head_a->po >= head_a->target_node->po)
				head_a->move = head_a->po;
			else
				head_a->move = head_a->target_node->po;
		}
		else
			head_a->move = head_a->target_node->po + head_a->po;
		head_a = head_a->next;
	}
}

void	get_target_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	int		min_v;

	while (stack_a)
	{
		min_v = INT_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->data < stack_a->data && current_b->data > min_v)
			{
				min_v = current_b->data;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (INT_MIN == min_v)
			stack_a->target_node = find_largest(stack_b);
		else
			stack_a->target_node = target_node;
		stack_a = stack_a->next;
	}
}

void	get_target_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	int		max_v;

	max_v = INT_MAX;
	current_a = stack_a;
	if (stack_a && stack_b)
	{
		while (current_a)
		{
			if (current_a->data > stack_b->data && current_a->data < max_v)
			{
				max_v = current_a->data;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (INT_MAX == max_v)
			stack_b->target_node = find_smallest(stack_a);
		else
			stack_b->target_node = target_node;
	}
}

void	update_all_position(t_stack *stack_a, t_stack *stack_b)
{
	get_position(&stack_a);
	get_position(&stack_b);
	get_target_stack_b(stack_a, stack_b);
	get_number_move(&stack_a);
}
