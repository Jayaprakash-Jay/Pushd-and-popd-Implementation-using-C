#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>


typedef struct st 
{
    char *stack[20];
    int top;
}Stk;


int is_empty(Stk *s); 
int is_full(Stk *s);
void push(Stk *s, char *dir); 
char* pop(Stk *s);
void print_stack(Stk *s); 
void pushd(Stk *s, const char *path); 
void popd(Stk *s);


