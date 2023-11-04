
abstract class Shape {
  abstract int numberOfSides();
}

class Triangle extends Shape {
  int numberOfSides() {
    return 3;
  }
}

class Rectangle extends Shape {
  int numberOfSides() {
    return 4;
  }
}

class Hexagon extends Shape {
  int numberOfSides() {
    return 6;
  }
}

public class q4 {
  public static void main(String[] args) {
    Triangle t = new Triangle();
    Rectangle r = new Rectangle();
    Hexagon h = new Hexagon();
    System.out.println("Triangle = " + t.numberOfSides());
    System.out.println("Rectangle = " + r.numberOfSides());
    System.out.println("Hexagon = " + h.numberOfSides());
  }
}
