
package Core;
import ioWrapper.IO_ConfigError;
import ioWrapper.IO_Handler;
import java.util.*;
import java.util.logging.Level;
import java.util.logging.Logger;
/**
 *
 * @author Fahim
 */


class SimpleCSV{
    protected IO_Handler io;
    private String sourceName;
    private String targetName;
    private ArrayList<String> sheet;
    private String [][]data;
    public SimpleCSV(String sourceArg, String targetArg){
        this.sourceName = sourceArg;
        this.targetName = targetArg;
        this.sheet = new ArrayList<>();
        try {
            this.io = new IO_Handler(IO_Handler.ModeIO.writeFile_readFile, sourceName, targetName);
        } catch (IO_ConfigError ex) {
            Logger.getLogger(SimpleCSV.class.getName()).log(Level.SEVERE, null, ex);
        }
        this.readCSV();
    }
    private void readCSV(){
        String currentLine;
        int columnSize = 0;
        while(io.inp().hasNext()){
            currentLine = io.inp().nextLine();
            sheet.add(currentLine);
            columnSize = Integer.max(currentLine.split(",").length, columnSize);
        }
        data = new String[sheet.size()][columnSize];
        for(int i = 0; i < sheet.size(); i++){
            data[i] = sheet.get(i).split(",");
        }
    }
    public String getFromCell(int row, int col){
        return data[row][col];
    }
    public int getRowCount(){
        return sheet.size();
    }
    public int getColumnCount(){
        return data[0].length;
    }
}

class CompProgCSV extends SimpleCSV{
    public CompProgCSV(String sourceArg, String targetArg){
        super(sourceArg, targetArg);
        this.generateLink();
        this.io.close();
    }
    private void generateLink(){
        for(int i = 0; i < super.getRowCount(); i++){
            String linkForCurrentRow = "https://vjudge.net/problem#OJId="+
                                        super.getFromCell(i, 0) +
                                        "&probNum=" +  
                                        super.getFromCell(i, 1) + 
                                        "&title=&source=&category=all";
            super.io.outp().println(linkForCurrentRow);
        }
    }
}

public class CsvScrapper {
    public static void main(String[] args){
        CompProgCSV csv = new CompProgCSV("Raw_Problem_List.csv", "proble_links.txt");
   }
}
