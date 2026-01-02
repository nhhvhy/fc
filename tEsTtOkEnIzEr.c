#include <stdio.h>
#include <stdlib.h>

extern int tokenizeStatement(char *statement, char **tokensOut);

int main(int argc, char* argv[])
{
	char teststr[] = "this is a test";
	char **tokens;

	tokenizeStatement(teststr, tokens);
	
	printf("here");

	while(*tokens != 0)
	{
		printf("%s\n", *tokens);
		++tokens;
	}

	return 0;
}




