#include "header.h"


int is_empty(Stk *s) 
{
    return s->top == -1;
}
int is_full(Stk *s) 
{
    return s->top == 19;
}

void push(Stk *s, char *dir) 
{
    if (is_full(s)) 
    {
	printf("Error: Stack is full\n");
	return;
    }
    s->stack[++s->top] = strdup(dir);
}

char* pop(Stk *s) 
{
    if (is_empty(s)) 
    {
	printf("Error: Stack is empty\n");
	return NULL;
    }
    char *dir = s->stack[s->top];
    s->stack[s->top--] = NULL;
    return dir;
}

void print_stack(Stk *s) 
{
    for (int i = s->top; i >= 0; i--) 
    {
	printf("%s\n", s->stack[i]);
    }
}

void pushd(Stk *s, const char *path)
{
    char cwd[200];
    if (getcwd(cwd, 200) == NULL)
    {
	perror("getcwd");
	return;
    }
    push(s, cwd);
    if (chdir(path) != 0)
    {
	perror("chdir");
    }
    if (getcwd(cwd, 200) != NULL)
    {
	printf("%s\n", cwd);
    }
}

void popd(Stk *s)
{
    char *path = pop(s);
    if (path != NULL)
    {
	if (chdir(path) != 0)
	{
	    perror("chdir");
	}
	free(path);
	char cwd[200];
	if (getcwd(cwd, 200) != NULL)
	{
	    printf("%s\n", cwd);
	}
    }
}
