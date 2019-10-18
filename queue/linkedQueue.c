/*
struct QNode	{	int data; struct QNode *next; };
struct QueueLL	{	struct QNode *front,*rear; };
struct QueueLL *main_Queue;
struct QNode* newElement(int data);

Above strcutures and variables are used for queue.
Also newElement(int) function will insert a new node and return the address of new node.
Complete the below two methods. */
// *main_Queue = NULL;
int enqueue(int data)
{
  struct QNode *temp = newElement(data);
  temp->next==NULL;
	if(main_Queue->front==NULL)
    {
      main_Queue->front =temp;
      main_Queue->rear=temp;
    }
  else
  {
   main_Queue->rear->next=temp;
    main_Queue->rear=temp;
  }
}

int dequeue()
{
	if(main_Queue->front==NULL)
      return -1;
  else
  {
    int k = main_Queue->front->data;
   struct QNode *i= main_Queue->front->next;
    main_Queue->front=i;
    
    return k;
  }
}