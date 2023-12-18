import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class q6 implements ActionListener {
  private JFrame frame;
  private JPanel redPanel;
  private JPanel yellowPanel;
  private JPanel greenPanel;
  private JRadioButton redButton;
  private JRadioButton yellowButton;
  private JRadioButton greenButton;

  public q6() {
    frame = new JFrame("Traffic lights");
    frame.setSize(600, 400);
    frame.setLayout(new GridLayout(2, 1));
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    redPanel = new JPanel() {
      protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setColor(Color.RED);
        g.fillOval(20, 20, 100, 100);
      }
    };
    yellowPanel = new JPanel() {
      protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setColor(Color.YELLOW);
        g.fillOval(20, 20, 100, 100);
      }
    };
    greenPanel = new JPanel() {
      protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setColor(Color.GREEN);
        g.fillOval(20, 20, 100, 100);
      }
    };
    greenPanel.setVisible(false);
    redPanel.setVisible(false);
    yellowPanel.setVisible(false);

    JPanel lightPanel = new JPanel();
    lightPanel.setLayout(new GridLayout(1, 3));
    lightPanel.add(redPanel);
    lightPanel.add(yellowPanel);
    lightPanel.add(greenPanel);

    redButton = new JRadioButton("Red");
    yellowButton = new JRadioButton("Yellow");
    greenButton = new JRadioButton("Green");

    ButtonGroup Btgroup = new ButtonGroup();
    Btgroup.add(redButton);
    Btgroup.add(yellowButton);
    Btgroup.add(greenButton);

    redButton.addActionListener(this);
    yellowButton.addActionListener(this);
    greenButton.addActionListener(this);

    JPanel buttonPanel = new JPanel();
    buttonPanel.setLayout(new GridLayout(1, 3));
    buttonPanel.add(redButton);
    buttonPanel.add(yellowButton);
    buttonPanel.add(greenButton);

    frame.add(lightPanel);
    frame.add(buttonPanel);
    frame.setVisible(true);
  }

  public void actionPerformed(ActionEvent e) {
    redPanel.setVisible(false);
    yellowPanel.setVisible(false);
    greenPanel.setVisible(false);

    if (e.getSource() == redButton) {
      redPanel.setVisible(true);
    } else if (e.getSource() == yellowButton) {
      yellowPanel.setVisible(true);
    } else if (e.getSource() == greenButton) {
      greenPanel.setVisible(true);
    }
  }

  public static void main(String[] args) {
    new q6();
  }
}