import java.util.Scanner;

class Area {
  static double calculate(double r) {
    return 3.14 * r * r;
  }

  static double calculate(double a, double b) {
    return a * b;
  }

  static double calculate(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return Math.sqrt(s * (s - a) * (s - b) * (s - c));
  }
}

class q1 {
  public static void main(String[] args) {
    System.out.println("1)Circle\n2)Rectangle\n3)Triangle");
    System.out.print("Enter the choice: ");
    Scanner sc = new Scanner(System.in);
    int ch = sc.nextInt();
    if (ch == 1) {
      System.out.print("Enter radius: ");
      int r = sc.nextInt();
      System.out.println("Area = " + Area.calculate(r));
    } else if (ch == 2) {
      System.out.print("Enter sides of rectangle: ");
      int a = sc.nextInt();
      int b = sc.nextInt();
      System.out.println("Area = " + Area.calculate(a, b));
    } else if (ch == 3) {
      System.out.print("Enter sides of trangle: ");
      int a = sc.nextInt();
      int b = sc.nextInt();
      int c = sc.nextInt();
      System.out.println("Area = " + Area.calculate(a, b, c));
    }
    sc.close();
  }
}