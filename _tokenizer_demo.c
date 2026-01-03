#include <stdio.h>
#include <stdlib.h>

extern int tokenizeStatement(char *statement, char ***tokensOut);

int main(int argc, char* argv[])
{
	char teststr[] = "this is a test statement";
	char **tokens;

	tokenizeStatement(teststr, &tokens);
	
	char **p = tokens;	
	while(*p != NULL)
	{
		printf("%s\n", *p);
		p++;
	}

	return 0;
}




