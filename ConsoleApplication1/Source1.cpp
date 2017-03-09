#include <iostream>

using namespace std;


int main()
 {

	 struct Node
	 {
		 int data;
		 Node* next;
	 };

	 Node* A;
	 A = NULL; // empty list
	 Node* temp = (Node*)malloc(sizeof(Node));
	 temp->data = 10;
	 temp->next = NULL;
	 A = temp;
	 free(temp);

	 printf("%d\n", A->data);
	 return 0;
 }

