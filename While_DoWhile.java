import java.util.Scanner;

public class While_DoWhile {
	//We use while for increase x, and we use  do-while for verify if you write a negative number
	//We use try-catch for verify if you write a number or a letter 
	public static void main(String[] args) {

		Scanner sc= new Scanner(System.in);
		int x=0,cont=0,y=0;
		try {
			//verify if you write a integer and not negative number
			do {
				System.out.println("Tell me a  integer:");
				cont=sc.nextInt();
			} while (cont<0);
			//End verify and do-while
			System.out.println("Cont: "+cont);
			//we increase x and stoped when x its superior than cont
			while (x<=cont) {
				x++;
				System.out.print(x+"\t");
			}
			//End while
			System.out.println("\nExit because x its superior than cont (x="+x+", cont="+cont+" )");
		} catch (Exception e) {
			//when its a letter or diferents than number its activated this exception
			System.out.println("Its not a number, only a Integer (0>...)");

		}


	}

}
