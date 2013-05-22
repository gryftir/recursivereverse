#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct NODE
{
	int num;
	struct	NODE * next;

}NODE;



// function declarations
NODE * makenode (int i);
NODE * pushNode (NODE * list, int i);
NODE * recursiveReverse(NODE * current);
void printList (NODE * first);
NODE * tailrecursereverse(NODE * current, NODE * next);

NODE * interativetail(NODE * current);
void freeMem(NODE ** current);


//main
int main (int argc, char * argv[]){
int count;
NODE * list = makenode(0);
for (count = 1; count <= 10; count++)
	list = pushNode(list,count);


printf("before reverse\n");
printList(list);
list = recursiveReverse(list);
printf ("after recursive reverse\n");
printList(list);		
printf("now we use the tailrecursereverse\n");
list = tailrecursereverse(list, NULL);
printList(list);
printf("now interative reversal based on tail reversal\n");
list = interativetail(list);
printList(list);
freeMem(&list);
	return 0;
}


void freeMem (NODE ** current) {
NODE * walker, * front = *current;

while (current) {
	walker = front;
	front = front->next;
	free (walker);
}
*current = NULL;
	return;
}


NODE * tailrecursereverse(NODE * current, NODE * append){
	NODE * next;
	if (current == append)
		return current;
	if (current->next == NULL) {
		current->next = append;
		return current;
	}
	next = current->next;
	current->next = append;
	return tailrecursereverse(next, current);
}

NODE * interativetail(NODE * current){
	NODE * next;
	NODE * append = NULL;
	if (current == append)
		return current;
	while (current->next != NULL) {
		next = current->next;
		current->next = append;
		append = current;
    current = next;
	}
	current->next = append;
		return current;
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
	new->next = list;;
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
	if (!current)
		return current;
	if (current->next) {
		next = recursiveReverse(current->next);
	}
	else {
		return current;
	}
	current->next->next = current;
	current->next = NULL;
	return next;
}
