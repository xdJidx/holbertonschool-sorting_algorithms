#include "sort.h"

/**
 * swap - swaps two elements in an array
 * @list: pointer to the head of the list
 * @node1: pointer to the first node
 * @node2: pointer to the second node
 * Return: void
 */
void doubleSwap(listint_t **list, listint_t **node1, listint_t *node2)
{
    /* Maj pointeur "next" de node1 pour pointer vers le nœud après node2 */
	(*node1)->next = node2->next;

    /*Maj pointeur "prev" du nœud après node2 pour pointer vers node1*/
	if (node2->next != NULL)
	node2->next->prev = *node1;

    /* Maj point "prev" de node2 pour point vers nœud précédent de node1 */
	node2->prev = (*node1)->prev;

    /* Maj pointeur "next" de node2 pour pointer vers node1 */
	node2->next = *node1;

    /* Maj point "next" nœud précédent de node1 pour point vers node2*/
	if ((*node1)->prev != NULL)
	(*node1)->prev->next = node2;
	else
	*list = node2;
/*Si node1 est le premier nœud, maj la tête de liste pour point vers node2 */

    /*Maj pointeur "prev" de node1 pour pointer vers node2*/
	(*node1)->prev = node2;

    /*Maj pointeur node1 pour pointer vers le nœud précédent de node2*/
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * @list: pointer to the head of the list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *prev, *next;

	if (list == NULL || *list == NULL)
	return;

	/* Parcours chaque nœud à partir du deuxième nœud */
	for (next = (*list)->next; next != NULL; next = next->next)
	{
		prev = next->prev;
		/* Compare et insert du nœud courant à sa position appropriée */
		while (prev != NULL && prev->n > next->n)
		{
			doubleSwap(list, &prev, next); /* Échange les nœuds si nécessaire */
			print_list(*list); /*Affiche la liste après chaque échange */
			prev = next->prev; /* Maj prev pour continuer comparaison si nécessaire */
		}
	}
}
