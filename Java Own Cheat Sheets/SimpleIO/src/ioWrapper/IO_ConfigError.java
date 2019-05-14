/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ioWrapper;

/**
 * Java Classes are package private. Means any class can access all other
 * classes written under the same package.
 *
 * @author Fahim
 */
public class IO_ConfigError extends Exception {

    private final String cause;

    public IO_ConfigError() {
        super();
        this.cause = "Mismatch in IO_Wrapper Mode and provided operands";
    }

    public IO_ConfigError(String causeArg) {
        super();
        this.cause = causeArg;
    }

    @Override
    public String toString() {
        return this.cause;
    }
}
