package pkg2;
import java.util.*;
public class Employee extends Person{
	private int year;
	private double salary;
	Scanner scanf = new Scanner(System.in);
	public Employee()
	{
		super();
		year = -1;
		salary = -1.0;
	}
	public Employee(String a, double b, int y, String n) {
		super(a,n);
		year = y;
		salary = b;
	}
	public int get_year()
	{
		return year;
	}
	public double get_salary() {
		return salary;
	}
	public void input() 
	{
		String nm,nid;
		print("Name of New Employee: ");
		nm = scanf.nextLine();
		print("Joining year: ");
		year = scanf.nextInt();
		print("Salary: ");
		salary = scanf.nextDouble();
		scanf.nextLine();
		print("National Insurance Number: ");
		nid = scanf.nextLine();
		
		set_per_info(nm, nid);
	}
	
	/*THIS METHOD CHECKS EQUALITY BETWEEN TWO OBJECT'S SALARY AND JOINING YEAR*/
	public int Equals(Employee emp) {
		if(get_salary()==emp.get_salary() && get_year() == emp.get_year())
		{
			return 1;
		}
		else {
			return 0;
		}
	}
	public void show_info()
	{
		println("Name of Employee: "+get_name());
		println("Joining year: "+ year);
		println("Salary: "+salary);
		println("National Insurance Number: " + get_national_id());
		
	}
	private  void print(Object ob){System.out.print(ob);}
	private  void println(Object ob){System.out.println(ob);}

}
