import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class ButtonPanel extends JPanel {
  public ButtonPanel(JTextPane display) {
    super.setLayout(new GridLayout(4, 4));
    JButton[] digits = new JButton[10];
    for (int i = 1; i <= 3; i++) {
      digits[i] = new JButton(Integer.toString(i));
      add(digits[i]);
    }
    JButton plus = new JButton("+");
    add(plus);
    for (int i = 4; i <= 6; i++) {
      digits[i] = new JButton(Integer.toString(i));
      add(digits[i]);
    }
    JButton minus = new JButton("-");
    add(minus);
    for (int i = 7; i <= 9; i++) {
      digits[i] = new JButton(Integer.toString(i));
      add(digits[i]);
    }
    JButton multiply = new JButton("*");
    add(multiply);
    JButton divide = new JButton("/");
    JButton equals = new JButton("=");
    JButton clear = new JButton("C");
    digits[0] = new JButton("0");
    add(digits[0]);
    add(divide);
    add(clear);
    add(equals);

    ActionListener addToDisplayAction = new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        display.setText(display.getText() + ((JButton) e.getSource()).getText());
      }
    };
    for (int i = 0; i <= 9; i++) {
      digits[i].addActionListener(addToDisplayAction);
    }
    plus.addActionListener(addToDisplayAction);
    minus.addActionListener(addToDisplayAction);
    multiply.addActionListener(addToDisplayAction);
    divide.addActionListener(addToDisplayAction);

    clear.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        display.setText("");
      }
    });

    equals.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        String[] operands = display.getText().split("[\\+\\-\\*\\/]");
        int operand1 = Integer.parseInt(operands[0]);
        int operand2 = Integer.parseInt(operands[1]);
        int result = 0;
        if (display.getText().contains("+")) {
          result = operand1 + operand2;
        } else if (display.getText().contains("-")) {
          result = operand1 - operand2;
        } else if (display.getText().contains("*")) {
          result = operand1 * operand2;
        } else if (display.getText().contains("/")) {
          try {
            result = operand1 / operand2;
          } catch (ArithmeticException ex) {
            display.setText("Cannot divide by zero");
            return;
          }
        }
        display.setText(Integer.toString(result));
      }
    });
  }
}

class Calculator extends JFrame {
  public Calculator() {
    super("Calculator");
    super.setSize(400, 400);
    super.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    super.setVisible(true);
    setLayout(new GridLayout(2, 1));
    JTextPane display = new JTextPane();
    display.setFont(new Font("Arial", Font.PLAIN, 20)); // Increase the font size to 20
    add(display);
    display.setEditable(false);
    add(new ButtonPanel(display));
    setVisible(true);
  }
}

public class q5 {
  public static void main(String[] args) {
    new Calculator();
  }
}