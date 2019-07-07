package Composite;

class DiscJockey{
	
	private SongComponent songList;
	
	// newSongList contains every Song, SongGroup,
	// and any Songs saved in SongGroups
	
	DiscJockey(SongComponent newSongList){
		
		songList = newSongList;
		
	}
	
	// Calls the displaySongInfo() on every Song
	// or SongGroup stored in songList
	
	void getSongList(){
		
		songList.displaySongInfo();
		
	}
	
}
