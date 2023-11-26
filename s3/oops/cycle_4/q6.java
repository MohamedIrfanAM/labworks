public class q6 extends Thread {
  public void run() {
    System.out.println("Thread is running");
  }

  public static void main(String[] args) {
    q6 t1 = new q6();
    System.out.println("Priority of t1: " + t1.getPriority());
    t1.setPriority(10);
    System.out.println("Priority of t1: " + t1.getPriority());
    System.out.println("Name of t1: " + t1.getName());
    t1.setName("Custom Thread Name");
    System.out.println("Name of t1: " + t1.getName());

    System.out.println("Name of Current Thread: " + Thread.currentThread().getName());
  }
}