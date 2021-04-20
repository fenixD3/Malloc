/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 18:47:07 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/31 18:29:16 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./test.h"

void show_heap_list()
{
    int i = 0;
    t_heap *heap = g_allocated_heap;

    printf("DEBUG: heap list\n");

    while (heap) {
        printf(
            "%d. heap %p, prev: %p, next: %p (count: %zu, group: %d, total size: %zu, free_space: %zu)\n",
            i,
            heap,
            heap->prev,
            heap->next,
            heap->block_count,
            heap->type,
            heap->total_size,
            heap->avail_size);
        heap = heap->next;
        i++;
    }
}
