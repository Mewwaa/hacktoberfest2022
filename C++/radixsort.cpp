#include <iostream>
using namespace std;

class queue{
    public:
    int size = 10;
    int front = -1;
    int rear = -1;
    int *arr = new int[size];

    int isFull(queue *qp){
        if (qp->rear == qp->size - 1){
            return 1;
        }else{
            return 0;
        }
    }

    int isEmpty(queue *qp){
        if (qp->front == -1 || qp->front > qp->rear){
            return 1;
        }else{
            return 0;
        }
    }

    void enqueue(queue *qp, int val){
        if (isFull(qp)){
            cout << "Overflow cant insert " << val << endl;
        }else if (qp->front == -1 && qp->rear == -1){
            qp->front = qp->rear = 0;
            qp->arr[qp->rear] = val;
        }else{
            qp->rear = qp->rear + 1;
            qp->arr[qp->rear] = val;
        }
        // cout<<"Front "<<qp->front<<endl;
        // cout<<"Rear "<<qp->rear<<endl;
    }

    int dequeue(queue *qp){
        if (isEmpty(qp)){
            cout << "Underflow cant delete!!" << endl;
            return -1;
        }else{
            int val = qp->arr[qp->front];
            qp->front = qp->front + 1;
            return val;
        }
        // cout<<"Front "<<qp->front<<endl;
        // cout<<"Rear "<<qp->rear<<endl;
    }

    void display(queue *qp){
        for (int i = qp->front; i <= qp->rear; i++){
            cout << qp->arr[i] <<" ";
        }
        cout<<endl;
    }

    void emptyQueue(queue *qp){
        qp->front = qp->rear = -1;
    }

};

queue *qp0 = new queue();
queue *qp1 = new queue();
queue *qp2 = new queue();
queue *qp3 = new queue();
queue *qp4 = new queue();
queue *qp5 = new queue();
queue *qp6 = new queue();
queue *qp7 = new queue();
queue *qp8 = new queue();
queue *qp9 = new queue();

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int maxEle(int arr[],int size){
    int maxElement = arr[0];
    for(int i=0;i<size;i++){
        if(arr[i]>maxElement){
            maxElement = arr[i];
        }
    }

    return maxElement;
}

int digitAtPlace(int n,int place){
    int a = n;
    int rem = 0;
    for(int i=0;i<place;i++){
        rem = a%10;
        a = a/10;
    }
    return rem;
}

void sort(int arr[],int size,int place){
    for(int i=0;i<size;i++){
        int n = arr[i];
        int digit = digitAtPlace(n,place);

        if(digit==0){
            qp0->enqueue(qp0,n);
        }else if(digit==1){
          qp1->enqueue(qp1,n);   
        }else if(digit==2){
          qp2->enqueue(qp2,n);   
        }else if(digit==3){
          qp3->enqueue(qp3,n);   
        }else if(digit==4){
          qp4->enqueue(qp4,n);   
        }else if(digit==5){
          qp5->enqueue(qp5,n);   
        }else if(digit==6){
          qp6->enqueue(qp6,n);   
        }else if(digit==7){
          qp7->enqueue(qp7,n);   
        }else if(digit==8){
          qp8->enqueue(qp8,n);   
        }else if(digit==9){
          qp9->enqueue(qp9,n);   
        }
    }

    int k=0;
    while(!(qp0->isEmpty(qp0))){
        arr[k] = qp0->dequeue(qp0);
        k++;
    }
    while(!(qp1->isEmpty(qp1))){
        arr[k] = qp1->dequeue(qp1);
        k++;
    }
    while(!(qp2->isEmpty(qp2))){
        arr[k] = qp2->dequeue(qp2);
        k++;
    }
    while(!(qp3->isEmpty(qp3))){
        arr[k] = qp3->dequeue(qp3);
        k++;
    }
    while(!(qp4->isEmpty(qp4))){
        arr[k] = qp4->dequeue(qp4);
        k++;
    }
    while(!(qp5->isEmpty(qp5))){
        arr[k] = qp5->dequeue(qp5);
        k++;
    }
    while(!(qp6->isEmpty(qp6))){
        arr[k] = qp6->dequeue(qp6);
        k++;
    }
    while(!(qp7->isEmpty(qp7))){
        arr[k] = qp7->dequeue(qp7);
        k++;
    }
    while(!(qp8->isEmpty(qp8))){
        arr[k] = qp8->dequeue(qp8);
        k++;
    }
    while(!(qp9->isEmpty(qp9))){
        arr[k] = qp9->dequeue(qp9);
        k++;
    }

    qp0->emptyQueue(qp0);
    qp1->emptyQueue(qp1);
    qp2->emptyQueue(qp2);
    qp3->emptyQueue(qp3);
    qp4->emptyQueue(qp4);
    qp5->emptyQueue(qp5);
    qp6->emptyQueue(qp6);
    qp7->emptyQueue(qp7);
    qp8->emptyQueue(qp8);
    qp9->emptyQueue(qp9);

}

void radixSort(int arr[],int size){
    int maxElement = maxEle(arr,size);
    int rounds = 0;

    while(maxElement>0){
        rounds++;
        maxElement/=10;
    }

    for(int i=1;i<=rounds;i++){
        sort(arr,size,i);
    }
}



int main(){

    int arr[100];

    cout<<"Enter size of your array (max: 100)"<<endl;
    int size;
    cin>>size;
   
    for(int i=0;i<size;i++){
        cout<<"Enter element at "<<i<<"th index "<<endl;
        cin>>arr[i];
    }

    cout<<"Original Array is: "<<endl;
    printArray(arr,size);

    radixSort(arr,size);

    cout<<"Sorted Array is: "<<endl;
    printArray(arr,size);
   
    return 0;
}















 // cout<<"Round = "<<place<<endl;
    // qp0->display(qp0);
    // qp1->display(qp1);
    // qp2->display(qp2);
    // qp3->display(qp3);
    // qp4->display(qp4);
    // qp5->display(qp5);
    // qp6->display(qp6);
    // qp7->display(qp7);
    // qp8->display(qp8);
    // qp9->display(qp9);
