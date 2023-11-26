
class Even extends Thread {
  public void run() {
    if (Random.k % 2 == 0) {
      System.out.println("Even: " + Random.k * Random.k);
      try {
        Thread.sleep(1000);
      } catch (InterruptedException ex) {
        System.out.println(ex);
      }
    }
  }
}

class Odd extends Thread {
  public void run() {
    if (Random.k % 2 != 0) {
      System.out.println("Odd: " + Random.k * Random.k * Random.k);
      try {
        Thread.sleep(1000);
      } catch (InterruptedException ex) {
        System.out.println(ex);
      }
    }
  }
}

class Random extends Thread {
  static int k = 0;

  public void run() {
    for (int i = 0; i < 10; i++) {
      k = (int) (Math.random() * 10);
      System.out.println("Random: " + k);
      Even e = new Even();
      Odd o = new Odd();
      e.start();
      o.start();
      try {
        Thread.sleep(1000);
      } catch (InterruptedException ex) {
        System.out.println(ex);
      }
    }
  }
}

public class q3 {
  public static void main(String[] args) {
    Random r = new Random();
    r.start();
  }
}