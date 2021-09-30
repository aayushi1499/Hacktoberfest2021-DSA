
/**
 * 
 * All Problem related to Array and Strings.
 * 
 */

import java.util.Scanner;
import java.net.InetSocketAddress;
import java.util.Arrays; 

class ArrayStringProblem {

    /**
     * 
     * problem 1 : is all the character in the string is unique. 
     */

    public static boolean isUnique(String str) {
        boolean[] charSet = new boolean[128];
        if (str.length() > 128) {
            return false;
        }
        for(int i = 0; i < str.length(); i++)
        {
            int val = str.charAt(i);
            if (charSet[val]) {
                return false;
            }
            charSet[val] = true;
        }
        return true; 
    }



    /**
     * 
     * problem 2 : check permutation ; check wheter string 2 is a permutation of string1.
     * 
     */

    public static String sort(String str) {
        char[] arr = str.toCharArray();
        Arrays.sort(arr);
        return new String(arr);
    }
    
    public static boolean permutation(String str1, String str2)
    {
        if (str1.length() != str2.length()) {
            return false;
        }
        
        return sort(str1).equals(sort(str2)); 
    }
    
    /**
     * version 2 : check whether both string have same character count. 
     */

    public static boolean permutationVersion2(String str1, String str2)
    {
        if(str1.length() != str2.length()) {
            return false; 
        }
        
        int[] charCount = new int[128];
        char[] content = str1.toCharArray();
        for (char c : content) {
            charCount[c]++;
        }
        
        for(int i = 0; i < str2.length(); i++)
        {
            int val = (int) str2.charAt(i);
            charCount[val]--;
            if (charCount[val] < 0) {
                return false; 
            }
        }
        return true; 
    }

    /**
     * 
     * problem 3 : replace space. 
     * 
     */

    public static void replaceSplace(char[] str, int trueLength)
    {
        int spaceCount = 0; 
        for(int i = 0;i < trueLength; i++) 
        {
            if (str[i] == ' ') {
                spaceCount += 1; 
            }
        }
        int index = trueLength + spaceCount * 2;
        if (trueLength < str.length) {
            str[index] = '\0';
            index--;
        }
        for(int i = trueLength - 1; i >= 0; i--) {
            if (str[i] == ' ') {
                str[index] = '0';
                str[index - 1] = '2';
                str[index - 2] = '%';
                index -= 3; 
            } else {
                str[index] = str[i];
                index -= 1;
            }
            
        }
    }

    /**
     * problem 4 : OneEditAway.
     * one replace, one Remove, one Insert. 
     */

    public static boolean oneEditAway(String str1, String str2) {
        if (str1.length() == str2.length()) {
            return oneReplaceEdit(str1, str2);    
        } else if(str1.length() == str2.length() + 1) {
            return oneInsertEdit(str2, str1);
        } else if(str1.length() + 1 == str2.length()) {
            return oneInsertEdit(str1, str2); 
        }
        return false; 
    }

    public static boolean oneReplaceEdit(String str1, String str2) {
        boolean isDifferent = false;
        for (int i = 0; i < str1.length(); i++) {
            if (str1.charAt(i) != str2.charAt(i)) {
                if (isDifferent) {
                    return false;
                }
                isDifferent = true;
            }
        }
        return true; 
    }

    public static boolean oneInsertEdit(String str1, String str2) {
        int index1 = 0, index2 = 0;
        while (index1 < str1.length() && index2 < str2.length()) {
            if (str1.charAt(index1) != str2.charAt(index2)) {
                if (index1 != index2) {
                    return false;
                } else {
                    index2++;
                }
            } else {
                index1++;
                index2++;
            }
        }
        return true; 
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in); 
        /**
         * problem 1 : uniQue character in string. 
         */
       
        /** String str = input.next();
        System.out.println(str);
        System.out.println(isUnique(str));*/
        
        /**
         * probleam 2: permution check whether string1 is permutation of string2. 
         * String str1 = input.next();
        String str2 = input.next();
        
        System.out.println(permutationVersion2(str1, str2)); */
        
        /**
         * probleam 3 : repace all space with %20; 
         String str = "mukesh sahani power                           ";  
        char[] string = new char[100];
        string = str.toCharArray();
        System.out.println(string.length);
        replaceSplace(string, 19);
        System.out.println(string);
         */

        String data1 = input.next(), data2 = input.next();
        System.out.println(oneEditAway(data1, data2));
        input.close(); 
    }
}
