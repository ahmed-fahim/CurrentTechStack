/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ioWrapper;

import java.util.*;
import java.io.*;

/**
 *
 * @author Fahim
 */
public class IO_Handler {

    private Scanner scanner;
    private PrintWriter printwriter;

    public enum ModeIO {
        writeFile_readFile,
        writeFile_readStd,
        writeStd_readFile,
        writeStd_readStd
    }
    private ModeIO currentMode;
    private String inFileName, outFileName;

    private void init_input(boolean isStd) {
        if (isStd) {
            this.scanner = new Scanner(System.in);
        } else {
            try {
                this.scanner = new Scanner(new BufferedReader(new FileReader(new File(this.inFileName))));
            } catch (FileNotFoundException exc) {
            }
        }
    }

    private void init_output(boolean isStd) {
        if (isStd) {
            this.printwriter = new PrintWriter(System.out);
        } else {
            try {
                this.printwriter = new PrintWriter(new File(this.outFileName));
            } catch (FileNotFoundException exc) {
            }
        }
    }

    private void setConfig() {
        switch (this.currentMode) {
            case writeFile_readFile: {
                this.init_input(false);
                this.init_output(false);
                break;
            }
            case writeFile_readStd: {
                this.init_input(true);
                this.init_output(false);
                break;
            }
            case writeStd_readFile: {
                this.init_input(false);
                this.init_output(true);
                break;
            }
            case writeStd_readStd: {
                this.init_input(true);
                this.init_output(true);
                break;
            }
            default: {
                break;
            }
        }
    }

    public IO_Handler() {
        this.currentMode = ModeIO.writeStd_readStd;
        this.setConfig();
    }

    public IO_Handler(ModeIO configMode) throws IO_ConfigError {
        this.currentMode = configMode;
        switch (configMode) {
            case writeStd_readStd: {
                this.currentMode = configMode;
                break;
            }
            case writeFile_readStd:
            case writeStd_readFile:
            case writeFile_readFile: {
                throw new IO_ConfigError("This Mode Configuration requires more argument");
            }
            default:
                break;
        }
        this.setConfig();
    }

    public IO_Handler(ModeIO configMode, String fileNameArg) throws IO_ConfigError {

        this.currentMode = configMode;

        switch (configMode) {
            case writeFile_readStd: {
                this.inFileName = fileNameArg;
                break;
            }
            case writeStd_readFile: {
                this.outFileName = fileNameArg;
                break;
            }
            case writeFile_readFile: {
                throw new IO_ConfigError("This Mode Configuration requires 1 more fileName Argument");
            }
            case writeStd_readStd: {
                throw new IO_ConfigError("This Mode Configuration does not require any fileName Argument");
            }
            default:
                break;
        }

        this.setConfig();
    }

    public IO_Handler(ModeIO configMode, String inFileNameArg, String outFileNameArg) throws IO_ConfigError {

        this.currentMode = configMode;

        switch (configMode) {
            case writeFile_readFile: {
                this.inFileName = inFileNameArg;
                this.outFileName = outFileNameArg;
                break;
            }
            case writeFile_readStd:
            case writeStd_readFile:
            case writeStd_readStd: {
                throw new IO_ConfigError("This Mode Configuration does not require so many Arguments");
            }
            default:
                break;
        }

        this.setConfig();
    }

    public Scanner inp() {
        return this.scanner;
    }

    public PrintWriter outp() {
        return this.printwriter;
    }
    public void close(){
        this.printwriter.close();
        this.scanner.close();
    }
    @Override
    protected void finalize() throws Throwable { 
        try{
            if(this.printwriter != null){
                this.printwriter.close();
            }
            if(this.scanner != null){
                this.scanner.close();
            }
        }catch (Exception error){}
        super.finalize();
    }

}
