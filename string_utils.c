/**
 * *_strdup - func that duplicate string
 * @string: string that duplicated
 * Return: return the value of new string or NULL
 */
char *_strdup(char *string)
{
	int i = 0;
	char *copy;
	int len;

	if (string == NULL)
		return (NULL);
	len = _strlen(string);
	copy = malloc((len + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	while ((copy[i] = string(i)) != '\0')
		i++;
	return (copy);
}

/**
 * *_strcmp - fun that compare two strings
 * @s1: first string
 * @s2: second string
 * Return: the value -1, 0, 1.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}

/**
 * _str_n_cmp - fun that compare string and bytes
 * @s1: first string
 * @s2: second string
 * @n: nr of bytes
 * Return: value -1, 0, 1.
 *
 */
int _str_n_cmp(char *s1, char *s2, int n)
{
	char c1;
	char c2;

	while (n--)
	{
		c1 = *s1++;
		c2 = *s2++;

		if (c1 == '\0' || c1 != c2)
			return (c1 > c2 ? 1 : (c1 < c2 ? -1 : 0));
	}
	return (0);

}
