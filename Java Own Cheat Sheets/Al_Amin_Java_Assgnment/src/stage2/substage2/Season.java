package stage2.substage2;

import stage1.*;

import java.io.File;
import java.io.FileNotFoundException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Scanner;

public class Season {
	private ArrayList<Match> matches;
	private int year;

	/** 
	 * DO NOT MODIFY
	 * reads the data for a soccer season from the filename provided.
	 * 
	 * @param filename
	 * @throws FileNotFoundException
	 */
	public Season(String filename) throws FileNotFoundException {
		year = Integer.parseInt(filename.substring(0, 2));
		matches = new ArrayList<Match>();
		File source = new File("data/"+filename);
		Scanner scanner = new Scanner(source);
		scanner.nextLine(); //ignore header
		while(scanner.hasNextLine()) {
			String line = scanner.nextLine();
			String[] tokens = line.split(",");
			Match m = new Match(tokens[1], tokens[2], Integer.parseInt(tokens[3]), Integer.parseInt(tokens[4]));
			matches.add(m);
		}
		scanner.close();
	}

	/**
	 * DO NOT MODIFY
	 * @return
	 */
	public int size() {
		return matches.size();
	}

	/**
	 * 
	 * @param idx
	 * @return the match at given index (null if index invalid)
	 */
	public Match getMatch(int idx) {
		if(idx < 0 || idx >= size())
			return null;
		return matches.get(idx);
	}

	/**
	 * 
	 * @param idx
	 * @return name of the winner of the match at passed index
	 * return "We're all winners!" if the match at passed index ended in a  draw.
	 * return null if index is invalid
	 */
	public String getWinner(int idx) {
		if(idx < 0 || idx >= size())
			return null;
		if(matches.get(idx).winner() == 1)
			return matches.get(idx).getHomeTeam();
		if(matches.get(idx).winner() == -1)
			return matches.get(idx).getAwayTeam();
		return "We're all winners!";
	}

	/**
	 * 
	 * @param team
	 * @return number of games played at home by the team passed
	 */
	public int getHomeGameCount(String team) {
		int count = 0;
		for(Match m: matches) {
			if(m.getHomeTeam().equals(team))
				count++;
		}
		return count;
	}

	/**
	 * 
	 * @param team
	 * @return number of games won at home by the team passed
	 */
	public int getHomeWinCount(String team) {
		int count = 0;
		for(Match m: matches) {
			if(m.getHomeTeam().equals(team) && m.winner() == 1)
				count++;
		}
		return count;
	}

	/**
	 * 
	 * @param team
	 * @return number of away games played by the team passed
	 */
	public int getAwayGameCount(String team) {
		int count = 0;
		for(Match m: matches) {
			if(m.getAwayTeam().equals(team))
				count++;
		}
		return count;
	}

	/**
	 * 
	 * @param team
	 * @return number of away games won by the team passed
	 */
	public int getAwayWinCount(String team) {
		int count = 0;
		for(Match m: matches) {
			if(m.getAwayTeam().equals(team) && m.winner() == -1)
				count++;
		}
		return count;
	}

	/**
	 * 
	 * @param team: assume team exists
	 * @return home game winning percent of the passed team
	 */
	public double getHomeGameWinPercent(String team) {
		return getHomeWinCount(team)*100.0/getHomeGameCount(team);
	}

	/**
	 * 
	 * @param team: assume team exists
	 * @return away game winning percent of the passed team
	 */
	public double getAwayGameWinPercent(String team) {
		return getAwayWinCount(team)*100.0/getAwayGameCount(team);
	}

	/**
	 * 
	 * @param team
	 * @return total games won by team passed
	 */
	public int getWinCount(String team) {
		return getHomeWinCount(team) + getAwayWinCount(team);
	}

	/**
	 * 
	 * @return a list of all the matches that resulted in a draw
	 */
	public ArrayList<Match> getMatchesDrawn() {
		ArrayList<Match> result = new ArrayList<Match>();
		for(Match m: matches) {
			if(m.goalDifference() == 0) {
				result.add(m);
			}
		}
		return result;
	}

