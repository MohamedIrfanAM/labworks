class Employee {
  String name;
  int age;
  String phoneNumber;
  String address;
  int salary;

  void printSalary() {
    System.out.println("Salary of Employee = " + this.salary);
  }
}

class Officer extends Employee {
  String specialization;
}

class Manager extends Employee {
  String department;
}

public class q2 {
  public static void main(String[] args) {
    Manager manager = new Manager();
    Officer officer = new Officer();

    // Manager
    manager.name = "Irfan";
    manager.phoneNumber = "7994747426";
    manager.address = "Thrissur";
    manager.age = 19;
    manager.department = "CSE";
    manager.salary = 100000;
    System.out.println("Manager");
    System.out.println("Name = " + manager.name);
    System.out.println("Phone Number = " + manager.phoneNumber);
    System.out.println("Address = " + manager.address);
    System.out.println("Age = " + manager.age);
    System.out.println("Department = " + manager.department);
    System.out.println("Salary = " + manager.salary);
    // Officer
    officer.name = "Mufasil";
    officer.phoneNumber = "9021380293";
    officer.address = "Kozhikode";
    officer.age = 20;
    officer.salary = 10000;
    officer.specialization = "AI";
    System.out.println("\nOfficer");
    System.out.println("Name = " + officer.name);
    System.out.println("Phone Number = " + officer.phoneNumber);
    System.out.println("Address = " + officer.address);
    System.out.println("Age = " + officer.age);
    System.out.println("specialization = " + officer.specialization);
    System.out.println("Salary = " + officer.salary);
  }
}
