import java.util.Scanner;

public class SelectionSort {
    public static void selectionSorting(int arr[]) {
        int i = 0;
        int minElementIndex = 0;
        while (i < arr.length) 
        {  
            int min = arr[i];
            for(int j = i + 1; j <arr.length; j++) 
            {
                if ( arr[j] < min) {
                    min = arr[j];
                }
            }
            int k = 0;
            while (arr[k] != min) 
            {
                minElementIndex++;
                k++;
            }
            while (minElementIndex != i) 
            {
                arr[minElementIndex] = arr[minElementIndex - 1];
                minElementIndex--;
            }
            minElementIndex = 0; 
            arr[i] = min;
            i++;
        }
        for(int k = 0; k < arr.length; k++)
        {
            System.out.print(arr[k] + " ");
        }
    }
	
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the size of the array:");
		int n = sc.nextInt();
		int[] arr = new int[n];
		for(int i = 0; i < arr.length; i++) {
			System.out.println("Enter the elements of the array:");
			arr[i] = sc.nextInt();
		}
		selectionSorting(arr);
	}
}
