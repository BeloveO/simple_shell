#include "shell.h"

/**
 * writeHistory - function def
 * @varInfo: variable param
 *
 * Return: 1
 */
int writeHistory(info_t *varInfo)
{
	ssize_t fileVar;
	char *fileN = gethisfile(varInfo);
	list_t *node = NULL;

	if (!fileN)
		return (-1);

	fileVar = open(fileN, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(fileN);
	if (fileVar == -1)
		return (-1);
	for (node = varInfo->history; node; node = node->next)
	{
		_putsfd(node->str, fileVar);
		_putfd('\n', fileVar);
	}
	_putfd(FLUSHBUF, fileVar);
	close(fileVar);
	return (1);
}


/**
 * gethisfile - main entry point
 * @varInfo: is a variable
 * Return: character
 */

char *gethisfile(info_t *varInfo)
{
	char *varBuffer, *charac;

	charac = _getEnvironment(varInfo, "HOME=");
	if (!charac)
		return (NULL);
	varBuffer = /** line check **/
	malloc(sizeof(char) * (_strlength(charac) + _strlength(FILEHIST) + 2));
	if (!varBuffer)
		return (NULL);
	varBuffer[0] = 0;
	_strcopy(varBuffer, charac);
	_strconcatenate(varBuffer, "/");
	_strconcatenate(varBuffer, FILEHIST);
	return (varBuffer);
}
/**
 * renumHistory - function def
 * @varInfo: is a variable
 *
 * Return: 0
 */
int renumHistory(info_t *varInfo)
{
	list_t *node = varInfo->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (varInfo->histcount = i);
}

/**
 * readHistory - main entry
 * @varInfo: is a variable
 * Return: int
 */
int readHistory(info_t *varInfo)
{
	int i, varOne = 0, lineVal = 0;
	ssize_t fileVar, length, fileSize = 0;
	struct stat st;
	char *varBuffer = NULL, *fileN = gethisfile(varInfo);

	if (!fileN)
		return (0);

	fileVar = open(fileN, O_RDONLY);
	free(fileN);
	if (fileVar == -1)
		return (0);
	if (!fstat(fileVar, &st))
		fileSize = st.st_size;
	if (fileSize < 2)
		return (0);
	varBuffer = malloc(sizeof(char) * (fileSize + 1));
	if (!varBuffer)
		return (0);
	length = read(fileVar, varBuffer, fileSize);
	varBuffer[fileSize] = 0;
	if (length <= 0)
		return (free(varBuffer), 0);
	close(fileVar);
	for (i = 0; i < fileSize; i++)
		if (varBuffer[i] == '\n')
		{
			varBuffer[i] = 0;
			buildHistoryListinfo_t(varInfo, varBuffer + varOne, lineVal++);
			varOne = i + 1;
		}
	if (varOne != i)
		buildHistoryListinfo_t(varInfo, varBuffer + varOne, lineVal++);
	free(varBuffer);
	varInfo->histcount = lineVal;
	while (varInfo->histcount-- >= MAXHIST)
		deleteNodeAtIndex(&(varInfo->history), 0);
	renumHistory(varInfo);
	return (varInfo->histcount);
}

/**
 * buildHistoryListinfo_t - fucntion def
 * @varInfo: is a variable
 * @varBuffer: varBufferfer
 * @lineVal: is a variable
 *
 * Return: 0
 */
int buildHistoryListinfo_t(info_t *varInfo, char *varBuffer, int lineVal)
{
	list_t *node = NULL;

	if (varInfo->history)
		node = varInfo->history;
	addNodeEnd(&node, varBuffer, lineVal);

	if (!varInfo->history)
		varInfo->history = node;
	return (0);
}




