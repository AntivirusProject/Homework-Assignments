package hexToBianary;

import java.util.*;

public class Converter {
	

	
	
	


	public static int hexToDec(char str){
	
		int num = -1;
		
		if(str == 'A'){
			 num = 10;
		}
		else if(str == 'B'){
			 num = 11;
		}
		else if(str == 'C'){
			 num = 12;
		}
		else if(str == 'D'){
			num = 13;
		}
		else if(str == 'E'){
			 num = 14;
		}
		else if(str == 'F'){
			num = 15;
		}
		else if(str >= '0' && str <= '9'){
			num = Integer.parseInt("" + str);
			
		}
		
		else{
			num = -1;
		}
		return num;
		
	}	
	
	public static String decToBin(int num){
	
	int remainder;
	
	char b[] = {'0','0','0','0'};
	int i = 3;
	
	String s = new String(b);
	
	while(true){
		int dividend = num / 2;
			remainder = num % 2;
			b[i--] = (char) ('0'+remainder);
			
			
			
			if(dividend < 2){
			b[i] = (char) ('0'+dividend);

			System.out.print(b);
			break;
		}
		
			else{
			num = dividend;
			continue;
			
		}
			
	}
	
	return s;
			
		
	}	
}

