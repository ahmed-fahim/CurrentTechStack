package Adapter;
// This is the Adaptee. The Adapter sends method calls
// to objects that use the EnemyAttacker interface
// to the right methods defined in EnemyRobot

import java.util.Random;

class EnemyRobot{

	private Random generator = new Random();
	
	void smashWithHands() {
		
		int attackDamage = generator.nextInt(10) + 1;
		
		System.out.println("Enemy Robot Causes " + attackDamage + " Damage With Its Hands");
		
	}

	void walkForward() {
		
		int movement = generator.nextInt(5) + 1;
		
		System.out.println("Enemy Robot Walks Forward " + movement + " spaces");
		
	}

	void reactToHuman(String driverName) {
		
		System.out.println("Enemy Robot Tramps on " + driverName);
		
	}
	
	
	
}

