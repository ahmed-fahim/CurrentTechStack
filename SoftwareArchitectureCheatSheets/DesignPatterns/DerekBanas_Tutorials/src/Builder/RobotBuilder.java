package Builder;// Defines the methods needed for creating parts
// for the robot

interface RobotBuilder {
	
	void buildRobotHead();
	
	void buildRobotTorso();
	
	void buildRobotArms();
	
	void buildRobotLegs();
	
	Robot getRobot();
	
}
