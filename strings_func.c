#include "shell.h"

/**
 * _strdup - duplicate str
 * @str: function param
 * Return: returns char pointer
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
		ptr = malloc(sizeof(char) * (len + 1));
		if (ptr == NULL)
			return (NULL);
		for (i = 0 ; i <= len ; i++)
			ptr[i] = str[i];
		return (ptr);
}

/**
 * _strcmp - compares 2 strings
 * @s1: first string param
 * @s2: second string param
 * Return: returns int that indicates if the strings are equal
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
 * _strlen - counts the length of the string
 * @s: string to be counted
 * Return: returns length of the string
 */

int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * _strcat - strcat from string library functions
 * @dest: first string
 * @src: second string
 * Return: returns char *
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
 * _strcpy - copies string from a pointer to another
 * @dest: fisrt param
 * @src: second param
 * Return: returns char *
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}

	return (dest);
}
