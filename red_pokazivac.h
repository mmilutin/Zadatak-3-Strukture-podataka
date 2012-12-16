struct qu {
 tosoba element;
 qu *sljedeci;
};
       
struct que {
   qu *front, *rear;
};

typedef struct que queue;

tosoba FrontQ(queue* Q) {
     tosoba prvi;
     prvi = Q->front->sljedeci->element;
     return prvi;
}

void EnQueueQ (tosoba x, queue* Q) {
   qu* novi = new qu;
   novi->element = x;
   novi->sljedeci = NULL;
   Q->rear->sljedeci=novi;
   Q->rear = novi;
}

void DeQueueQ(queue* Q) {   
    qu* brisi = Q->front;
    Q->front = brisi->sljedeci;
    delete brisi;
}

queue* InitQ(queue* Q) {
  Q = new queue;
  qu* novi = new qu;
  Q->front = novi;
  Q->rear = novi;
  Q->front->sljedeci = NULL;
  return Q;
}

bool IsEmptyQ(queue* Q) {
  if (Q->front == Q->rear) return 1;
  else return 0;
}
