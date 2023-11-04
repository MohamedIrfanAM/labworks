class Employee {
  String name;
  int salary;

  void calcSalary() {
    System.out.println("Salary of Employee is " + this.salary);
  }

  void display() {
    System.out.println("Name of the class is Employee");
  }
}

class Engineer extends Employee {
  void calcSalary() {
    System.out.println("Salary of Engineer is " + this.salary);
  }
}

public class q3 {
  public static void main(String[] args) {
    Engineer engineer = new Engineer();
    engineer.name = "Irfan";
    engineer.salary = 100000;
    engineer.display();
    engineer.calcSalary();
  }
}
