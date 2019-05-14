package pkg3;

import java.util.Scanner;

public class Maincode {

	public static void main(String[] args) {
		Scanner scanf = new Scanner(System.in);
		print("Number of Weighted Items: ");
		int num = scanf.nextInt();
		scanf.nextLine();
		
		WeighedItem[] w = new WeighedItem[num];
		for(int i = 0; i < num; i++)
		{
			String name;
			double unitprice, weight;
			print("NAME: ");
			name = scanf.nextLine();
			print("Unit Price: ");
			unitprice = scanf.nextDouble();
			print("Weight: ");
			weight = scanf.nextDouble();
			scanf.nextLine();
			w[i] = new WeighedItem(name, unitprice, weight);
			println(w[i].toString());
			
		}
		print("Number of Counted Items: ");
		num = scanf.nextInt();
		scanf.nextLine();
		CountedItem[] c = new CountedItem[num];
		
		for(int i = 0; i < num; i++)
		{
			String name;
			double unitprice;
			int quantity;
			print("NAME: ");
			name = scanf.nextLine();
			print("Unit Price: ");
			unitprice = scanf.nextDouble();
			print("Quantity: ");
			quantity = scanf.nextInt();
			scanf.nextLine();
			c[i] = new CountedItem(name, unitprice, quantity);
			println(c[i].toString());
			
		}
		scanf.close();
		

	}
	private static void print(Object ob){System.out.print(ob);}
	private static void println(Object ob){System.out.println(ob);}

}
