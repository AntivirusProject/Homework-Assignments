package calculator;
	
import java.util.*;
public class Calculator {





		    public static void main(String[] args){
		        Scanner scanner = new Scanner(System.in);
		        String s = scanner.nextLine();
		        String w  = result(s);
		        System.out.println("Result: "+w);
		    }
		    public static String before(String s, int i){       //number before operation mark
		        String str = s.substring(0,i);
		        String num = "";
		        for(int b=str.length()-1;b>=0;b--){
		            if(b==0 || !Character.isDigit(str.charAt(b-1))&&str.charAt(b-1)!='.'){
		                num=str.substring(b);
		                break;
		            }
		        }
		        return num;
		    }

		    public static String after(String s, int i){          //number after operation mark
		        String str = s.substring(i+1);
		        String num = "";
		        for(int a=0;a<=str.length();a++){
		            if(a==str.length() || !Character.isDigit(str.charAt(a))&&str.charAt(a)!='.'){
		                num=str.substring(0,a);
		                break;
		            }
		        }
		        return num;
		    }
		    public static String result(String s){
		        char o = '(';
		        char c = ')';
		        while(s.contains(Character.toString(o))||s.contains(Character.toString(c))){
		            String in;
		            if(s.contains(Character.toString(o))){
		                System.out.println(s);
		                in = s.substring(s.indexOf(o)+1);
		                System.out.println("ino: "+in);
		                s = s.substring(0, s.indexOf(o))+ result(in);
		            }else if(s.contains(Character.toString(c))){
		                in = s.substring(0, s.indexOf(c));
		                System.out.println("inc: "+in);
		                return count(in)+s.substring(s.indexOf(c)+1);
		            }
		        }
		        return count(s);
		    }
		    public static String count(String s){
		        String num1;
		        double n1;
		        String num2;
		        double n2;

		        for(int i=0; i<s.length();i++){
		            if(s.charAt(i)=='*'||s.charAt(i)=='/'){
		                num1 = before(s,i);
		                System.out.println("nu1:" +num1);
		                num2 = after(s,i);
		                System.out.println("nu2:" +num2);
		                n1 = Double.parseDouble(num1);
		                n2 = Double.parseDouble(num2);
		                double res = (s.charAt(i))=='*' ? n1*n2: n1/n2;
		                s = s.substring(0,i-num1.length())+res+s.substring(i+num2.length()+1);

		                i = 0;
		            }
		        }
		        for(int i=0; i<s.length();i++){
		            if(s.charAt(i)=='+'||s.charAt(i)=='-'){
		                num1 = before(s,i);
		                num2 = after(s,i);
		                n1 = Double.parseDouble(num1);
		                n2 = Double.parseDouble(num2);
		                double res = (s.charAt(i))=='+' ? n1+n2: n1-n2;
		                s = s.substring(0,i-num1.length())+res+s.substring(i+num2.length()+1);
		                System.out.println("+:" + s);
		                i=0;
		            }
		        }
		        return s;
		    }
		}
	}

}
