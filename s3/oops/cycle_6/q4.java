import java.util.Scanner;

class BinaryHeap{
  int size;
  int root;
  int tail;
  int[] arr;
  BinaryHeap(int size)
  {
    this.size = size;
    this.arr = new int[size];
    this.tail = -1;
    this.root = 0;
  }
  public void heapify(int loc){
    int largest = loc;
    int left = ((loc+1)*2)-1;
    int right = ((loc+1)*2);
    if(left <= tail && arr[left] > arr[largest] ){
      int temp = arr[left];
      arr[left] = arr[largest];
      arr[largest] = temp;
      largest = left;
    }
    if(right <= tail && arr[right] > arr[largest] ){
      int temp = arr[right];
      arr[right] = arr[largest];
      arr[largest] = temp;
      largest = right;
    }
    if(largest != loc){
      heapify(largest);
    }
  }
  public void insert(int data){
    tail++;
    arr[tail] = data;
    int parent = tail/2;
    int child = tail;
    while(child > 0){
      if(arr[parent] < arr[child]){
        int temp = arr[parent];
        arr[parent] = arr[child];
        arr[child] =  temp;
      }
      else{
        heapify(child);
      }
      child = parent;
      parent /= 2;
    }
  }
  public void delete(){
    if(tail == -1){
      System.out.println("Heap underflow!!");
      return;
    }
    arr[root] = arr[tail];
    tail--;
    heapify(0);
  }
  public void display(){
    if(tail == -1){
      System.out.println("Heap is empty!!");
      return;
    }
    int[] d = arr;
    int t = tail;
    System.out.println("");
    for(int i = 0; i <= t; i++){
      System.out.print(this.arr[root] + " ");
      delete();
    }
    System.out.println("");
    this.arr = d;
  }
}

class q4{
  public static void main(String[] args)
  {
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter size of the heap: ");
    int n =  sc.nextInt(); 
    BinaryHeap h = new BinaryHeap(n);
    for(int i = 0; i< n; i++){
      System.out.print("\nEnter element " + (i+1) + " : ");
      int x = sc.nextInt();
      h.insert(x);
    }
    h.display();
  }
}
