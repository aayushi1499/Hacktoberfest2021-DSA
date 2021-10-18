// Kashish Ahuja - codeitmin

// KBC Quiz
/* Take 10 questions: core java based questions
Two life lines: 50-50, change the question
Show total money won */

import java.util.Scanner;
import static java.lang.System.out;
import static java.lang.System.in;
import javax.swing.JOptionPane;

class KBC
{
	static	
	{
		out.println("Welcome to KBC... ");
	}

	static Scanner sc = new Scanner(in);

	public static int check(String userAns, String correctAns, int m)
	{
		if(userAns.equalsIgnoreCase("FF"))
		{
			JOptionPane.showMessageDialog(null,"\n50-50 life line activated");
			return 2;
		}
		
		else if(userAns.equalsIgnoreCase("CTQ"))
		{
			JOptionPane.showMessageDialog(null,"\nChange the question life line activated");
			JOptionPane.showMessageDialog(null,"New Question...");
			return 1;
		}

		else
		{
			if(userAns.equals(correctAns))
			{
				JOptionPane.showMessageDialog(null,"\nThat's the right answer.");
				if(m!=10)
				{
					JOptionPane.showMessageDialog(null,"Total money won: Rs " + m +"0 lakh");
					return 0;
				}
				else
				{
					JOptionPane.showMessageDialog(null,"Total money won: Rs 1Cr");
					JOptionPane.showMessageDialog(null,"You are now a CrorePati");
					JOptionPane.showMessageDialog(null,"ParttYYY Brroooo");
					return 0;
				}
			}
			else
			{
				JOptionPane.showMessageDialog(null,"\nThat's not the right answer. You lost.");
				JOptionPane.showMessageDialog(null,"Total money won: Rs " + (m-1) +"0 lakh");
				System.exit(0);
				return 0;
			}
		}
	}

	public static String lifeLine(boolean ff, boolean ctq)
	{
		if(ff==true)
		{
			if(ctq==true)
				return "\nLife line: 50-50 : FF, Change the question : CTQ";
			else
				return "\nLife line: 50-50 : FF";
		}
		else if(ctq==true)
			return "\nLife line: Change the question : CTQ";
		else
			return "\nLife line: No life lines left";
	}

