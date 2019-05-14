package pkg2;
import java.util.*;


public class Maincode {

	public static void main(String[] args) {
		Scanner scanf = new Scanner(System.in);
		
		print("Number of Employees: ");
		int num = scanf.nextInt();
		scanf.nextLine();
		Employee[] e = new Employee[num+1];
		
		/*FIRST IS SHOWN DATA ASSIGING USING CONSTRUCTOR OVERLOADING*/
		for(int i = 1; i < num; i++)
		{
			String nm,nid;
			double sal;
			int yr;
			print("Name of New Employee: ");
			nm = scanf.nextLine();
			print("Joining year: ");
			yr = scanf.nextInt();
			print("Salary: ");
			sal = scanf.nextDouble();
			scanf.nextLine();
			print("National Insurance Number: ");
			nid = scanf.nextLine();
			e[i] = new Employee(nm, sal, yr, nid);
		}
		
		/*NEXT HERE WE SEE TAKING INPUTS USING METHODS OF THE CLASS*/
		e[num] = new Employee();
		e[num].input();
		
		/******************/
		
		/*Testing Various methods of the class*/
		while(true)
		{
			println("");
			println("Select an option");
			println("1. View Info of an Employee");
			println("2. Check Equality between 2 entry");
			println("3. Exit");
			int dec = scanf.nextInt();
			scanf.nextLine();
			String a,b;
			int indx1;
			if(dec == 1)
			{
				print("Name of the required Employee: ");
				a = scanf.nextLine();
				boolean flag = false;
				for(int i = 1; i <= num; i++)
				{
					if(e[i].get_name().equals(a))
					{
						flag = true;
						e[i].show_info();
						break;
					}
				}
				if(flag == false) println("Employee "+a+" has not been found in System");
			}
			else if(dec == 2)
			{
				int val = -1;
				indx1 = -1;
				print("Insurance Number of employee 1: ");
				a = scanf.nextLine();
				print("Insurance Number of employee 2: ");
				b = scanf.nextLine();
				boolean flag = false;
				for(int i = 1; i <= num; i++)
				{
					if(e[i].get_national_id().equals(a))
					{
						flag = true;
						indx1 = i;
						break;
					}
				}
				if(flag == false) 
				{
					println("First employee was not found in system");
					continue;
				}
				flag = false;
				for(int i = 1; i <= num; i++)
				{
					if(e[i].get_national_id().equals(b) && i!=indx1)
					{
						flag = true;
						val = e[indx1].Equals(e[i]);
						break;
					}
				}
				
				if(flag == false) 
				{
					println("Second employee was not found in system");
					continue;
				}
				if(val == 1){
					println("Both of the employees have same salary and joining year!!");
				}
				else {
					println("The employees have different salary or/and joining year!!");
				}
			}
			else if(dec == 3)break;
		}
		scanf.close();
	}
	private static void print(Object ob){System.out.print(ob);}
	private static void println(Object ob){System.out.println(ob);}


}
