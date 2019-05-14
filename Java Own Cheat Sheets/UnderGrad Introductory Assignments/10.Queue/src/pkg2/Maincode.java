package pkg2;
import java.util.*;

public class Maincode {

	public static void main(String[] args) {
		Scanner scanf = new Scanner(System.in);
		print("Maximum Size of Queue: ");
		int size = scanf.nextInt();
		
		Queue a = new Queue(size);
		while(true)
		{
			int dec = 0;
			println("\n1.enqueue()");
			println("2.dequeue()");
			println("3.front()");
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
				a.enqueue(temp);;
			}
			else if(dec == 2)
			{
				int temp = a.dequeue();
				if(temp != -997) println("dequeued " + temp);
			}
			else if(dec == 3)
			{
				println("front " + a.front());
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
