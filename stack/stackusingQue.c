/*
int top = -1;
int front1=-1, rear1=-1;
int front2=-1, rear2=-1;
int q1[SIZE], q2[SIZE];

void enqueue(int q[], int *f, int *r, int item);
int dequeue(int q[], int *f, int *r);

Above two queue and their enqueue and dequeue functions are available, 
So complete the below two methods to implement stack using these functions. */


// Function to add an item to stack.
int push(int item)
{
  	if(front1==-1 && rear1==-1)
    {
      front1++;
      rear1++;
    }
  else
   rear1++;
	q1[rear1]=item;
}

// Function to remove an item from stack.
int pop()
{
	if(rear1==-1)
      return -1;
  else
  {
    int x = q1[rear1];
    rear1--;
    return x;
  }
}