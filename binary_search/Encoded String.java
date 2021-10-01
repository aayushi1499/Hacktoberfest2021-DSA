//Program to print For each test case,the decoded string, in a separate line.
//Problem Statement is from codechef.

package CodeChef;
import java.util.Scanner;
public class EncodedStrings {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		while(t-- != 0) {
			int n = s.nextInt();
			String str = s.next();
			String str2 = "abcdefghijklmnop";
			for(int i=0; i<n; i=i+4) {
				int sum=0;
				int k=0;
				int end=i+4;
				for(int j=end-1; j>=i; j--) {
					int val=Integer.parseInt(str.substring(j, j+1));
					sum=sum+(val*(int)Math.pow(2,k));
					k++;
				}
				System.out.print(str2.charAt(sum));
			}
			System.out.println();
		
	}
		s.close();
}
}
