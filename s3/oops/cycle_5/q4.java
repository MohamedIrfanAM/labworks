import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JFrame;
import javax.swing.JPanel;

public class q4 extends JPanel {
  public q4() {
  }

  protected void paintComponent(Graphics g) {
    super.paintComponent(g);
    g.setColor(Color.RED);

    int panelWidth = getWidth();
    int panelHeight = getHeight();

    // int pointSize = 2;
    int pointX = 20;
    int pointY = panelHeight / 2;

    // g.fillOval(pointX, pointY, pointSize, pointSize);
    int prevX = pointX;
    int prevY = pointY;
    g.setColor(Color.BLACK);
    g.drawLine(20, 0, 20, panelHeight);
    g.drawLine(0, pointY, panelWidth, pointY);
    for (int i = 0; i <= panelWidth; i++) {
      double angle = ((double) i * Math.PI) / 180.00;
      int x = pointX + i;
      int y = pointY - (int) (Math.sin(angle) * panelHeight / 4);
      g.setColor(Color.RED);
      g.drawLine(prevX, prevY, x, y);
      prevX = x;
      prevY = y;
      // g.fillOval(x, y, pointSize, pointSize);
    }
  }

  public static void main(String[] args) {
    JFrame frame = new JFrame("Hello World!");
    frame.setSize(600, 400);
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.add(new q4());
    frame.setVisible(true);
  }
}