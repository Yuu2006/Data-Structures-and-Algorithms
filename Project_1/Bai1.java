package Project_1;
import java.util.Scanner;

public class Bai1{
    public void Input(int[] a, int n){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the elements of array: ");
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
        }
    }
    
    public void Output(int[] a, int n){
        for (int i = 0; i < n; i++) {
            System.out.print(a[i] + " ");
        }
    }
    
    public int binary_Search(int[] a, int n, int k){
        int l = 0;
        int r = n - 1;
        int mid;
        while(l <= r){
            mid = (l + r) / 2;
            if(a[mid] == k) return mid;
            else if(a[mid] < k) l = mid + 1;
            else r = mid - 1;
        }   
        return -1;    
    }
    
    // This is the template: //

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Array size: ");
        int n = sc.nextInt();
        int[] a = new int[n];
        Bai1 b1 = new Bai1();
        b1.Input(a, n);
        System.out.println("The elements of the array are: ");
        b1.Output(a, n);
        System.out.print("\nEnter the number you want to find: ");
        int k = sc.nextInt();
        System.out.print("The number you want to find at index: ");
        System.out.println(b1.binary_Search(a, n, k));
        sc.close();
    }
}