	/**
	 * HD question
	 * 
	 * @return an arraylist containing the home and away matches 
	 * for each pair of opponents (say the names X and Y are used to
	 * iterate over the teams)
	 * that had the biggest discrepancies between playing at
	 * X's home and then at Y's home 
	 * 
	 * EXPLANATION:
	 * 
	 * Every team plays every other team twice - 
	 * once at home and once away (at the other team's home).
	 * 
	 * We would like to see which pair of teams performed extremely differently
	 * when at home and when away.
	 * 
	 * It is possible a team does BRILLIANTLY at home again a particular opponent 
	 * and ATROCIOUSLY when away (at that opponent's home).
	 * 
	 * It is also possible, although statistically unlikely (no cases in the last decade)
	 * that a team does ATROCIOUSLY at home again a particular opponent 
	 * and BRILLIANTLY when away (at that opponent's home).
	 * 
	 * We would like to return an arraylist containing these matches that have 
	 * the biggest discrepancy while playing at home and while playing away for 
	 * each pair of opponents.
	 * 
	 * Consider the following hypothetical match schedule:
	 * 
	 * sunderland (h) 0 - 1 man city (a)
	 * chelsea (h) 1 - 4 arsenal (a)
	 * stoke (h) 2 - 2 crystal palace (a)
	 * man united (h) 4 - 0 burnley (a)
	 * man city (h) 3 - 1 sunderland (a)
	 * crystal palace (h) 4 - 1 stoke (a)
	 * burnley (h) 4 - 0 man united (a)
	 * arsenal (h) 0 - 5 chelsea (a)
	 * 
	 * If you highlight the games between chelsea and arsenal,
	 * you'll see that arsenal got 3 more goals over chelsea when arsenal was playing away 
	 * and chelsea score 5 more goals over arsenal when chelsea was playing away.
	 * This is a swing of 8 goals in chelsea's favour.
	 * 
	 * Similarly, there is an 8-goal swing in burnley's favour against man united.
	 * 
	 * The order of items in the list MUST be:
	 * [item 0: 1st match that has biggest swing on the return fixture, 
	 *  item 1: return fixture for item 1,
	 *  item 2: 2nd match that has biggest swing on the return fixture 
	 *  		(equaling swing between items 0 and 1),
	 *  item 3: return fixture for item 2,
	 *  ...]
	 *  
	 * So, in this case, the list that should be returned is:
	 * [chelsea 1 - 4 arsenal, 
	 * arsenal 0 - 5 chelsea, 
	 * man united 4 - 0 burnley, 
	 * burnley 4 - 0 man united]
	 */
	public ArrayList<Match> getBiggestSwing() {
		int maxGoalDiff = 0;
		for(int i=0; i < matches.size(); i++) {
			String homeTeam1 = matches.get(i).getHomeTeam();
			String awayTeam1 = matches.get(i).getAwayTeam();
			int goalDiff1 = matches.get(i).goalDifference();
			for(int k=0; k < matches.size(); k++) {
				String homeTeam2 = matches.get(k).getHomeTeam();
				String awayTeam2 = matches.get(k).getAwayTeam();
				int goalDiff2 = matches.get(k).goalDifference();
				if(homeTeam1.equals(awayTeam2) && homeTeam2.equals(awayTeam1)) {
					if(Math.abs(goalDiff1+goalDiff2) > maxGoalDiff) {
						maxGoalDiff = Math.abs(goalDiff1+goalDiff2);
					}
					break;
				}
			}
		}
		
		ArrayList<Match> result = new ArrayList<Match>();
		for(int i=0; i < matches.size(); i++) {
			String homeTeam1 = matches.get(i).getHomeTeam();
			String awayTeam1 = matches.get(i).getAwayTeam();
			int goalDiff1 = matches.get(i).goalDifference();
			for(int k=0; k < matches.size(); k++) {
				String homeTeam2 = matches.get(k).getHomeTeam();
				String awayTeam2 = matches.get(k).getAwayTeam();
				int goalDiff2 = matches.get(k).goalDifference();
				if(homeTeam1.equals(awayTeam2) && homeTeam2.equals(awayTeam1)) {
					if(Math.abs(goalDiff1+goalDiff2) == maxGoalDiff) {
						if(result.indexOf(matches.get(i)) == -1) {
							result.add(matches.get(i));
							result.add(matches.get(k));
						}
					}
					break;
				}
			}
		}
		return result;
	}

	/**
	 * DO NOT MODIFY
	 * @return season in "Season: YY/YY" format. For example "Season: 13/14"
	 */
	public String getSeasonYear() {
		DecimalFormat df = new DecimalFormat("00");
		return "Season "+df.format(year)+"/"+df.format(year+1);
	}

	/**
	 * DO NOT MODIFY
	 */
	public String toString() {
		String result = getSeasonYear()+":\n";
		for(Match m: matches) {
			result+=m.toString()+"\n";
		}
		return result;
	}
}