import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class JDBCDelete {
    public static void main(String[] args) {

        String url = "jdbc:mysql://localhost:3306/testdb";
        String username = "root";
        String password = "root";

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");

            Connection con = DriverManager.getConnection(
                url, username, password
            );

            String query = "DELETE FROM students WHERE id = ?";

            PreparedStatement ps = con.prepareStatement(query);
            ps.setInt(1, 1);

            int rows = ps.executeUpdate();

            if (rows > 0) {
                System.out.println("Record deleted successfully!");
            } else {
                System.out.println("No record found.");
            }

            ps.close();
            con.close();

        } catch (ClassNotFoundException | SQLException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
