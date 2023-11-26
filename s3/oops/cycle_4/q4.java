class PrintMultiples {
  int n;

  synchronized public void print(int n) {
    for (int i = 1; i <= 5; i++) {
      System.out.println(n + " * " + i + " = " + (n * i));
    }
  }
}

class Thread1 extends Thread {
  PrintMultiples p;

  Thread1(PrintMultiples p) {
    this.p = p;
  }

  public void run() {
    p.print(5);
  }
}

class Thread2 extends Thread {
  PrintMultiples p;

  Thread2(PrintMultiples p) {
    this.p = p;
  }

  public void run() {
    p.print(7);
  }
}

public class q4 {
  public static void main(String[] args) {
    PrintMultiples p = new PrintMultiples();
    Thread1 t1 = new Thread1(p);
    Thread2 t2 = new Thread2(p);
    t1.start();
    t2.start();
  }
}