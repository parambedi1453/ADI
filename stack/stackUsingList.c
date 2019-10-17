/*
struct StackLL
{
  int data;
  struct StackLL* next;
};
struct StackLL* main_Stack = NULL;	// The stack head to be used for operations.

struct StackLL* newElement(int data);
++++++ This function is given to you for inserting an element and it will return the address of new node. ++++++
So complete the functions below using above constructs to implement the stack.
*/
int isEmpty()
{
	if(main_Stack==NULL)
      return 1;
  return 0;
}

void push(int data)
{
	struct StackLL *temp = newElement(data);
  if(main_Stack == NULL)
    main_Stack = temp;
  else
  {
    temp->next = main_Stack;
    main_Stack = temp;
  }
}

int pop()
{
	if(main_Stack==NULL)
      return -1;
  else
  {
    int k = main_Stack->data;
    main_Stack = main_Stack->next;
    return k;
  }
}
