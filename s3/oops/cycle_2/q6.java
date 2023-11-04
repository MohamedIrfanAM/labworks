class Employee {
  String name;
  int salary;
}

public class q6 {
  public static void main(String[] args) {
    Employee a = new Employee();
    Employee b = new Employee();
    a.name = "Irfan";
    a.salary = 100000;
    b.name = "Mufasil";
    b.salary = 10000;
    b = null;
    System.gc();
    System.out.println(a.name + " - " + a.salary);
  }
}
