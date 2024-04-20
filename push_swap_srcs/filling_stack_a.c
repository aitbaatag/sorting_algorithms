/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 01:30:45 by kait-baa          #+#    #+#             */
/*   Updated: 2024/01/06 03:14:05 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	help_filling_stack_a(t_stack **stack_a, char **args, int argc, int i)
{
	long	nb;
	t_stack	*new_node;

	while (args[i])
	{
		if (!(ft_is_valid_argument(args[i])) && args[i])
		{
			if (argc == 2)
				free_argv(args);
			return (0);
		}
		nb = ft_atoi(args[i]);
		new_node = ft_mylstnew(nb);
		if (!(check_duplicates(stack_a, nb)) || nb > INT_MAX
			|| ft_strlen(args[i]) > 11 || ft_strlen(args[i]) == 0)
		{
			if (argc == 2)
				free_argv(args);
			return (0);
		}
		ft_mylstadd_back(stack_a, new_node);
		i++;
	}
	return (1);
}

int	filling_stack_a(t_stack **stack_a, char **args, int argc)
{
	int	i;

	i = 0;
	if (!(help_filling_stack_a(stack_a, args, argc, i)))
		return (0);
	if (argc == 2)
		free_argv(args);
	return (1);
}
