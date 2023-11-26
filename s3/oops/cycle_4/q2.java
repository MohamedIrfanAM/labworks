import java.util.Scanner;

class AgeException extends Exception {
  AgeException(String s) {
    super(s);
  }
}

public class q2 {
  public static void validateAge(int age) throws AgeException {
    System.out.println("inside validateAge()");
    if (age < 18) {
      throw new AgeException("Age is less than 18");
    } else {
      System.out.println("No exception");
    }
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    try {
      System.out.print("Enter age: ");
      int age = sc.nextInt();
      validateAge(age);
      System.out.println("Person is eligible to vote");
    } catch (AgeException e) {
      System.out.println("Age Exception\n" + e);
    } catch (Exception e) {
      System.out.println("Exception");
    } finally {
      System.out.println("Finally block");
      sc.close();
    }
  }
}