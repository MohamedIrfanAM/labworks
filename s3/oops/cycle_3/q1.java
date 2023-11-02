import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class q1 {
  public static void main(String[] args) {
    try {
      FileWriter fw = new FileWriter("file.txt");
      System.out.println("Line to write to the file: ");
      Scanner sc = new Scanner(System.in);
      String input = sc.nextLine();
      sc.close();
      fw.write(input);
      fw.close();
      System.out.println("Successfully wrote to the file.");
      FileReader fr = new FileReader("file.txt");
      while (true) {
        int i = fr.read();
        if (i == -1) {
          break;
        }
        System.out.print((char) i);
      }
      fr.close();
    } catch (IOException e) {
      System.out.println("An error occurred.");
      e.printStackTrace();
    }
  }
}