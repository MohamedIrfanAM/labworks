import java.util.Scanner;
import java.util.StringTokenizer;

public class q5 {
  public static void main(String[] args) {
    System.out.print("Enter list of integers with one space gap: ");
    Scanner sc = new Scanner(System.in);
    String list = sc.nextLine();
    StringTokenizer st = new StringTokenizer(list);
    int sum = 0;
    while (st.hasMoreTokens()) {
      String word = st.nextToken();
      int num = Integer.parseInt(word);
      System.out.print(num + " ");
      sum += num;
    }
    System.out.print("\n");
    System.out.println("Sum = " + sum);
    sc.close();
  }
}