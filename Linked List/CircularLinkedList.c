#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node* next;
};

struct node* last = NULL;

void insertAtF(int data)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));

	if (last == NULL) {
		temp->info = data;
		temp->next = temp;
		last = temp;
	}

	else {
		temp->info = data;
		temp->next = last->next;

		last->next = temp;
	}
}

void DisplayList()
{
	if (last == NULL)
		printf("\nList is empty\n");
	else {
		struct node* temp;
		temp = last->next;
		do {
			printf("\nData = %d", temp->info);
			temp = temp->next;
		} while (temp != last->next);
	}
}

int main()
{
	insertAtF(10);
	insertAtF(20);
	insertAtF(30);

	DispalyList();

	return 0;
}
