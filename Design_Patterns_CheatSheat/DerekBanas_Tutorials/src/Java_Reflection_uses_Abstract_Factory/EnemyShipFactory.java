package Java_Reflection_uses_Abstract_Factory;
// With an Abstract_Factory Pattern you won't
// just build ships, but also all of the components
// for the ships

// Here is where you define the parts that are required
// if an object wants to be an enemy ship

import Abstract_Factory.ESEngine;
import Abstract_Factory.ESWeapon;

public interface EnemyShipFactory{
	
	ESWeapon addESGun();
	ESEngine addESEngine();
	
}
