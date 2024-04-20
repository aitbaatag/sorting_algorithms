/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 01:30:41 by kait-baa          #+#    #+#             */
/*   Updated: 2024/01/06 03:04:51 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	if (NULL == argv || NULL == *argv)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

int	isstacksorted(t_stack *stack_a)
{
	int		current;
	int		next;
	t_stack	*temp;

	if (!stack_a)
		return (1);
	temp = stack_a;
	while (temp->next != NULL)
	{
		current = temp->data;
		next = temp->next->data;
		if (current > next)
		{
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}
