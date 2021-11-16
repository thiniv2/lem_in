/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:00:39 by thinguye          #+#    #+#             */
/*   Updated: 2021/11/15 15:00:15 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		is_empty(t_queue *queue)
{
	if (queue->rear == -1)
		return (1);
	return (0);
}

void	enqueue(t_queue *queue, int value)
{
	if (queue->front == -1)
		queue->front = 0;
	queue->rear += 1;
	queue->que[queue->rear] = value;
}

int		dequeue(t_queue *q)
{
	int		item;

	if (is_empty(q))
		item = -1;
	else
	{
		item = q->que[q->front];
		q->front++;
		if (q->front > q->rear)
		{
			q->front = -1;
			q->rear = -1;
		}
	}
	return (item);
}

t_queue	*init_queue(int size)
{
	t_queue	*queue;

	if (!(queue = (t_queue*)malloc(sizeof(t_queue))))
		display_error(1);
	if (!(queue->que = (int*)malloc(sizeof(int) * size)))
		display_error(1);
	queue->front = -1;
	queue->rear = -1;
	return (queue);
}