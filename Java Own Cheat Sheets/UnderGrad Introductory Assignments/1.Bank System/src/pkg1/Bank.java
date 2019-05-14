package pkg1;

import java.util.*;

public class Bank {
	static int n_gen=0;
	static Scanner scanf = new Scanner(System.in);
	final static int maxacc = 101;
	static double interest_rate = 0, overdraft_limit = 0;
	static Accounts[] gen = new Accounts[maxacc];

	public static void main(String[] args)
	{
		println("\t\t\"Welcome to the Banking System\"\n");
		print("****Please input the desired interest rate for all the Savings Accounts\n\trate = ");
		interest_rate = scanf.nextDouble();
		print("\n****Please input the desired Overdraft limit for all the Current Accounts\n\tOverdraft limit = ");
		overdraft_limit = scanf.nextDouble();
		
		while(true)
		{
			println("\nCurrently The Bank has: "+n_gen+" Accounts");
			println("\nWhat would you want to do?");
			println("1.Open a new Account\t2.Close an existing Account");
			println("3.Update Bank\t4.View info of an account");
			println("5.Withdraw from an Account\t6.Deposit in an Account");
			println("7.EXIT\n");
			int decision = 0;
			decision = scanf.nextInt();
			if(decision == 1)
			{
				Open();
			}
			else if(decision == 2)
			{
				Close();
			}
			else if(decision == 3)
			{
				Update_Bank();
			}
			else if(decision == 4)
			{
				View_info();
			}
			else if(decision == 5)
			{
				withdraw();
			}
			else if(decision == 6)
			{
				deposit();
			}
			else if(decision == 7) break;
		}
		
	}
	private static void print(Object ob) {
		System.out.print(ob);
	}
	private static void println(Object ob) {
		
		System.out.println(ob);
	}
	private static void Open() {
		if(n_gen+1 >= maxacc)
		{
			println("Sorry, Bank has already reached Maximum number of Accounts");
			return;
		}
		n_gen++;
		int decision = 0;
		println("\t1.General Account");
		println("\t2.Savings Account");
		println("\t3.Current Account");
		decision = scanf.nextInt();
		scanf.nextLine();
		if(decision == 1)
		{	
				gen[n_gen] = new Accounts();
		}
		else if(decision == 2)
		{
			gen[n_gen] = new SavingsAccount(interest_rate);
		}
		else if(decision == 3)
		{
			gen[n_gen] = new CurrentAccount(overdraft_limit);
		}
		
		print("Account owners name: ");
		String nm = scanf.nextLine();
		print("Balance to be deposited initially: ");
		double bln = scanf.nextDouble();
		gen[n_gen].Set_Accounts(nm, bln);

	}
	private static void Close() {
		if(n_gen == 0)
		{
			println("Sorry, System has no Account");
			return;
		}
		scanf.nextLine();
		print("Please enter the name of the account holder\nName: ");
		String s = scanf.nextLine();
		
		int flag = 0;
		for(int count = 1; count <= n_gen; count++)
		{
			if(gen[count].get_name().equals(s))
			{
				flag = 1;
				for(int j = count; j < n_gen; j++)
				{
					gen[j] = gen[j+1];
					gen[j].Set_Accounts(gen[j+1].get_name(), gen[j+1].get_balance());
				}
				n_gen--;
				println("Closed");
				break;
			}
		}
		if(flag == 0) println("Account for Owner "+s+" is not found in System");

	}
	private static void Update_Bank()
	{
		if(n_gen == 0)
		{
			println("Sorry, System has no Account");
			return;
		}
		for(int i = 1; i <= n_gen; i++)
		{
			gen[i].Update();
		}
	}
	private static void View_info() {
		if(n_gen == 0)
		{
			println("Sorry, System has no Account");
			return;
		}
		scanf.nextLine();
		print("Account holder Name: ");
		String s = scanf.nextLine();
		int flag = 0;
		for(int i = 1; i <= n_gen; i++)
		{
			if(gen[i].get_name().equals(s))
			{
				flag = 1;
				gen[i].show_account_state();
				break;
			}
		}
		if(flag == 0)println("Account for Owner "+s+" is not found in System");
	}
	private static void withdraw() {
		if(n_gen == 0)
		{
			println("Sorry, System has no Account");
			return;
		}
		scanf.nextLine();
		print("Account holder Name: ");
		String s = scanf.nextLine();
		int flag = 0;
		for(int i = 1; i <= n_gen; i++)
		{
			if(gen[i].get_name().equals(s))
			{
				flag = 1;
				print("Withdraw Amount: ");
				double temp = scanf.nextDouble();
				gen[i].Withdraw(temp);
				break;
			}
		}
		if(flag == 0)println("Account for Owner "+s+" is not found in System");
		
	}
	private static void deposit() {
		if(n_gen == 0)
		{
			println("Sorry, System has no Account");
			return;
		}
		scanf.nextLine();
		print("Account holder Name: ");
		String s = scanf.nextLine();
		int flag = 0;
		for(int i = 1; i <= n_gen; i++)
		{
			if(gen[i].get_name().equals(s))
			{
				flag = 1;
				print("Deposit Amount: ");
				double temp = scanf.nextDouble();
				gen[i].Deposit(temp);
				break;
			}
		}
		if(flag == 0)println("Account for Owner "+s+" is not found in System");
		
	}

}
