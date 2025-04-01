package Project_1;
import java.util.Scanner;

public class Bai3 {
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
    // quicksort
    public void Sort(int[] a, int l, int r){
        if(l >= r) return;
        int i = l, j = r;
        int mid = a[(l + r) / 2];
        while(i <= j){
            while(a[i] < mid) i++;
            while(a[j] > mid) j--;
            if(i <= j){
                swap(a, i, j);
                i++;
                j--;
            }    
        }
        if(l < j) Sort(a, l, j);
        if(i < r) Sort(a, i, r);
    }
    // swap
    private void swap(int[] a,int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    
    //template: 
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Array size: ");
        int n = sc.nextInt();
        int[] a = new int[n];
        Bai3 b3 = new Bai3();
        b3.Input(a, n);
        System.out.println("The elements of the array are: ");
        b3.Output(a, n);
        System.out.println("\nThe sorted array: ");
        b3.Sort(a, 0, n - 1);
        b3.Output(a, n);
    }
}
