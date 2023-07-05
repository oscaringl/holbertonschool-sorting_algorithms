#include "sort.h"
#include <stdio.h>

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                     in ascending order using Cocktail shaker sort algorithm
 *
 * @list: Double pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped;
    listint_t *current;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    do {
        swapped = 0;
        for (current = *list; current->next != NULL; current = current->next)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(list, &current, &(current->next));
                swapped = 1;
                print_list((const listint_t *)*list);
            }
        }
        if (!swapped)
            break;

        swapped = 0;
        for (; current->prev != NULL; current = current->prev)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(list, &(current->prev), &current);
                swapped = 1;
                print_list((const listint_t *)*list);
            }
        }
    } while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @list: Double pointer to the head of the doubly linked list
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap_nodes(listint_t **list, listint_t **node1, listint_t **node2)
{
    listint_t *prev1, *next1, *prev2, *next2;

    prev1 = (*node1)->prev;
    next1 = (*node1)->next;
    prev2 = (*node2)->prev;
    next2 = (*node2)->next;

    if (prev1)
        prev1->next = *node2;
    if (next1)
        next1->prev = *node2;
    if (prev2)
        prev2->next = *node1;
    if (next2)
        next2->prev = *node1;

    (*node1)->prev = prev2;
    (*node1)->next = next2;
    (*node2)->prev = prev1;
    (*node2)->next = next1;

    if (prev1 == NULL)
        *list = *node2;
    if (prev2 == NULL)
        *list = *node1;
}
