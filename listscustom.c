#include "shell.h"

/**
 * freeList - function def
 * @first: is a variable
 * Return: nothing
 */
void freeList(list_t **first)
{
	list_t *node, *next_node, *head;

	if (!first || !*first)
		return;
	head = *first;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*first = NULL;
}

/**
 * addNodeEnd - function def
 * @first: is a variable
 * @strValue: is a variable
 * @num: is a variable
 *
 * Return: size of list
 */
list_t *addNodeEnd(list_t **first, const char *strValue, int num)
{
	list_t *beginning, *node;

	if (!first)
		return (NULL);

	node = *first;
	beginning = malloc(sizeof(list_t));
	if (!beginning)
		return (NULL);
	_memset((void *)beginning, 0, sizeof(list_t));
	beginning->num = num;
	if (strValue)
	{
		beginning->str = _strdupcase(strValue);
		if (!beginning->str)
		{
			free(beginning);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = beginning;
	}
	else
		*first = beginning;
	return (beginning);
}

/**
 * printListString - function def
 * @header: pointer to first node
 *
 * Return: size of list
 */
size_t printListString(const list_t *header)
{
	size_t i = 0;

	while (header)
	{
		_puts(header->str ? header->str : "(nil)");
		_puts("\n");
		header = header->next;
		i++;
	}
	return (i);
}
/**
 * add_node - function def
 * @first: is a variable
 * @strValue: is a variable
 * @num: is a variable
 *
 * Return: size of list
 */
list_t *add_node(list_t **first, const char *strValue, int num)
{
	list_t *beginning;

	if (!first)
		return (NULL);
	beginning = malloc(sizeof(list_t));
	if (!beginning)
		return (NULL);
	_memset((void *)beginning, 0, sizeof(list_t));
	beginning->num = num;
	if (strValue)
	{
		beginning->str = _strdupcase(strValue);
		if (!beginning->str)
		{
			free(beginning);
			return (NULL);
		}
	}
	beginning->next = *first;
	*first = beginning;
	return (beginning);
}

/**
 * deleteNodeAtIndex - function def
 * @first: is a variable
 * @index: is a variable
 * Return: 1
 */
int deleteNodeAtIndex(list_t **first, unsigned int index)
{
	list_t *node, *prev;
	unsigned int i = 0;

	if (!first || !*first)
		return (0);

	if (!index)
	{
		node = *first;
		*first = (*first)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *first;
	while (node)
	{
		if (i == index)
		{
			prev->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev = node;
		node = node->next;
	}
	return (0);
}



