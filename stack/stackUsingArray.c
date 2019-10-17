/* 
int Stack[SIZE], top = -1;

Above variables are used for Stack, SIZE and top and all are global variables. */

// Function to check if stack is full.
int isFull()
{
	if(top == SIZE)
      return 1;
  return 0;
}

// Function to check if stack is empty.
int isEmpty()
{
  if(top == -1)
    return 1;
  return 0;

}

// Function to add an item to stack.
int push(int item)
{
    if(!isFull())
    {  Stack[top++]=item;
 return item;
    }
}

// Function to remove an item from stack.
int pop()
{
	if(top!=-1)
    {
      int a = Stack[top-1];
      top--;
//       printf("%d\n",a);
      return a;
    }
  return -1;
}