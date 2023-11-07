import java.util.Scanner;
class Node{
  Node prev;
  Node next;
  int data;
}

class doubleLinkedList{
  Node head;
  Node tail;
  int size;
  doubleLinkedList(){
    head = new Node();
    tail= new Node();
    size=0;
  }
  public void insert(int data){
    Node newNode=new Node();
    newNode.data=data;
    newNode.next=null;
    if(size == 0){
      newNode.prev = null;
      head = newNode;
      tail = newNode;
    }
    else{
      newNode.prev=tail;
      tail.next=newNode;
      tail = newNode;
    }
    size++;
  }
    
  public void display(){
    Node current = head;
    while(current != null)
    {
      System.out.print(current.data + " ");
      current = current.next;
    }
    System.out.print("\n");
  }

  public void delete(int data){
    Node current = head;
    while(current != null)
    {
      if(current.data == data){
          if(current.prev != null)current.prev.next = current.next;
          if(current.next != null)current.next.prev = current.prev;
          current = null;
          break;
      }
      current = current.next;
    }
  }
}

class q1{
  public static void main(String[] args)
  {
    doubleLinkedList d = new doubleLinkedList();
    Scanner sc = new Scanner(System.in);
    int option;
    do{
      System.out.print("1)Insert\n2)Delete\n3)Display\n4)Exit\nOption: ");
      option = sc.nextInt();
      if(option == 1){
        System.out.print("\nEnter data to insert: ");
        int data = sc.nextInt(); 
        d.insert(data);
      }
      else if(option == 2){
        System.out.print("\nEnter data to delete: ");
        int data = sc.nextInt(); 
        d.delete(data);
        d.display();
      }
      else if(option == 3){
        d.display();
      }
    }while(option != 4);
  }
}
