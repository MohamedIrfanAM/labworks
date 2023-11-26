class PrintOddEven {
  int n;

  synchronized public void print(int n) {
    for (int i = 1; i <= 100; i++) {
      if (i % 2 == n) {
        System.out.print(i + " ");
      }
    }
  }
}

class EvenThread extends Thread {
  PrintOddEven p;

  EvenThread(PrintOddEven p) {
    this.p = p;
  }

  public void run() {
    p.print(0);
  }
}

class OddThread extends Thread {
  PrintOddEven p;

  OddThread(PrintOddEven p) {
    this.p = p;
  }

  public void run() {
    p.print(1);
  }
}

public class q5 {
  public static void main(String[] args) {
    PrintOddEven p = new PrintOddEven();
    EvenThread t1 = new EvenThread(p);
    OddThread t2 = new OddThread(p);
    t1.start();
    t2.start();
  }
}