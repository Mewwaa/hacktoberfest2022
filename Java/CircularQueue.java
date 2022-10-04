import java.util.*;
class MyCircularQueue {
    int[] queue;
    int rear;
    int front;
    int capacity;

    //construtor for circular queue
    public MyCircularQueue(int k) {
        this.capacity=k;
        this.queue=new int[capacity];
        this.front=-1;
        this.rear=-1;    
    }

    // method for traversing and printing the queue
    public void printQueue(){
        if (!isEmpty()) {
            int i = front;
            System.out.println();
            do {
                System.out.print(queue[i] + " ");
                if(i==rear)
                    break;
                i = (i + 1) % (queue.length);
            } while (i != front);
    }
        else System.out.println("[]");
    }
        
    // method for adding the value from the Rear
    public boolean enQueue(int value) {
        if(isFull())
            System.out.println("Queue is full");
        if(isEmpty())
        {
            front=rear=0;
            queue[rear]=value;
            return true;
        }
        rear=(rear+1)%capacity;
        queue[rear]=value;
        return true;
    }
    
    //method for removing the value from Front
    public boolean deQueue() {
        if(isEmpty()){
            System.out.println("Queue is empty");
            return false;
        }
            
        if(front==rear){
            front=rear=-1;
            return true;
            }
            
        front=(front+1)%capacity;
        return true;
    }
    
    //method will return the Front value in queue
    public int Front() {
        if(isEmpty()){
            System.out.println("Queue is empty");
            return -1;
        }
            
        return queue[front];
    }
    
    // method will return the Rear value
    public int Rear() {
         if(isEmpty()){
            System.out.println("Queue is empty");
            return -1;
         }
           
        return queue[rear];
    }
    
    // this method will check whether the queue is empty or not
    public boolean isEmpty() {
       if(rear==-1 && front==-1)
           return true;
        return false;
    }
    
    // for checking whether the queue is full or not
    public boolean isFull() {
        if((rear+1) % capacity==front)
            return true;
        return false;
    }
}

// main class
public class Main
{
	public static void main(String[] args) {
        // object of MyCircularQueue class created
		MyCircularQueue q = new MyCircularQueue(10);
		q.printQueue();
        //adding values
		q.enQueue(4);
		q.enQueue(5);
		q.enQueue(7);
		q.enQueue(40);
		q.printQueue();
        //removing values
		q.deQueue();
		q.deQueue();
		q.deQueue();
		q.printQueue();
		System.out.println(q.Front());
		System.out.println(q.Rear());
		System.out.println(q.isEmpty());
		
		  
	}
}
