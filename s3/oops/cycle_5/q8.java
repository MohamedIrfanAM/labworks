import java.sql.*;
import java.util.Scanner;

public class q8 {
  public static void main(String[] args) {
    try {
      Class.forName("com.mysql.cj.jdbc.Driver");
      Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/javalab", "root", "");
      Statement stmt = con.createStatement();
      Scanner scanner = new Scanner(System.in);
      System.out.print("Enter the number of students: ");
      int n = scanner.nextInt();
      scanner.nextLine();

      for (int i = 0; i < n; i++) {
        System.out.print("Enter the roll number of student " + (i + 1) + ": ");
        int rollNumber = scanner.nextInt();
        scanner.nextLine();

        System.out.print("Enter the name of student " + (i + 1) + ": ");
        String name = scanner.nextLine();

        System.out.print("Enter the CGPA of student " + (i + 1) + ": ");
        double cgpa = scanner.nextDouble();
        scanner.nextLine();

        String query = "INSERT INTO student (roll_no, name, cgpa) VALUES (" + rollNumber + ", '" + name + "', "
            + cgpa + ")";
        stmt.executeUpdate(query);
      }

      System.err.println("Students with CGPA > 7.0: ");
      ResultSet rs = stmt.executeQuery("SELECT * FROM student WHERE cgpa > 7.0");
      System.out.println("Roll No.\tName\t\tCGPA");
      System.out.println("----------------------------------------------");
      while (rs.next()) {
        System.out.printf("%d\t\t%s\t\t%.2f%n", rs.getInt(1), rs.getString(2), rs.getDouble(3));
      }

      scanner.close();
      con.close();
    } catch (Exception e) {
      System.out.println(e);
    }
  }
}
