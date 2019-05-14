package pkg1;
import java.util.*;
public class Maincode {

	public static void main(String[] args) {
		Scanner scanf = new Scanner(System.in);
		print("Maximum Size of Stack: ");
		int size = scanf.nextInt();
		
		Stack a = new Stack(size);
		while(true)
		{
			int dec = 0;
			println("\n1.push()");
			println("2.pop()");
			println("3.top()");
			println("4.isEmpty()");
			println("5.size()");
			println("6.show()");
			println("0.exit()");
			
			dec = scanf.nextInt();
			println("");
			
			if(dec == 1)
			{
				print("Element: ");
				int temp = scanf.nextInt();
				a.push(temp);
			}
			else if(dec == 2)
			{
				int temp = a.pop();
				if(temp != -997) println("popped " + temp);
			}
			else if(dec == 3)
			{
				println("top " + a.top());
			}
			else if(dec == 4)
			{
				println(a.isEmpty());
			}
			else if(dec == 5)
			{
				println("size " + a.size());
			}
			else if(dec == 6)
			{
				a.show();
			}
			else if(dec == 0)
			{
				break;
			}
		}
		scanf.close();
		

	}
	private static void print(Object ob) {
		System.out.print(ob);
	}
	private static void println(Object ob) {
		System.out.println(ob);
	}
	

}
