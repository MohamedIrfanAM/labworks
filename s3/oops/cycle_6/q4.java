import java.util.Scanner;

class BinaryHeap {
  int size;
  int root;
  int tail;
  int[] arr;

  BinaryHeap(int size) {
    this.size = size;
    this.arr = new int[size];
    this.tail = -1;
    this.root = 0;
  }

  public void heapify(int loc) {
    int largest = loc;
    int left = ((loc + 1) * 2) - 1;
    int right = ((loc + 1) * 2);
    if (left <= tail && arr[left] > arr[largest]) {
      largest = left;
    }
    if (right <= tail && arr[right] > arr[largest]) {
      largest = right;
    }
    if (largest != loc) {
      int temp = arr[loc];
      arr[loc] = arr[largest];
      arr[largest] = temp;
      heapify(largest);
    }
  }

  void sort() {
    for (int i = (size + 1) / 2; i >= 0; i--) {
      heapify(i);
    }
    for (int i = tail; i >= 0; i--) {
      int temp = arr[0];
      arr[0] = arr[i];
      arr[i] = temp;
      tail--;
      heapify(0);
    }
  }

  void display() {
    for (int i = 0; i < size; i++) {
      System.out.print(arr[i] + " ");
    }
    System.out.print("\n");
  }
}

class q4 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter size of the heap: ");
    int n = sc.nextInt();
    BinaryHeap h = new BinaryHeap(n);
    System.out.print("\nEnter elements of the heap: ");
    for (int i = 0; i < n; i++) {
      int x = sc.nextInt();
      h.arr[++h.tail] = x;
    }
    h.sort();
    h.display();
    sc.close();
  }
}
