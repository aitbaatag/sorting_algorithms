/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_stack_a_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 03:14:12 by kait-baa          #+#    #+#             */
/*   Updated: 2024/01/06 03:21:50 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	is_valid_argument(char *str)
{
	int	i;
	int	num;

	num = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

void	ft_mylstclear(t_stack **list)
{
	t_stack	*ptr;

	while (*list != NULL)
	{
		ptr = (*list)->next;
		if (ptr)
			ptr->prev = NULL;
		free(*list);
		*list = ptr;
	}
}

t_stack	*ft_mylstnew(int data)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	ft_mylstadd_front(t_stack **list, t_stack *node)
{
	if (*list)
	{
		(*list)->prev = node;
		node->next = *list;
	}
	node->prev = NULL;
	*list = node;
}
