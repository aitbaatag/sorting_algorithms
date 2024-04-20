/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 01:31:22 by kait-baa          #+#    #+#             */
/*   Updated: 2024/01/06 03:11:09 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || !(argv[1][0]))
		return (0);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i = 0;
	}
	if (!(filling_stack_a(&stack_a, argv + i, argc)))
	{
		ft_mylstclear(&stack_a);
		ft_putstr("Erorr\n");
		return (0);
	}
	if (ft_mylstsize(stack_a) == 3 || ft_mylstsize(stack_a) == 2)
		sort_2_3_node(&stack_a);
	else if (!(isstacksorted(stack_a)) && ft_mylstsize(stack_a) != 1)
		push_swap(&stack_a, &stack_b);
	ft_mylstclear(&stack_a);
}
