import java.util.Scanner;

public class ReverseNumberExample  
{  
    public static void main(String[] args)   
    {  
        System.out.print("Enter Number : ");
        int number = new Scanner(System.in).nextInt();   
        int reverse = 0;  
        while(number != 0)   
        {  
            int remainder = number % 10;  
            reverse = reverse * 10 + remainder;  
            number = number/10;  
        }  
        System.out.println("The reverse of the given number is: " + reverse);  
    }  
}  
