struct qu {
   tosoba podaci[100];
   int front, rear;
};

typedef struct qu queue;

int AddOne(int n) {
   return((n+1)%100);
}

tosoba FrontQ(queue* Q) {
     tosoba prvi;
   prvi = Q->podaci[Q->front];
     return prvi;
}

void EnQueueQ (tosoba x, queue* Q) {
    Q->rear=AddOne(Q->rear);
    Q->podaci[Q->rear] = x;
}

void DeQueueQ(queue* Q){
	Q->front = AddOne(Q->front);
}

queue* InitQ(queue* Q){
	Q = new queue;
	Q->front = 0;
	Q->rear = 99;
	return Q;
}

bool IsEmptyQ(queue* Q){
   if(AddOne(Q->rear) == Q->front) return true;
   return false;
}   
