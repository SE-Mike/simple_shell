#include "shell.h"

/**
 * _ourhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _ourhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * uunset_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int uunset_alias(info_t *info, char *str)
{
	char *k, i;
	int ret;

	k = _strchr(str, '=');
	if (!k)
		return (1);
	i = *k;
	*k = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*k = i;
	return (ret);
}

/**
 * sett_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int sett_alias(info_t *info, char *str)
{
	char *k;

	k = _strchr(str, '=');
	if (!k)
		return (1);
	if (!*++k)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * prnt_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int prnt_alias(list_t *node)
{
	char *k = NULL, *l = NULL;

	if (node)
	{
		k = _strchr(node->str, '=');
		for (l = node->str; l <= k; l++)
			_putchar(*l);
		_putchar('\'');
		_puts(k + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _ouralias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _ouralias(info_t *info)
{
	int n = 0;
	char *m = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (n = 1; info->argv[n]; n++)
	{
		m = _strchr(info->argv[n], '=');
		if (m)
			set_alias(info, info->argv[n]);
		else
			print_alias(node_starts_with(info->alias, info->argv[n], '='));
	}

	return (0);
}
