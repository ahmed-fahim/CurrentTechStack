package pkg3;

public class PurchaseItem {
	private String name;
	private double unitprice;
	public PurchaseItem()
	{
		name = "no item";
		unitprice = 0.0;
	}
	public PurchaseItem(String a, double p)
	{
		name = a;
		unitprice = p;
	}
	public double getPrice()
	{
		return unitprice;
	}
	public String toString() {
		String s = name;
		s+=" @"+String.valueOf(unitprice);
		return s;
	}
}
