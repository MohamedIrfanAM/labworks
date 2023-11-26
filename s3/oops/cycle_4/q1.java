public class q1 {
  public static void throwException(int size, int index) throws ArrayIndexOutOfBoundsException {
    System.out.println("inside throwException()");
    if (index >= size) {
      throw new ArrayIndexOutOfBoundsException("Array index out of bound");
    } else {
      System.out.println("No exception");
    }
  }

  public static void arrayException() {
    try {
      int[] arr = new int[5];
      throwException(5, 6);
      arr[6] = 10;
    } catch (ArrayIndexOutOfBoundsException e) {
      System.out.println("Array index out of bound");
    }
  }

  public static void main(String[] args) {
    try {
      int x = 10;
      arrayException();
      x = x / 0;
    } catch (ArithmeticException e) {
      System.out.println("Arithmetic Exception");
    } catch (Exception e) {
      System.out.println("Exception");
    } finally {
      System.out.println("Finally block");
    }
  }
}