#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct NODE
{
	int num;
	struct	NODE * next;

}NODE;

NODE * makenode (int i);
NODE * pushNode (NODE * list, int i);

NODE * recursiveReverse(NODE * current);
void printList (NODE * first);
int main (int argc, char * argv[]){
int count;
NODE * list = makenode(0);
for (count = 1; count <= 10; count++)
	list = pushNode(list,count);

printf("before reverse\n");
printList(list);
list = recursiveReverse(list);
printf ("after reverse\n");
printList(list);		

	return 0;
}

NODE * makenode (int i){
	NODE * node;
	node = (NODE *) malloc (sizeof(NODE));
	node->num = i;
	node->next = NULL;
	return node;
}


NODE * pushNode (NODE * list, int i){
	NODE * new = makenode(i);
	new->next = list;
	return new;
}

void printList (NODE * first){
	while (first)
	{
		printf ("%d\n", first->num);
		first = first->next;
	}
	return;
}

NODE * recursiveReverse(NODE * current){
NODE * next;
	if (current->next)
next = recursiveReverse(current->next);
	else
		return current;
current->next->next = current;
current->next = NULL;
return next;
}
