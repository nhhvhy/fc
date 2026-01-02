/* Function(s) for tokenizing SQL statements
 *
 * Version - 12/28/25
 * Author - nhhvhy
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char **tokens;
	size_t tokenCount;
	size_t size;
	size_t capacity;
} Tokens;

#define pushToken(tokarr, token)\
	if (tokarr.capacity == 0) tokarr.capacity = 64;\
	while (tokarr.size <= (tokarr.capacity + strlen(token))) {\
		tokarr.capacity *= 2;\
		tokarr.tokens = realloc(tokarr.tokens, tokarr.capacity);\
	}\
	tokarr.tokens[tokarr.tokenCount++] = token;


int tokenizeStatement(char *statement, char **tokensOut) {
	Tokens tokarr = {};
	char *delimiter = " ";
	char *token;

	token = strtok(statement, delimiter);
	
	printf("here");
	while (token)
	{
		pushToken(tokarr, token);
		token = strtok(NULL, delimiter);
	}
	
	tokensOut = tokarr.tokens;
	return 0;
}
