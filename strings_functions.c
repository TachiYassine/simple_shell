#include "shell.h"

char *_Str_duplicate(const char *str)
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

int _str_compare(char *str1, char *str2)
{
	int cmp;

	cmp = (int)*str1 - (int)*str2;
	while(*str1)
	{
		if (*str1 != *str2)
			break;
		str1++;
		str2++;
		cmp = (int)*str1 - (int)*str2;
	}
	return (cmp);
}

int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

char * _strcat(char *dest, char *src)
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
/*
char *_strcpy(char *dest, char *src)
{
	.....
}*/
