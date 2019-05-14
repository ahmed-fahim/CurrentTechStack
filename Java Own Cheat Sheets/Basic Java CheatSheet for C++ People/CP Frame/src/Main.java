import java.util.*;
import java.io.*;
import java.math.*;



class Main {
    static Scanner cin;
    static PrintWriter cout;
    static void init_file(){
        try {
            cin=new Scanner(new BufferedReader(new FileReader(new File("inp.txt"))));
            cout=new PrintWriter(new File("outp.txt"));
        } catch (FileNotFoundException ex) {
           
        }
    }
    static void init_std(){
        cin=new Scanner(System.in);
        cout=new PrintWriter(System.out);
    }
    static <T> void resize(ArrayList<T> ob, int sz){
        for(int i=0;i<sz;i++){
            ob.add(null);
        }
    }
    static int On(int n, int k){
        return n|1<<k;
    }
    static long On(long n, long k){
        return n|1L<<k;
    }
    static int Off(int n, int k){
        if(check(n,k) == 1){
            return n-(1<<k);
        }
        else{
            return n;
        }
    }
    static long Off(long n, long k){
        if(check(n,k)==1){
            return n-(1L<<k);
        }
        else{
            return n;
        }
    }
    static int check(int n, int k){
        int res=n & (1<<k);
        return (res == 0) ? 0:1;
    }
    static int check(long n, long k){
        long res=n & (1L<<k);
        return (res == 0) ? 0:1;
    }
    static <T> void resize(ArrayDeque<T> ob, int sz){
        for(int i=0;i<sz;i++){
            ob.addLast(null);
        }      
    }
    public Main(){

        init_std();  

        //init_file();

    }
    public static void main(String[] args){
        new Main();
        cin.close();
        cout.close();
        ///write your code int Main()
        ///C++ map  = JAVA TreeMap
        ///C++ vector = JAVA ArrayList
        ///C++ set = JAVA TreeSet
        ///C++ unorderd_map = JAVA HashMap
        ///C++ bool = JAVA Boolean
        ///C++ deque = JAVA ArrayDequeue
        ///C++ priority_queue = PriorityQueue 
        
    }
}
