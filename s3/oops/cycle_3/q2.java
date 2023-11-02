import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class q2 {
  public static void main(String[] args) {
    try {
      System.out.print("Enter file name: ");
      Scanner sc = new Scanner(System.in);
      String input = sc.nextLine();
      sc.close();
      FileReader fr = new FileReader(input);
      int lineNumber = 1;
      System.out.print(lineNumber + " - ");
      while (true) {
        int i = fr.read();
        if (i == -1) {
          break;
        }
        System.out.print((char) i);
        if ((char) i == '\n') {
          lineNumber++;
          System.out.print(lineNumber + " - ");
        }
      }
      fr.close();
    } catch (IOException e) {
      System.out.println("An error occurred.");
      e.printStackTrace();
    }
  }
}