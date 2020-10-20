/*
  This is a simple calculator program
  @Author Srinidh Reddy
*/  
  
import java.util.Scanner;
public class arithmetic_operations {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        //This loops run until you choose to exit
        while(true)
        {
            
            System.out.println("Enter the two numbers to perform operations ");
            System.out.print("Enter the first number : ");
            int x = input.nextInt();
            System.out.print("Enter the second number : ");
            int y = input.nextInt();
            System.out.println("");
            System.out.println("Choose the operation you want to perform ");
            System.out.println("Choose 1 for ADDITION");
            System.out.println("Choose 2 for SUBTRACTION");
            System.out.println("Choose 3 for MULTIPLICATION");
            System.out.println("Choose 4 for DIVISION");
            System.out.println("Choose 5 for MODULUS");
            System.out.println("Choose 6 for EXIT");
            int n = input.nextInt();
            switch(n)
            {
                case 1:
                addition(x,y);
                break;
 
                case 2:
                subtraction(x,y);
                break;
 
                case 3:
                multiply(x,y);
                break;
 
                case 4:
                division(x,y); 
                break;
 
                case 5:
                modulo(x,y);
                break;
 
                case 6:
                System.exit(0);
            }
        }
    }
    public static void addition(int x,int y) {
        int add;
        add = x + y;
        System.out.println("Result : "+add);   
    }

    public static void subtraction(int x,int y) {
        int sub;
        sub = x - y;
        System.out.println("Result : "+sub);   
    }

    public static void multiply(int x,int y) {
        int mul;
        mul = x * y;
        System.out.println("Result : "+mul);   
    }

    public static void division(int x,int y) {
        float div;
        div = (float) x / y;
         System.out.print("Result : "+div); 
    }

    public static void modulo(int x,int y) {
        int mod;               
        mod = x % y;
        System.out.println("Result : "+mod);
    }
   
}
