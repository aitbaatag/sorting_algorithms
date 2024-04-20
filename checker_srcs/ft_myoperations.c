/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_myoperations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 01:30:53 by kait-baa          #+#    #+#             */
/*   Updated: 2024/01/06 03:03:04 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_stack **stack_a, int i)
{
	t_stack	*next;
	t_stack	*last;

	if (!(*stack_a) || !stack_a)
		return ;
	if (ft_mylstsize(*stack_a) > 1)
	{
		next = (*stack_a)->next;
		last = ft_lstlast(*stack_a);
		(*stack_a)->next = NULL;
		(*stack_a)->prev = last;
		next->prev = NULL;
		last->next = (*stack_a);
		(*stack_a) = next;
	}
	if (i == 1)
		ft_putstr("ra\n");
}

void	rb(t_stack **stack_b, int i)
{
	t_stack	*next;
	t_stack	*last;

	if (!(*stack_b) || !stack_b)
		return ;
	if (ft_mylstsize(*stack_b) > 1)
	{
		next = (*stack_b)->next;
		last = ft_lstlast(*stack_b);
		(*stack_b)->next = NULL;
		(*stack_b)->prev = last;
		next->prev = NULL;
		last->next = (*stack_b);
		(*stack_b) = next;
	}
	if (i == 1)
		ft_putstr("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
}

void	rra(t_stack **stack_a, int i)
{
	t_stack	*last;

	if (NULL == *stack_a || NULL == stack_a)
		return ;
	if (ft_mylstsize(*stack_a) > 1)
	{
		last = ft_lstlast(*stack_a);
		last->prev->next = NULL;
		(*stack_a)->prev = last;
		last->next = (*stack_a);
		last->prev = NULL;
		(*stack_a) = last;
	}
	if (i == 1)
		ft_putstr("rra\n");
}

void	rrb(t_stack **stack_b, int i)
{
	t_stack	*last;

	if (NULL == *stack_b || NULL == *stack_b)
		return ;
	if (ft_mylstsize(*stack_b) > 1)
	{
		last = ft_lstlast(*stack_b);
		last->prev->next = NULL;
		(*stack_b)->prev = last;
		last->next = (*stack_b);
		last->prev = NULL;
		(*stack_b) = last;
	}
	if (i == 1)
		ft_putstr("rrb\n");
}
