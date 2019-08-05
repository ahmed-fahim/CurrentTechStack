package Iterator;

import java.util.ArrayList;
import java.util.Iterator;

class SongsOfThe70s implements SongIterator{
	
	// ArrayList holds SongInfo objects
	
	private ArrayList<SongInfo> bestSongs;
	
	SongsOfThe70s() {
		
		bestSongs = new ArrayList<SongInfo>();
		
		addSong("Imagine", "John Lennon", 1971);
		addSong("American Pie", "Don McLean", 1971);
		addSong("I Will Survive", "Gloria Gaynor", 1979);
		
	}
	
	// Add a SongInfo object to the end of the ArrayList
	
	private void addSong(String songName, String bandName, int yearReleased){
		
		SongInfo songInfo = new SongInfo(songName, bandName, yearReleased);
		
		bestSongs.add(songInfo);
		
	}
	
	
	// Get rid of this
	// Return the ArrayList filled with SongInfo Objects
	
	ArrayList<SongInfo> getBestSongs(){
		
		return bestSongs;
		
	}

	// NEW By adding this method I'll be able to treat all
	// collections the same
	
	public Iterator createIterator() {
		// TODO Auto-generated method stub
		return bestSongs.iterator();
	}
	
}
