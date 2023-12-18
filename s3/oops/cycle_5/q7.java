import java.sql.*;

public class q7 {
  public static void main(String[] args) {
    try {
      Class.forName("com.mysql.cj.jdbc.Driver");
      Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/javalab", "root", "");
      Statement stmt = con.createStatement();
      ResultSet rs = stmt.executeQuery("SELECT * FROM phonedetails");

      System.out.println("ID\tName\t\tBrand\t");
      System.out.println("--------------------------------------------------");

      while (rs.next()) {
        System.out.printf("%d\t%s\t\t%s\t\t%n", rs.getInt(1), rs.getString(2), rs.getString(3));
      }

    } catch (Exception e) {
      System.out.println(e);
    }
  }

}
