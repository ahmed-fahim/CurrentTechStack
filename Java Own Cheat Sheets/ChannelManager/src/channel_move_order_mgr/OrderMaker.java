/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package channel_move_order_mgr;
import ioWrapper.IO_ConfigError;
import ioWrapper.IO_Handler;
import java.util.ArrayList;
import java.util.TreeMap;
import java.util.logging.Level;
import java.util.logging.Logger;
/**
 *
 * @author Fahim
 */
public class OrderMaker {
    private IO_Handler io;
    private TreeMap<String, ArrayList<Integer> > mp;
    private static final String[] ORDER= {"IB", "B", "S", "C", "EM", "ED"};
    public static void main(String[] args){
        OrderMaker ordMaker = new OrderMaker();
    }
    public OrderMaker(){
        try {
            io = new IO_Handler(IO_Handler.ModeIO.writeFile_readFile, "defaultChannel", "Move_Order");
        } catch (IO_ConfigError ex) {
            Logger.getLogger(OrderMaker.class.getName()).log(Level.SEVERE, null, ex);
        }
        mp = new TreeMap<>();
        fillMap();
        getOrder();
        io.close();
    }
    private void fillMap(){
        while(io.inp().hasNextLine()){
            String[] literals = io.inp().nextLine().split(" ");
            String key = literals[1];
            Integer value = Integer.parseInt(literals[0]);
            
            if(mp.containsKey(key)){
                mp.get(key).add(value);
            }
            else{
                ArrayList<Integer> list =  new ArrayList<>();
                list.add(value);
                mp.put(key, list);
            }
        }
    }
    private void shiftChannels(int index, int lo, int hi){
        for(int i = index; i < ORDER.length; i++){
            String key = ORDER[i];
            for(int j = 0; j < mp.get(key).size(); j++){
                int value = mp.get(key).get(j);
                if(value >= lo && value < hi){
                    value++;
                    mp.get(key).set(j, value);
                }
            }
        }
    }
    private void getOrder(){
        int len = ORDER.length;
        int nextPosition = 1;
        for(int i = 0; i < len; i++){
            String key = ORDER[i];
            ArrayList<Integer> currentList = mp.get(key);
            for(int j = 0; j < currentList.size(); j++){
                io.outp().println("\""+key+"\" :: Move Channel " + currentList.get(j) + " to channel " + nextPosition);
                int lo = nextPosition;
                int hi = currentList.get(j);
                shiftChannels(i+1, lo, hi);
                mp.get(key).set(j, nextPosition);
                nextPosition++;
            }
        }
    }
}
