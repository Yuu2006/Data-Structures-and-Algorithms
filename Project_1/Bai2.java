package Project_1;
import java.util.Scanner;

public class Bai2 {
    public void Input(int[] a, int n){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the elements of array: ");
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
        }
    }
    
    public void Output(int[] a, int n){
        System.out.println("The elements of the array are: ");
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

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Array size: ");
        int n = sc.nextInt();
        int[] a = new int[n];
        Bai2 b2 = new Bai2();
        b2.Input(a, n);
        b2.Output(a, n);
        do{      
            System.out.print("\nEnter the number: ");
            int k = sc.nextInt();
            if(k == -1){
                break;
            }
            else{
                System.out.print("The number you want to find at index: ");
                System.out.println(b2.binary_Search(a, n, k));
            }
        } while(true);
    }
}
