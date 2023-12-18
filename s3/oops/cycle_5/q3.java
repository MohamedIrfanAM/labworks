import javax.swing.JFrame;
import javax.swing.JTextField;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class q3 extends JFrame {
  public q3() {
    setTitle("Key Event Example");
    setSize(300, 200);
    setLayout(null);

    JTextField textField = new JTextField(20);

    textField.setBounds(50, 50, 150, 20);
    textField.addKeyListener(new KeyAdapter() {
      public void keyTyped(KeyEvent e) {
        System.out.println("Key Typed: " + e.getKeyChar());
      }

      public void keyPressed(KeyEvent e) {
        System.out.println("Key Pressed: " + e.getKeyChar());
      }

      public void keyReleased(KeyEvent e) {
        System.out.println("Key Released: " + e.getKeyChar());
      }
    });

    add(textField);
  }

  public static void main(String[] args) {
    q3 frame = new q3();
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.setVisible(true);
  }
}
