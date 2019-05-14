package pkg2;

public class Person {
	private String name, nationalInsurance;
	public Person()
	{
		name = null;
		nationalInsurance = null;
	}
	public Person(String a, String b) {
		name = a;
		nationalInsurance = b;
	}
	public String get_name()
	{
		return name;
	}
	public String get_national_id() {
		return nationalInsurance;
	}
	public void set_per_info(String a, String b)
	{
		name = a;
		nationalInsurance = b;
	}
}
