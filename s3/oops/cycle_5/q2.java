import java.awt.Color;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JFrame;
import javax.swing.JPanel;

public class q2 extends JPanel implements MouseListener {
  public q2() {
    addMouseListener(this);
    super.setBackground(Color.RED);
  }

  public void mouseClicked(MouseEvent e) {
    System.out.println("Mouse clicked");
    super.setBackground(Color.GREEN);
  }

  public void mouseEntered(MouseEvent e) {
    System.out.println("Mouse entered");
    super.setBackground(Color.BLUE);
  }

  public void mouseExited(MouseEvent e) {
    System.out.println("Mouse exited");
    super.setBackground(Color.RED);
  }

  public void mousePressed(MouseEvent e) {
    System.out.println("Mouse pressed");
    super.setBackground(Color.YELLOW);
  }

  public void mouseReleased(MouseEvent e) {
    System.out.println("Mouse released");
    super.setBackground(Color.ORANGE);
  }

  public static void main(String[] args) {
    JFrame frame = new JFrame("Hello World!");
    frame.setSize(200, 200);
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.add(new q2());
    frame.setVisible(true);
  }
}