import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class q1 extends JPanel implements MouseMotionListener, MouseListener {
  int x1, y1, x2, y2;
  int shape = 0;

  public q1() {
    addMouseMotionListener(this);
    addMouseListener(this);
    super.setBackground(Color.WHITE);

    // Make radio buttons
    ButtonGroup group = new ButtonGroup();
    JRadioButton rectangle = new JRadioButton("Rectangle");
    JRadioButton oval = new JRadioButton("Oval");
    JRadioButton line = new JRadioButton("Line");
    group.add(rectangle);
    group.add(oval);
    group.add(line);
    add(line);
    add(rectangle);
    add(oval);

    line.setSelected(true);
    line.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        shape = 0;
      }
    });
    rectangle.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        shape = 1;
      }
    });
    oval.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        shape = 2;
      }
    });
  }

  public void mouseClicked(MouseEvent e) {
  }

  public void mouseEntered(MouseEvent e) {
  }

  public void mouseExited(MouseEvent e) {
  }

  public void mousePressed(MouseEvent e) {
    x1 = e.getX();
    y1 = e.getY();
  }

  public void mouseReleased(MouseEvent e) {
  }

  public void mouseMoved(MouseEvent e) {
  }

  public void mouseDragged(MouseEvent e) {
    System.out.println("Mouse dragged");
    x2 = e.getX();
    y2 = e.getY();
    System.out.println(x1 + " " + y1 + " " + x2 + " " + y2);
    repaint();
  }

  public void paintComponent(Graphics g) {
    super.paintComponent(g);
    g.setColor(Color.BLACK);
    if (shape == 0)
      g.drawLine(x1, y1, x2, y2);
    else if (shape == 1)
      g.drawRect(x1, y1, x2 - x1, y2 - y1);
    else if (shape == 2)
      g.drawOval(x1, y1, x2 - x1, y2 - y1);
  }

  public static void main(String[] args) {
    JFrame frame = new JFrame("Paint Application");
    frame.setSize(400, 400);
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.add(new q1());
    frame.setVisible(true);
  }
}