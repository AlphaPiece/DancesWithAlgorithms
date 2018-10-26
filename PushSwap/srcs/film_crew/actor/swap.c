/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 16:12:28 by zwang             #+#    #+#             */
/*   Updated: 2018/10/25 21:43:28 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_box_stacks *box_stacks, char stack_code)
{
	t_box	*box;

	box = (stack_code == 'a') ? box_stacks->a : box_stacks->b;
	while (box && box->is_empty)
		box = box->next;
	if (box && box->next)
		ft_swap(4, &(box->num), &(box->next->num));
}

void	swap_both(t_box_stacks *box_stacks)
{
	swap(box_stacks, 'a');
	swap(box_stacks, 'b');
}
