/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 01:31:26 by kait-baa          #+#    #+#             */
/*   Updated: 2024/01/06 02:56:32 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct stack_a_b
{
	int					data;

	struct stack_a_b	*next;
	struct stack_a_b	*prev;
}						t_stack;

int						filling_stack_a(t_stack **stack_a, char **args,
							int argc);
int						ft_is_valid_argument(char *str);
char					**ft_split(char const *s, char c);
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
void					ss(t_stack **stack_a, t_stack **stack_b);
t_stack					*ft_lstlast(t_stack *lst);
int						ft_mylstsize(t_stack *lst);
int						isstacksorted(t_stack *stack_a);
void					ft_mylstclear(t_stack **list);
void					free_argv(char **argv);
size_t					ft_strlen(const char *str);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
#endif