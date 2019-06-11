package stage2.substage3;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import stage1.*;
import stage2.*;
import stage2.substage1.*;
import stage2.substage2.Season;

public class PointsTable {
	public Season data;
	public ArrayList<TeamPerformance> tableEntries;

	/**
	 * DO NOT MODIFY
	 * @return the number of entries in team performance list.
	 */
	public int size() {
		return tableEntries.size();
	}

	/**
	 * DO NOT MODIFY
	 */
	public String toString() {
		String result = data.getSeasonYear()+":\n";
		for(TeamPerformance tp: tableEntries) {
			result+=tp.toString()+"\n";
		}
		return result;
	}

	/**
	 * DO NOT MODIFY
	 * load the season using addMatchEntry
	 * 
	 * IMPORTANT: Complete addMatchEntry method for this constructor
	 * and any other method in this class to work
	 * @param season
	 */
	public PointsTable(Season season) {
		data = season;
		
		tableEntries = new ArrayList<TeamPerformance>();
		for(int i=0; i < season.size(); i++) {
			addMatchEntry(season.getMatch(i));
		}

		//we use built-in sort method to sort teams in desending order
		//uses compareTo(Match) in class Match

		Collections.sort(tableEntries, Collections.reverseOrder());
	}
	
	/**
	 * add a match so that the corresponding team performances are created/updated
	 * sort the table in descending order to maintain sorted order of the table
	 * 
	 * if a team performance entry for the home team already exists, it should be updated
	 * if a team performance entry for the home team already does not exist, it should be added
	 * same goes for the away team
	 * 
	 * @param m: match played
	 */
	public void addMatchEntry(Match m) {
		//to be completed
		
		//TeamPerformance(String name, int played, int won, int drawn, int goalscored, int goalconceded)
		//Match(m.getHomeTeam(), m.getAwayTeam(), m.getHomeGoals(), m.getAwayGoals());
		
		
		
		//I have left the sort method call at the end of the method
		//for your convenience
		Collections.sort(tableEntries, Collections.reverseOrder());
	}

	/**
	 * IMPORTANT! Proceed to this method ONLY AFTER addMatchEntry test passes
	 * @param team
	 * @return true if there is a record for the given team (case insensitive)
	 * in tableEntries, false otherwise.
	 */
	public boolean teamExists(String team) {
		return false; //to be completed
	}

	/**
	 * IMPORTANT! Proceed to this method ONLY AFTER addMatchEntry test passes
	 * @param team
	 * @return true index at which there is a record for the given team 
	 * (case insensitive) in tableEntries, -1 if no record exists.
	 */
	public int getTeamIndex(String team) {
		return -1; //to be completed
	}

	/**
	 * IMPORTANT! Proceed to this method ONLY AFTER addMatchEntry test passes
	 * @param standing
	 * @return team with given standing
	 */
	public String getTeamByStanding(int standing) {
		return null; //to be completed
	}

	/**
	 * IMPORTANT! Proceed to this method ONLY AFTER addMatchEntry test passes
	 * @param team
	 * @return the standing of the passed team.
	 * note that the team at index 0 has standing 1,
	 * team at index 1 has standing 2, and so on.
	 */
	public Integer getStanding(String team) {
		return null; //to be completed
	}
	
	/**
	 * Assume table has at least three teams
	 * The bottom three teams are relegated
	 * @return a list containing the names of the bottom three teams
	 * (in order of appearance in the table from top to bottom)
	 */
	public ArrayList<String> getRelegatedTeams() {
		return null; //to be completed
	}
}
