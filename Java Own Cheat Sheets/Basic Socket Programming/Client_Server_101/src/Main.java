import java.util.*;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.ServerSocket;
import java.net.Socket;

class Server1 {  
    public static void Server1(String[] args){  
        try{  
            ServerSocket ss=new ServerSocket(6666);  
            Socket s=ss.accept();//establishes connection   
            DataInputStream dis=new DataInputStream(s.getInputStream());  
            String  str=(String)dis.readUTF();  
            System.out.println("message= "+str);  
            ss.close();  
        }catch(Exception e){System.out.println(e);}  
    }  
}
class Client1 {  
public static void Client1(String[] args) {  
        try{      
        Socket s=new Socket("localhost",6666);  
        DataOutputStream dout=new DataOutputStream(s.getOutputStream());  
        dout.writeUTF("Hello Server");  
        dout.flush();  
        dout.close();  
        s.close();  
        }catch(Exception e){System.out.println(e);}  
    }  
}  
class Chat {
    boolean flag = false;

    public synchronized void Question(String msg) {
        if (flag == true) {
            try {
                wait();
                System.out.println("Boy is typing....");
                try {
    				Thread.sleep(5000);
    			} catch (InterruptedException e) {
    				// TODO Auto-generated catch block
    				e.printStackTrace();
    			}
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println(msg);
        flag = true;
        notify();
    }

    public synchronized void Answer(String msg) {
        if (flag == false) {
            try {
                wait();
                System.out.println("Girl is typing....");
                try {
    				Thread.sleep(5000);
    			} catch (InterruptedException e) {
    				// TODO Auto-generated catch block
    				e.printStackTrace();
    			}
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        System.out.println(msg);
        flag = false;
        notify();
    }
}

class T1 implements Runnable {
    Chat m;
    String[] s1 = { "Hi", "How are you ?", "I am also doing fine!" };

    public T1(Chat m1) {
        this.m = m1;
        new Thread(this, "Question").start();
    }

    public void run() {
        synchronized (m) 
        {
			for (int i = 0; i < s1.length; i++) {
            m.Question(s1[i]);
			}
        }
    }
}

class T2 implements Runnable {
    Chat m;
    String[] s2 = { "Hi", "I am good, what about you?", "Great!" };

    public T2(Chat m2) {
        this.m = m2;
        new Thread(this, "Answer").start();
    }

    public void run() {
        
    	synchronized (m) 
    	{
        	for (int i = 0; i < s2.length; i++)
        	{
                m.Answer(s2[i]);
            }
		}
    }
}
public class Main {
    public static void main(String[] args) {
        Client1 cl = new Client1();
        Server1 sr = new Server1();
        
    }
}