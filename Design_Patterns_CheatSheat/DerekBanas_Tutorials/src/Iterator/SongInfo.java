package Iterator;
// Will hold all of the info needed for each song

// I told all users to:
// 1. create a function named addSong() for adding song, band and release
// 2. create a function named getBestSongs() that will return the collection
//    of songs

class SongInfo{
	
	private String songName;
	private String bandName;
	private int yearReleased;
	
	SongInfo(String newSongName, String newBandName, int newYearReleased){
		
		songName = newSongName;
		bandName = newBandName;
		yearReleased = newYearReleased;
		
	}
	
	String getSongName(){ return songName; }
	String getBandName(){ return bandName; }
	int getYearReleased(){ return yearReleased; }
	
}
