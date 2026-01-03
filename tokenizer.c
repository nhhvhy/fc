/* Function(s) for tokenizing SQL statements
 *
 * Version - 12/28/25
 * Author - nhhvhy
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int INITAL_TOKEN_CAPACITY = 64; // Inital capacity of token array within Tokens struct
const char *TOKEN_DELIMITER = " ";    // Delimiter used to seperate token within input statement

typedef struct {
	char **tokens;
	size_t count; 		// number of tokens
	size_t capacity;	// available token slots
} Tokens;


Tokens newTokenStruct() {
	Tokens temp;
	temp.tokens = malloc(INITAL_TOKEN_CAPACITY);
	temp.capacity = INITAL_TOKEN_CAPACITY;
	temp.count = 0;

	return temp;
}

void pushToken(Tokens *tokarr, char* token) {
	if (tokarr->count + 1 >= tokarr->capacity) 
	{
		tokarr->capacity *= 2;
		tokarr->tokens = realloc(
			tokarr->tokens, 
			tokarr->capacity * sizeof *tokarr->tokens
		);
	}
	
	if (token) {
		tokarr->tokens[tokarr->count++] = strdup(token);
	} else {
		tokarr->tokens[tokarr->count++] = NULL;
	}
}

int tokenizeStatement(char *statement, char ***tokensOut) {
	char *token;
	Tokens tokarr = newTokenStruct();

	token = strtok(statement, TOKEN_DELIMITER);
	while (token)
	{
		pushToken(&tokarr, token);
		token = strtok(NULL, TOKEN_DELIMITER);
	}
	pushToken(&tokarr, NULL); // push null terminator

	*tokensOut = tokarr.tokens;
	return 0;
}
