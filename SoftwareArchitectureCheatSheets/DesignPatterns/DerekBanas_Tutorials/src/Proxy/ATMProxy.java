package Proxy;// In this situation the proxy both creates and destroys
// an ATMMachine Object

public class ATMProxy implements GetATMData {

	// Allows the user to access getATMState in the 
	// Object ATMMachine
	
	public ATMState getATMData() {
		
		ATMMachine realATMMachine = new ATMMachine();
		
		return realATMMachine.getATMData();
	}

	// Allows the user to access getCashInMachine 
	// in the Object ATMMachine


	public int getCashInMachine() {
		
		ATMMachine realATMMachine = new ATMMachine();
		
		return realATMMachine.getCashInMachine();
		
	}
	
}
