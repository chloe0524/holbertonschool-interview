#include "holberton.h"

/**
 * wildcmp - Compares two strings with wildcard support
 * @s1: First string
 * @s2: Second string (may contain wildcard *)
 * Return: 1 if strings are identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	/* If s2 is empty, s1 must also be empty for a match */
	if (*s2 == '\0')
		return (*s1 == '\0');

	/* If we have a wildcard in s2 */
	if (*s2 == '*')
	{
		/* Skip the wildcard and see if remaining strings match */
		if (wildcmp(s1, s2 + 1))
			return (1);

		/* If s1 is not empty, try matching current s1 char with wildcard */
		if (*s1 != '\0' && wildcmp(s1 + 1, s2))
			return (1);

		return (0);
	}

	/* If current characters match, continue comparing next positions */
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	/* Characters don't match */
	return (0);
}
