#include "header.h"


int main(int argc, char *argv[]) 
{
    Stk stack;
    stack.top = -1;

    if (argc < 2) 
    {
	printf("Usage: %s <pushd/popd> <directory>\n", argv[0]);
	return 0;
    }
    else
    {
	if (strcmp(argv[1], "pushd") == 0) 
	{
	    if (argc != 3) 
	    {
		printf("Usage: %s pushd <directory>\n", argv[0]);
		return 0;
	    }
	    else
	    {
		pushd(&stack, argv[2]);
	    }
	} 
	else if (strcmp(argv[1], "popd") == 0) 
	{
	    if (argc != 2) 
	    {
		printf("Usage: %s popd\n", argv[0]);
		return 0;
	    }
	    else
	    {
		popd(&stack);
	    }
	} 
	else 
	{
	    printf("Command not found : %s\n", argv[1]);
	    return 0;
	}
    }

    return 0;
}

