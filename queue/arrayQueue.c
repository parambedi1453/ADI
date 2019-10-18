/*
int front=-1, rear=-1;
int array[SIZE];

Above variables are used for queue, SIZE, front and rear and all are global variables. Complete the below two methods. */

// Method to add an item to the queue.
void enqueue(int item)
{
  	if(rear == SIZE)
      return ;
	if(front==-1&&rear==-1)
    {
      front++;
      rear++;
    }
  else
  {
    rear++;
  }
  array[rear]=item;
    
}

// Method to remove an item from queue.
int dequeue()
{
	if(front>rear)
      return -1;
  	else
    {
      int k =array[front];
     front++;
      return k;
    }
  
}