package Builder;// The director / engineer class creates a Robot using the
// builder interface that is defined (OldRobotBuilder)

class RobotEngineer {
	
	private RobotBuilder robotBuilder;
	
	// OldRobotBuilder specification is sent to the engineer
	
	RobotEngineer(RobotBuilder robotBuilder){
		
		this.robotBuilder = robotBuilder;
		
	}
	
	// Return the Robot made from the OldRobotBuilder spec
	
	Robot getRobot(){
		
		return this.robotBuilder.getRobot();
		
	}
	
	// Execute the methods specific to the RobotBuilder 
	// that implements RobotBuilder (OldRobotBuilder)
	
	void makeRobot() {
		
		this.robotBuilder.buildRobotHead();
		this.robotBuilder.buildRobotTorso();
		this.robotBuilder.buildRobotArms();
		this.robotBuilder.buildRobotLegs();
		
	}
	
}
