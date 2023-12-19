import java.util.Scanner;

class q2 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter size of the array: ");
    int n = sc.nextInt();
    int l = -1;
    int r = n;
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = sc.nextInt();
    }
    System.out.print("\nEnter data to search: ");
    int data = sc.nextInt();
    while (r - l > 1) {
      int m = l + (r - l) / 2;
      if (a[m] <= data) {
        l = m;
      } else {
        r = m;
      }
    }
    if (a[l] == data) {
      System.out.println("Data found at - " + l);
    } else {
      System.out.println("Data not found");
    }
    sc.close();
  }
}
