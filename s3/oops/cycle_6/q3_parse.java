import java.util.Scanner;

class q3{

  public static void quickSort(String [] arr,int l,int r,int n){
    if(l >= r) return;
    int p = l;
    int ll = l;
    int rr = r;

    int L = java.lang.Integer.parseInt(arr[l]);
    int P = java.lang.Integer.parseInt(arr[p]);
    int R = java.lang.Integer.parseInt(arr[r]);
    l++;
    while(l < r){
      L = java.lang.Integer.parseInt(arr[l]);
      P = java.lang.Integer.parseInt(arr[p]);
      R = java.lang.Integer.parseInt(arr[r]);
      if(L <= P){
        l++;
        continue;
      }
      if(P >= R){
        String temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        l++;
      }
      r--;
    } 
    L = java.lang.Integer.parseInt(arr[l]);
    if(L > P){
      l--;
    }
    String temp = arr[l];
    arr[l] = arr[p];
    arr[p] = temp;
    int x = p;
    p = l;
    l = x;

    if(p != l){
      quickSort(arr,ll,p-1,n);
      quickSort(arr,p+1,rr,n);
    }
    else{
      quickSort(arr,ll+1,rr,n);
    }
  }

  public static void main(String[] args)
  {
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter size of the array: ");
    int n =  sc.nextInt(); 
    String[] arr = new String[n];
    sc.nextLine();
    for(int i = 0; i < n; i++){
      System.out.print("\nEnter element " + (i+1) + " : ");
      arr[i] = sc.nextLine();
    }

    quickSort(arr , 0 ,n-1,n);

    System.out.println("\nSorted array = ");
    for(int i=0; i< n; i++){
      System.out.print(arr[i] + " ");
    }
  }
}
