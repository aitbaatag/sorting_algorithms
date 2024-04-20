/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 02:52:14 by kait-baa          #+#    #+#             */
/*   Updated: 2024/01/06 03:52:38 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_print_error(t_stack **stack_a, t_stack **stack_b, char *str)
{
	ft_mylstclear(stack_a);
	ft_mylstclear(stack_b);
	free(str);
	ft_putstr("Erorr\n");
	exit(1);
}

void	ft_operations(t_stack **stack_a, t_stack **stack_b, char *moves)
{
	if (!ft_strcmp(moves, "pa\n"))
		pa(stack_a, stack_b);
	else if (!ft_strcmp(moves, "pb\n"))
		pb(stack_a, stack_b);
	else if (!ft_strcmp(moves, "sa\n"))
		sa(stack_a);
	else if (!ft_strcmp(moves, "sb\n"))
		sb(stack_b);
	else if (!ft_strcmp(moves, "ss\n"))
		ss(stack_a, stack_b);
	else if (!ft_strcmp(moves, "ra\n"))
		ra(stack_a, 0);
	else if (!ft_strcmp(moves, "rb\n"))
		rb(stack_b, 0);
	else if (!ft_strcmp(moves, "rr\n"))
		rr(stack_a, stack_b);
	else if (!ft_strcmp(moves, "rra\n"))
		rra(stack_a, 0);
	else if (!ft_strcmp(moves, "rrb\n"))
		rrb(stack_b, 0);
	else if (!ft_strcmp(moves, "rrr\n"))
		rrr(stack_a, stack_b);
	else
		free_print_error(stack_a, stack_b, moves);
}

int	main_norm(t_stack **stack_a, t_stack **stack_b, int argc, char *argv[])
{
	int		i;
	char	*moves;
	int		size_a;

	size_a = 0;
	i = 1;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i = 0;
	}
	if (!(filling_stack_a(stack_a, argv + i, argc)))
	{
		ft_mylstclear(stack_a);
		ft_putstr("Erorr\n");
		exit(1);
	}
	size_a = ft_mylstsize(*stack_a);
	moves = malloc(sizeof(char) * 4);
	while (read(0, moves, 4))
		ft_operations(stack_a, stack_b, moves);
	free(moves);
	return (size_a);
}

int	main(int argc, char *argv[])
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			size_a;

	stack_a = NULL;
	stack_b = NULL;
	size_a = 0;
	if (argc == 1)
		return (0);
	size_a = main_norm(&stack_a, &stack_b, argc, argv);
	if (isstacksorted(stack_a) && size_a == ft_mylstsize(stack_a) && size_a > 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	ft_mylstclear(&stack_a);
}
