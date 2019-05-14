package pkg1;

public class Accounts {
	private double balance;
	private String accholder;
	public Accounts() 
	{
		balance = 0;
		accholder = new String();
	}
	public void Set_Accounts(String s, double initialAmount)
	{
		accholder = s;
		balance = initialAmount;
	}
	public void Withdraw(double amount)
	{
		if(balance >= amount)
		{
			balance-=amount;
		}
		else {
			print("Not Sufficient Balance\n");
		}
	}
	public void Deposit(double amount) {
		balance+=amount;
	}
	public double get_balance() {
		return balance;
	}
	public String get_name() {
		return accholder;
	}
	public void show_account_state()
	{
		println("Account Holder: "+accholder);
		println("Current Balance is " +balance );
	}
	private void print(Object ob) {
		System.out.print(ob);
	}
	private void println(Object ob) {
		
		System.out.println(ob);
	}
	public void Update()
	{
		
	}
}
