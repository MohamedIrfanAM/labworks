import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class q3 {
  public static void main(String[] args) {
    try {
      System.out.print("Enter file name: ");
      Scanner sc = new Scanner(System.in);
      String input = sc.nextLine();
      sc.close();
      FileReader fr = new FileReader(input);
      int lineCount = 1, wordCount = 1, charCount = 0;
      while (true) {
        int i = fr.read();
        if (i == -1) {
          break;
        }
        charCount++;
        if ((char) i == '\n') {
          lineCount++;
          wordCount++;
        } else if ((char) i == ' ') {
          wordCount++;
        }
      }
      System.out.println("Char count = " + charCount);
      System.out.println("Word count = " + wordCount);
      System.out.println("Line count = " + lineCount);
      fr.close();
    } catch (IOException e) {
      System.out.println("An error occurred.");
      e.printStackTrace();
    }
  }
}