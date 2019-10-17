/* 
int Stack[SIZE], top = -1;
int isFull();
int isEmpty();

Above variables are used for Stack, SIZE and top and all are global variables. Also above two functions are provided. */
int a[SIZE],top2=-1,min;
// Function to add an item to stack.
void push(int item)
{
  if(top==-1)
  {
    top++;
    Stack[top]=item;
    top2++;
    a[top2]=item;
    min = a[top2];
  }
	else
    {
      top++;
      Stack[top]=item;
      if(Stack[top]<min)
        min = Stack[top];
       top2++;
      a[top2]=min;
    }
}

// Function to remove an item from stack.
int pop()
{
  if(isEmpty())
    return -1;
	int x = Stack[top];
  	top--;
  	top2--;
  return x;
}

// Function to return the minimum item from stack.
int getMin()
{
	return a[top2];
}