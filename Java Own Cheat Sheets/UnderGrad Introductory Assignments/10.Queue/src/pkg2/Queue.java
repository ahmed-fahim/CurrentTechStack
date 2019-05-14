package pkg2;

public class Queue {
	private int f,r, maxsize;
	private int[] q;
	public Queue(int size) {
		maxsize = size;
		q = new int[maxsize];
		f = r = 0;
	}
    public void enqueue(int e)
    {
    	if(size()+1 > maxsize)
    	{
    		System.out.println("FULL!!");
    		return;
    	}
        q[r] = e;
        r++;
    }
    public int dequeue()
    {
        if(size() == 0)
        {
        	System.out.println("Empty!!");
            return -997;
        }
        int temp = q[f];
        int i;
        for(i = f; i < r-1; i++)
        {
            q[i] = q[i+1];
        }
        r--;
        return temp;
    }
    public boolean isEmpty()
    {
        return (f == r) ? true : false;
    }
    public int front()
    {
        return q[f];
    }
    public int size()
    {
        return (r-f);
    }
    public void show()
    {
    	for(int i = f; i < r; i++)
    	{
    		System.out.println(q[i]);
    	}
    }
}
