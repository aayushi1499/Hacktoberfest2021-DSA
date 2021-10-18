public class  lps
{
static int lps(String s)
{
	int a = s.length();
	if(a < 2) {
		return 0;
	}

	int len = 0;
	int i = (a + 1)/2;
	while(i < a)
	{
		if(s.charAt(i) == s.charAt(len))
		{
		++len;
		++i;
		}
		else
		{
		i = i - len + 1;
		len = 0;
		}
	}
	return len;

}
public static void main (String[] args)
{
	String s = "xyzxxyz";
	System.out.println(lps(s));
}
}
