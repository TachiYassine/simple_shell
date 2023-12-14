#include "shell.h"

/**
 * _Str_duplicate - Duplicates a string.
 *
 * @str: Pointer to the string to be duplicated.
 *
 * Return: Pointer to a new allocated memory containing copy of string.
 *         NULL if memory allocation fails or if str is NULL.
 */
char *_strdup(const char *str)
{
	char *ptr;
	int i, len = 0;

	if (str == NULL)
		return (NULL);
	
	while (*str != '\0')
	{
		len++;
		str++;
	}
	str = str - len;
	ptr = malloc(sizeof(char) * (len * 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		ptr[i] = str[i];
	return (ptr);
}

/**
 * _str_compare - Compares two strings lexicographically.
 *
 * @str1: Pointer to the first string for comparison.
 * @str2: Pointer to the second string for comparison.
 *
 * Return: An integer < than, = to, or > than zero if str1 is found
 * so to be less than, to match, or be greater than str2
 */
int _strcmp(char *s1, char *s2)
{
	int cmp;

	cmp = (int)*s1 - (int)*s2;
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
		cmp = (int)*s1 - (int)*s2;
	}
	return (cmp);
}

/**
 * _strlen - Computes the length of a string.
 *
 * @s: Pointer to the string whose length is to be determined.
 *
 * Return: Length of string (number characters) excluding the null terminator
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * _strcat - Concatenates two strings, appending the second to the first.
 *
 * @dest: Pointer to the destination string where the concatenation will occur.
 * @src: Pointer to the string to be appended.
 *
 * Return: Pointer to the destination string.
 */
char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*p)
		p++;

	while (*src)
	{
		*p = *src;
		p++;
		src++;
	}
	*p = *src;

	return (dest);
}

/**
 * _strcpy - Copies a string including the null terminator.
 *
 * @dest: Pointer to the destination buffer where the string will be copied.
 * @src: Pointer to the string to be copied.
 *
 * Return: Pointer to the destination buffer.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
