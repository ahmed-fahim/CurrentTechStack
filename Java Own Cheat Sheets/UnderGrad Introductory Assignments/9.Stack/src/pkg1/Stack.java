package pkg1;

public class Stack {
	private int[] s;
	private int maxsize,t;
	public Stack(int size) {
		s = new int[size];
		maxsize = size;
		t = -1;
	}
	public void push(int e) {
		if(size()+1 > maxsize)
		{System.out.println("OVERFLOW!");return;}
		s[++t]=e;
	}
	public int pop()
	{
		if(size() == 0) {
			System.out.println("UNDERFLOW!");
			return -997;
		}
		return s[t--];
	}
	public boolean isEmpty() 
	{
		return (t == -1) ? true : false;
	}
	public int top() 
	{
		return s[t];
	}
	public int size() {
		return t+1;
	}
	public void show() {
		for(int i = t; i >= 0; i--)
		{
			System.out.println(s[i]);
		}
		System.out.println();
	}
}
