/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 01:31:18 by kait-baa          #+#    #+#             */
/*   Updated: 2024/01/02 05:14:56 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_is_valid_argument(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9'))
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_duplicates(t_stack **list, int data_check)
{
	t_stack	*ptr;

	ptr = *list;
	if (!*list)
		return (1);
	if (ptr->data == data_check || ptr->data == data_check)
		return (0);
	while (ptr->next != NULL)
	{
		if (ptr->data == data_check)
			return (0);
		ptr = ptr->next;
	}
	while (ptr->prev != NULL)
	{
		if (ptr->data == data_check)
			return (0);
		ptr = ptr->prev;
	}
	return (1);
}
