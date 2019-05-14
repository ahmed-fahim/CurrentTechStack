package pkg1;

public class CurrentAccount extends Accounts{
	private double overdraftlimit;
	private double overdraft;
	
	public CurrentAccount(double ovrdrft) {
		super();
		overdraftlimit = ovrdrft;
		overdraft = 0.0;
	}

	@Override
	public void Update()
	{
		if(overdraft > 0)
		{
			System.out.println("Owner "+get_name()+", your account is in OverDraft");
		}
	}
	
	@Override
	public void Withdraw(double amount)
	{
		if(get_balance() >= amount)
		{
			Deposit(-amount);
		}
		else if(overdraftlimit-overdraft >= amount-get_balance())
		{
			double temp = amount-get_balance();
			Deposit(-get_balance());
			overdraft+=temp;
		}
		else {
			System.out.println("Sorry, Overdraft limit Reached");
		}
	}
	@Override
	public void Deposit(double amount) {
		double temp = get_balance();
		if(overdraft > 0)
		{
			overdraft-=amount;
			if(overdraft< 0)
			{
				temp-=overdraft;
				overdraft = 0;
				Set_Accounts(get_name(), temp);
			}
		}
		else {
			Set_Accounts(get_name(), temp+amount);
		}
	} 
}
