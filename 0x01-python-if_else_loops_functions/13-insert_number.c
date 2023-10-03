#include "lists.h"

listint_t *create_node(int n);

/**
 * insert_node - inserts a node sorted in a linked list of ints
 * @head: this is the double pointer to head of LL, in edge
 * cases
 * @number:this is the data for new node
 *
 * Return: this returns pointer to newly created node, NULL on failure
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *cur_node = NULL, *new_node = NULL;

	if (!head)
		return (NULL);
	else if (!(*head))
	{
		new_node = create_node(number);
		*head = new_node;
		return (new_node);
	}
	cur_node = *head;
	while (cur_node)
	{
		if (cur_node->n >= number)
		{
			new_node = create_node(number);
			new_node->next = cur_node;
			*head = new_node;
			return (new_node);
		}
		else if (cur_node->n <= number)
		{
			if (!cur_node->next || cur_node->next->n >= number)
			{
				new_node = create_node(number);
				new_node->next = cur_node->next;
				cur_node->next = new_node;
				return (cur_node->next);
			}
		}
		cur_node = cur_node->next;
	}
	return (NULL); /* this is means failed */
}


/**
 * create_node - this creates a new node for the LL
 * @n: this is the data to insert into new node
 *
 * Return: this returns pointer to newly allocated node
 */


listint_t *create_node(int n)
{
	listint_t *ret = NULL;

	ret = malloc(sizeof(listint_t));
	if (!ret)
		return (NULL);
	ret->next = NULL;
	ret->n = n;
	return (ret);
}
