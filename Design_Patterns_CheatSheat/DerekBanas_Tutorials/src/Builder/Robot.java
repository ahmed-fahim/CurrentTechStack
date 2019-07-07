package Builder;// The concrete Robot class based on the RobotPlan interface

class Robot implements RobotPlan{

	private String robotHead;
	private String robotTorso;
	private String robotArms;
	private String robotLegs;
	
	public void setRobotHead(String head) {
		
		robotHead = head;
		
	}
	
	String getRobotHead(){ return robotHead; }

	
	public void setRobotTorso(String torso) {
		
		robotTorso = torso;
		
	}
	
	String getRobotTorso(){ return robotTorso; }

	
	public void setRobotArms(String arms) {
		
		robotArms = arms;
		
	}
	
	String getRobotArms(){ return robotArms; }

	
	public void setRobotLegs(String legs) {
		
		robotLegs = legs;
		
	}
	
	String getRobotLegs(){ return robotLegs; }
	
	
	
}
