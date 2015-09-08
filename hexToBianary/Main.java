package hexToBianary;

import java.util.*;

public class Main{
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String bianaryString = "";
		String hex = sc.nextLine();
		
		int l = hex.length();
		for(int i  = 0; i < l; i++){
			int num = Converter.hexToDec(hex.charAt(i));
			
			String bin = Converter.decToBin(num);
			bianaryString = bianaryString + bin;
			
			if(num == -1){
				break;
			}
		}
		

		
	}
}
