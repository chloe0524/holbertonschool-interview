#include "regex.h"

/**
 * regex_match - Checks if a pattern matches a string.
 * @str: The string to scan.
 * @pattern: The regular expression pattern.
 *
 * Return: 1 if the pattern matches the string, 0 otherwise.
 */
int regex_match(const char *str, const char *pattern)
{
	if (!pattern || !*pattern)
		return (!str || !*str);

	if (*(pattern + 1) == '*')
	{
		if (regex_match(str, pattern + 2))
			return (1);
		if (*str && (*pattern == *str || *pattern == '.'))
			return (regex_match(str + 1, pattern));
		return (0);
	}
	if (*str && (*pattern == *str || *pattern == '.'))
		return (regex_match(str + 1, pattern + 1));
	return (0);
}
