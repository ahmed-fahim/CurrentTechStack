package pkg3;

public class CountedItem extends PurchaseItem {
	private int quantity;
	public CountedItem()
	{
		super();
		quantity = 0;
	}
	public CountedItem(String n, double uprice, int q)
	{
		super(n,uprice);
		quantity = q;
	}
	@Override
	public double getPrice()
	{
		double tm = super.getPrice();
		tm*=(double)quantity;
		return tm;
	}
	
	@Override
	public String toString()
	{
		String tm = super.toString();
		tm+=" "+String.valueOf(quantity)+" units "+String.valueOf(getPrice())+" SR";
		return tm;
	}
	
}
