/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamofoke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 09:33:09 by kamofoke          #+#    #+#             */
/*   Updated: 2019/09/16 09:34:31 by kamofoke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

t_files			*get_prevnd(t_files *head, t_files *a)
{
	t_files		*temp;
	t_files		*pre_a;

	if (head == a)
		return (NULL);
	temp = head;
	pre_a = NULL;
	while (temp && temp != a)
	{
		pre_a = temp;
		temp = temp->next;
	}
	if (temp != a)
	{
		ft_putendl("error: node not found!");
		ft_exit("EXIT_FAILURE");
	}
	return (pre_a);
}

void			ft_list_swap(t_files **head, t_files **a, t_files **b)
{
	t_files		*pre_a;
	t_files		*pre_b;
	t_files		*temp;

	if ((*head) == NULL || (*a) == NULL || (*b) == NULL)
		return ;
	pre_a = get_prevnd(*head, *a);
	pre_b = get_prevnd(*head, *b);
	if (pre_a)
		pre_a->next = (*b);
	if (pre_b)
		pre_b->next = (*a);
	temp = NULL;
	temp = (*a)->next;
	(*a)->next = (*b)->next;
	(*b)->next = temp;
	if ((*head) == (*a))
		*head = *b;
	else
	{
		if ((*head) == (*b))
			*head = *a;
	}
}
