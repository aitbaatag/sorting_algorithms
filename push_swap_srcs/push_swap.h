/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 01:31:26 by kait-baa          #+#    #+#             */
/*   Updated: 2024/01/06 03:22:56 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct stack_a_b
{
	int					data;
	int					po;
	int					move;
	int					posn;
	bool				above_below;
	struct stack_a_b	*target_node;
	struct stack_a_b	*next;
	struct stack_a_b	*prev;
}						t_stack;

int						filling_stack_a(t_stack **stack_a, char **args,
							int argc);
int						ft_is_valid_argument(char *str);
char					**ft_split(char const *s, char c);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
long					ft_atoi(const char *str);
void					ft_putstr(char *str);
int						check_duplicates(t_stack **list, int data_check);
void					ft_myoperations(t_stack **list, char *rules);
int						ft_strcmp(const char *str1, const char *str2);
t_stack					*ft_lstlast(t_stack *lst);
void					sa(t_stack **list);
t_stack					*ft_mylstnew(int data);
void					ft_mylstadd_front(t_stack **list, t_stack *node);
void					ft_mylstadd_back(t_stack **list, t_stack *node);
void					pb(t_stack **stack_a, t_stack **stack_b);
void					pa(t_stack **stack_a, t_stack **stack_b);
void					ra(t_stack **stack_a, int i);
void					rra(t_stack **stack_a, int i);
void					rb(t_stack **stack_b, int i);
void					rr(t_stack **stack_a, t_stack **stack_b);
void					rrb(t_stack **stack_b, int i);
void					rrr(t_stack **stack_a, t_stack **stack_b);
void					sb(t_stack **list);
int						ft_mylstsize(t_stack *lst);
void					*ft_memcpy(void *dest, const void *src, size_t n);
int						isstacksorted(t_stack *stack_a);
void					sort_stack(t_stack **stack_a, t_stack **stack_b);
void					get_position_stack_b(t_stack **stack_a,
							t_stack **stack_b);
void					get_number_move(t_stack **stack_a);
void					update_all_position(t_stack *stack_a, t_stack *stack_b);
void					push_to_stack_b(t_stack **stack_a, t_stack **stack_b,
							int i);
void					get_target_stack_b(t_stack *stack_a, t_stack *stack_b);
void					push_swap(t_stack **stack_a, t_stack **stack_b);
void					get_position(t_stack **stack_x);
void					get_target_stack_a(t_stack *stack_a, t_stack *stack_b);
t_stack					*best_node(t_stack *stack_a);
void					sort_2_3_node(t_stack **stack_a);
t_stack					*find_largest(t_stack *stack_x);
t_stack					*find_smallest(t_stack *stack_x);
void					rotation_a(t_stack **stack_a, t_stack *top_node);
void					rotation_b(t_stack **stack_a, t_stack *top_node);
void					free_argv(char **argv);
void					ft_mylstclear(t_stack **list);
size_t					ft_strlen(const char *str);
#endif