/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masanz-s <masanz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:53:29 by masanz-s          #+#    #+#             */
/*   Updated: 2026/04/20 14:53:30 by masanz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static void	swap_cmd(t_list **stack)
{
	int	temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = *(int *)(*stack)->content;
	*(int *)(*stack)->content = *(int *)(*stack)->next->content;
	*(int *)(*stack)->next->content = temp;
}

/**
 * @brief Swap the first two elements at the top of stack a. 
 * 		  Do nothing if there is only one or no elements.
 */
void	sa(t_list **stack_a)
{
	swap_cmd(stack_a);
}

/**
 * @brief Swap the first two elements at the top of stack b.
 * 		  Do nothing if there is only one or no elements.
 */
void	sb(t_list **stack_b)
{
	swap_cmd(stack_b);
}

/**
 * @brief sa and sb at the same time.
 */
void	ss(t_list **stack_a, t_list **stack_b)
{
	swap_cmd(stack_a);
	swap_cmd(stack_b);
}
