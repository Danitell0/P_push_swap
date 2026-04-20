/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masanz-s <masanz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:53:26 by masanz-s          #+#    #+#             */
/*   Updated: 2026/04/20 14:53:27 by masanz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static void	rotate_cmd(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	last = ft_lstlast(*stack);
	last->next = first;
	first->next = NULL;
}

/**
 * @brief Shift up all elements of stack a by one.
 * 		  The first element becomes the last one.
 */
void	ra(t_list **stack_a)
{
	rotate_cmd(stack_a);
}

/**
 * @brief Shift up all elements of stack b by one.
 * 		  The first element becomes the last one.
 */
void	rb(t_list **stack_b)
{
	rotate_cmd(stack_b);
}

/**
 * @brief ra and rb at the same time.
 */
void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate_cmd(stack_a);
	rotate_cmd(stack_b);
}
