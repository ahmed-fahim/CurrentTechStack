package Decorator;
// Has a "Has a" relationship with Pizza. This is an
// Aggregation Relationship

abstract class ToppingDecorator implements Pizza {

	Pizza tempPizza;
	
	// Assigns the type instance to this attribute
	// of a Pizza
	
	// All decorators can dynamically customize the Pizza
	// instance PlainPizza because of this
	
	ToppingDecorator(Pizza newPizza){
		
		tempPizza = newPizza;
		
	}
	
	public String getDescription() {
		
		return tempPizza.getDescription();
		
	}

	public double getCost() {
		
		return tempPizza.getCost();
		
	}
	
}
