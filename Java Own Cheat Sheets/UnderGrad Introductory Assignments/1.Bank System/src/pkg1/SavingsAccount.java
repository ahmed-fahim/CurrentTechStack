package pkg1;

public class SavingsAccount extends Accounts{
	double interest;
	
	public SavingsAccount(double a) {
		super();
		interest = a;
	}
	public void addInterest() {
		double temp = get_balance();
		temp*=interest;
		temp/=100.00;
		Deposit(temp);
	}
	@Override
	public void Update()
	{
		addInterest();
	}
}
