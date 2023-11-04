import java.util.Scanner;

interface A {
  double add();

  double subtract();
}

interface B {
  double multiply();

  double divide();
}

class Calculator implements A, B {
  double a, b;

  public double add() {
    return a + b;
  }

  public double subtract() {
    return a - b;
  }

  public double multiply() {
    return a * b;
  }

  public double divide() {
    return a / b;
  }
}

public class q5 {
  public static void main(String[] args) {
    System.out.print("Enter two numbers: ");
    Scanner sc = new Scanner(System.in);
    double a = sc.nextDouble();
    double b = sc.nextDouble();
    sc.close();
    Calculator c = new Calculator();
    c.a = a;
    c.b = b;
    System.out.println("Add = " + c.add());
    System.out.println("Subtract = " + c.subtract());
    System.out.println("Multiply = " + c.multiply());
    if (b == 0) {
      System.out.println("Divide by 0 error");
    } else {
      System.out.println("Divide = " + c.divide());
    }
  }
}
