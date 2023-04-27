#include "shell.h"
/**
 * **stringtowsec - function def
 * @stringVal: is a variable
 * @delimit: is a variable
 * Return: char
 */
char **stringtowsec(char *stringVal, char delimit)
{
	int i, count2, count3, count4, words = 0;
	char **str;

	if (stringVal == NULL || stringVal[0] == 0)
		return (NULL);
	for (i = 0; stringVal[i] != '\0'; i++)
		if ((stringVal[i] != delimit && stringVal[i + 1] == delimit) ||
				    (stringVal[i] != delimit && !stringVal[i + 1]) ||
					stringVal[i + 1] == delimit)
			words++;
	if (words == 0)
		return (NULL);
	str = malloc((1 + words) * sizeof(char *));
	if (!str)
		return (NULL);
	for (i = 0, count2 = 0; count2 < words; count2++)
	{
		while (stringVal[i] == delimit && stringVal[i] != delimit)
			i++;
		count3 = 0;
		while (stringVal[i + count3] != delimit &&
		stringVal[i + count3] &&
		stringVal[i + count3] != delimit)
			count3++;
		str[count2] = malloc((count3 + 1) * sizeof(char));
		if (!str[count2])
		{
			for (count3 = 0; count3 < count2; count3++)
				free(str[count3]);
			free(str);
			return (NULL);
		}
		for (count4 = 0; count4 < count3; count4++)
			str[count2][count4] = stringVal[i++];
		str[count2][count4] = 0;
	}
	str[count2] = NULL;
	return (str);
}

/**
 * **stringtow - function def
 * @stringVal: is a variable
 * @delimit: is a variable
 * Return: is a variable
 */

char **stringtow(char *stringVal, char *delimit)
{
	int count, count2, count3, count4, words = 0;
	char **str;

	if (stringVal == NULL || stringVal[0] == 0)
		return (NULL);
	if (!delimit)
		delimit = " ";
	for (count = 0; stringVal[count] != '\0'; count++)
		if (!is_delimitor(stringVal[count], delimit) &&
	(is_delimitor(stringVal[count + 1], delimit) ||
	!stringVal[count + 1]))
			words++;

	if (words == 0)
		return (NULL);
	str = malloc((1 + words) * sizeof(char *));
	if (!str)
		return (NULL);
	for (count = 0, count2 = 0; count2 < words; count2++)
	{
		while (is_delimitor(stringVal[count], delimit))
			count++;
		count3 = 0;
		while (!is_delimitor(stringVal[count + count3], delimit) &&
		stringVal[count + count3])
			count3++;
		str[count2] = malloc((count3 + 1) * sizeof(char));
		if (!str[count2])
		{
			for (count3 = 0; count3 < count2; count3++)
				free(str[count3]);
			free(str);
			return (NULL);
		}
		for (count4 = 0; count4 < count3; count4++)
			str[count2][count4] = stringVal[count++];
		str[count2][count4] = 0;
	}
	str[count2] = NULL;
	return (str);
}



