package Composite;

import java.util.ArrayList;

class SongGroup extends SongComponent {
	
	// Contains any Songs or SongGroups that are added
	// to this ArrayList
	
	private ArrayList<SongComponent> songComponents = new ArrayList<>();
	
	private String groupName;
	private String groupDescription;
	
	SongGroup(String newGroupName, String newGroupDescription){
		
		groupName = newGroupName;
		groupDescription = newGroupDescription;
		
	}
	
	private String getGroupName() { return groupName; }
	private String getGroupDescription() { return groupDescription; }
	
	public void add(SongComponent newSongComponent) {
		
		songComponents.add(newSongComponent);
		
	}
	
	public void remove(SongComponent newSongComponent) {
		
		songComponents.remove(newSongComponent);
		
	}
	
	public SongComponent getComponent(int componentIndex) {
		
		return songComponents.get(componentIndex);
		
	}
	
	public void displaySongInfo(){
		
		System.out.println(getGroupName() + " " +
				getGroupDescription() + "\n");
		
		// Cycles through and prints any Songs or SongGroups added
		// to this SongGroups ArrayList songComponents

		songComponents.forEach(SongComponent::displaySongInfo);
		
	}
}
