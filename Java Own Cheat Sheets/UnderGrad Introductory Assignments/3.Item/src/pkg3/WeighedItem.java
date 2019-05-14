package pkg3;

public class WeighedItem extends PurchaseItem{
	private double weight;
	public WeighedItem()
	{
		super();
		weight = 0.0;
	}
	public WeighedItem(String n, double uprice, double w)
	{
		super(n,uprice);
		weight = w;
	}
	@Override
	public double getPrice()
	{
		double tm = super.getPrice();
		tm*=weight;
		return tm;
	}
	
	@Override
	public String toString()
	{
		String tm = super.toString();
		tm+=" "+String.valueOf(weight)+"kg "+String.valueOf(getPrice())+" SR";
		return tm;
	}
	
}