	public static void questions()
	{
		String ans; 
		int money=0, chk;
		boolean ff=true, ctq=true;

		ans=JOptionPane.showInputDialog("\nWhich of these is not a phase of Agile approach? \nA) Application Database making \nB) Application Analysis \nC)Application Marketing \nD) Application Launching \n" + lifeLine(ff, ctq));
		money++;
		chk=check(ans, "C", money);
		if(chk==1)
		{
			money--;
			ctq=false;
		}
		else if(chk==2)
		{
			ff=false;
			ans=JOptionPane.showInputDialog("\nWhich of these is not a phase of Agile approach \nA) \nB) Application Analysis \nC)Application Marketing \nD) \n"+ lifeLine(ff,ctq));
			if(check(ans, "C", money)==1)
			{
				money--;
				ctq=false;
			}
		}

		ans=JOptionPane.showInputDialog("\nJava can not be defined as: ? \nA) Annotation programming \nB) Purely object oriented programming \nC) Object oriented programming \n D)Automation oriented programming\n"+ lifeLine(ff,ctq));
		money++;
		chk=check(ans, "D", money);
		if(chk==1)
		{
			money--;
			ctq=false;
		}
		else if(chk==2)
		{
			ff=false;
			ans=JOptionPane.showInputDialog("\nJava can not be defined as: ? \nA) Annotation programming \nB)   \nC) \nD)Automation oriented programming\n"+ lifeLine(ff,ctq));
			if(check(ans, "D", money)==1)
			{
				money--;
				ctq=false;
			}
		}

		ans=JOptionPane.showInputDialog("\nJVM is an: ?\nA) Compiler \nB)Interpreter \nC) Both \n D) None\n"+ lifeLine(ff,ctq));
		money++;
		chk=check(ans, "B", money);
		if(chk==1)
		{
			money--;
			ctq=false;
		}
		else if(chk==2)
		{
			ff=false;
			ans=JOptionPane.showInputDialog("\nJVM is an: ?\nA) Compiler \nB)Interpreter \nC) \nD) \n"+ lifeLine(ff,ctq));
			if(check(ans, "B", money)==1)
			{
				money--;
				ctq=false;
			}
		}
		

		ans=JOptionPane.showInputDialog("\nWhich of these is not a non-access level in java? \nA)Transition \nB) Strictfp \nC) Final \nD) Static\n"+ lifeLine(ff,ctq));
		money++;
		chk=check(ans, "A", money);
		if(chk==1)
		{
			money--;
			ctq=false;
		}
		else if(chk==2)
		{
			ff=false;
			ans=JOptionPane.showInputDialog("\nWhich of these is not a non-access level in java? \nA)Transition \nB) \nC) Final \nD) \n"+ lifeLine(ff,ctq));
			if(check(ans, "A", money)==1)
			{
				money--;
				ctq=false;
			}
		}

		ans=JOptionPane.showInputDialog("\nWhich of these is not a method provided by Scanner class? \nA) nextShort() \nB) nextLine() \nC)nextChar() \nD) nextBoolean()\n"+ lifeLine(ff,ctq));
		money++;
		chk=check(ans, "C", money);
		if(chk==1)
		{
			money--;
			ctq=false;
		}
		else if(chk==2)
		{
			ff=false;
			ans=JOptionPane.showInputDialog("\nWhich of these is not a method provided by Scanner class? \nA) nextShort() \nB) \nC)nextChar() \nD) \n"+ lifeLine(ff,ctq));
			if(check(ans, "C", money)==1)
			{
				money--;
				ctq=false;
			}
		}

		ans=JOptionPane.showInputDialog("\nIn java everything by default is of type? \nA) Public \nB) Private \nC) Protected \nD)Default\n"+ lifeLine(ff,ctq));
		money++;	
		chk=check(ans, "D", money);
		if(chk==1)
		{
			money--;
			ctq=false;
		}
		else if(chk==2)
		{
			ff=false;
			ans=JOptionPane.showInputDialog("\nIn java everything by default is of type?\nA) Public \nB) \nC) \nD)Default\n"+ lifeLine(ff,ctq));
			if(check(ans, "D", money)==1)
			{
				money--;
				ctq=false;
			}
		}

		ans=JOptionPane.showInputDialog("\nWhich of these is not a way of importing packages?\nA)Runtime \nB) Global \nC) Static \n D) Non-static\n"+ lifeLine(ff,ctq));
		money++;
		chk=check(ans, "A", money);
		if(chk==1)
		{
			money--;
			ctq=false;
		}
		else if(chk==2)
		{
			ff=false;
			ans=JOptionPane.showInputDialog("\nWhich of these is not a way of importing packages?\nA)Runtime \nB) Global \nC) \n D) \n"+ lifeLine(ff,ctq));
			if(check(ans, "A", money)==1)
			{
				money--;
				ctq=false;
			}
		}

		ans=JOptionPane.showInputDialog("\nWhich of these is a way of identifying an object in java?\nA) classname name \nB)new classname \nC) uppercase \n D) datatype name\n"+ lifeLine(ff,ctq));
		money++;
		chk=check(ans, "B", money);
		if(chk==1)
		{
			money--;
			ctq=false;
		}
		else if(chk==2)
		{
			ff=false;
			ans=JOptionPane.showInputDialog("\nWhich of these is a way of identifying an object in java?\nA) classname name \nB)new classname \nC) \n D)\n"+ lifeLine(ff,ctq));
			if(check(ans, "B", money)==1)
			{
				money--;
				ctq=false;
			}
		}

		ans=JOptionPane.showInputDialog("\nWhich of these java classes does not contain format() method?\nA) String \nB) DateFormat \nC)LocalDateFormat \nD) NumberFormat\n"+ lifeLine(ff,ctq));
		money++;
		chk=check(ans, "C", money);
		if(chk==1)
		{
			money--;
			ctq=false;
		}
		else if(chk==2)
		{
			ff=false;
			ans=JOptionPane.showInputDialog("\nWhich of these java classes does not contain format() method?\nA) \nB)  \nC)LocalDateFormat \nD) NumberFormat\n"+ lifeLine(ff,ctq));
			if(check(ans, "C", money)==1)
			{
				money--;
				ctq=false;
			}
		}

		ans=JOptionPane.showInputDialog("\nWhat is the correct output of DateFormat class with LONG static constant?\nA) 8/17/21 \nB)August 17, 2021 \nC) Tuesday, August, 17, 2021 \nD) Aug 17, 2021\n"+ lifeLine(ff,ctq));
		money++;	
		chk=check(ans, "B", money);
		if(chk==1)
		{
			money--;
			ctq=false;
		}
		else if(chk==2)
		{
			ff=false;
			ans=JOptionPane.showInputDialog("\nWhat is the correct output of DateFormat class with LONG static constant?\nA) \nB)August 17, 2021 \nC) Tuesday, August, 17, 2021 \n D)\n"+ lifeLine(ff,ctq));
			if(check(ans, "B", money)==1)
			{
				money--;
				ctq=false;
			}
		}

		ans=JOptionPane.showInputDialog("\nWhat is these dialog box method does not require null?\nA)showInputDialog() \nB) showMessageDialog() \nC) showConfirmDialog() \nD) showGraphicDialog()\n"+ lifeLine(ff,ctq));
		money++;
		chk=check(ans, "A", money);
		if(chk==1)
		{
			money--;
			ctq=false;
		}
		else if(chk==2)
		{
			ff=false;
			ans=JOptionPane.showInputDialog("\nWhat is these dialog box method does not require null?\nA)showInputDialog() \nB)  \nC) showConfirmDialog() \nD) \n"+ lifeLine(ff,ctq));
			if(check(ans, "A", money)==1)
			{
				money--;
				ctq=false;
			}
		}
	}

    static public void main(String...args) 
    {
		JOptionPane.showMessageDialog(null, "Welcome to KBC...");
        questions();
    }
}