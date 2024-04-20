/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 01:30:45 by kait-baa          #+#    #+#             */
/*   Updated: 2024/01/06 03:48:05 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
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

int	filling_stack_a(t_stack **stack_a, char **args, int argc)
{
	int		i;
	long	nb;
	t_stack	*new_node;

	i = 0;
	while (args[i])
	{
		if (!(ft_is_valid_argument(args[i])) && args[i])
			return (0);
		nb = ft_atoi(args[i]);
		new_node = ft_mylstnew(nb);
		if (!(check_duplicates(stack_a, nb)) || nb > INT_MAX
			|| ft_strlen(args[i]) == 0 || ft_strlen(args[i]) > 11)
		{
			return (0);
		}
		ft_mylstadd_back(stack_a, new_node);
		i++;
	}
	if (argc == 2)
		free_argv(args);
	return (1);
}
