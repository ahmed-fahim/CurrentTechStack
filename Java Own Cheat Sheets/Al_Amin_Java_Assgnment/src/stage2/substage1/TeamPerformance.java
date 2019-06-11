/**
 * DO NOT MODIFY
 */
package stage2.substage1;

import java.text.DecimalFormat;

import stage1.*;
import doNotModify.*;

public class TeamPerformance implements Comparable<TeamPerformance> {
	private String name;
	private int gamesPlayed, gamesWon, gamesDrawn;
	private int goalsScored, goalsConceded;

	public String getName() {
		return name;
	}

	public int getGamesPlayed() {
		return gamesPlayed;
	}

	public int getGamesWon() {
		return gamesWon;
	}

	public int getGamesDrawn() {
		return gamesDrawn;
	}

	public int getGoalsScored() {
		return goalsScored;
	}

	public int getGoalsConceded() {
		return goalsConceded;
	}

	/*
	 * setters are private since we don't want
	 * clients to modify these values.
	 * these setters are called when the 
	 * object is created or when a new match 
	 * record is added using the addMatchRecord method
	 */

	private void setName(String name) {
		this.name = name;
	}

	/**
	 * @param played
	 * assign, to instance variable gamesPlayed, the higher of 0 and played
	 */
	private void setGamesPlayed(int played) {
		gamesPlayed = Math.max(0, played);
	}

	/**
	 * assumption: gamesWon set correctly
	 * @param won
	 * assign, to the instance variable gamesWon, a value based on parameter.
	 * if won > gamesPlayed, gamesWon should becomes gamesPlayed
	 * if won < 0, gamesWon should becomes 0
	 * in all other cases, gamesWon should be assigned the value won
	 */
	private void setGamesWon(int won) {
		this.gamesWon = Math.max(0, Math.min(won, gamesPlayed));
	}

	/**
	 * assumption: gamesWon AND gamesPlayed set correctly
	 * @param drawn
	 * assign, to the instance variable gamesDrawn, a value based on parameter.
	 * if drawn > gamesPlayed - gamesWon, gamesDrawn should becomes gamesPlayed - gamesWon
	 * if drawn < 0, gamesDrawn should becomes 0
	 * in all other cases, gamesDrawn should be assigned the value drawn
	 */
	private void setGamesDrawn(int drawn) {
		this.gamesDrawn = Math.max(0, Math.min(drawn, gamesPlayed - gamesWon));
	}

	/**
	 * assumption: gamesPlayed, gamesWon AND gamesDrawn set correctly.
	 * @return number of games lost
	 */
	public int getGamesLost() {
		return gamesPlayed-gamesWon-gamesDrawn;
	}

	/**
	 * @param gs
	 * assign, to instance variable goalsScored, the higher of 0 and gs
	 * UNLESS... gamesPlayed is 0. in that case, goalsScored should be 0.
	 * because if you haven't played a game, you can't score.
	 * 
	 * I would have liked to include another scenario where you check if 
	 * the team has won a game, in which case, goalsScored CANNOT be zero.
	 * However, a bit too much for this assignment, I figured.
	 */
	private void setGoalsScored(int gs) {
		if(gamesPlayed == 0)
			goalsScored = 0;
		else
			goalsScored = Math.max(0, gs);
	}

	/**
	 * @param gc
	 * assign, to instance variable goalsConceded, the higher of 0 and gc.
	 * UNLESS... gamesPlayed is 0. in that case, goalsConceded should be 0.
	 * because you cannot concede a goal if you haven't played a game 
	 * (no matter how bad you are :D).
	 */
	private void setGoalsConceded(int gc) {
		if(gamesPlayed == 0)
			goalsScored = 0;
		else
			goalsConceded = Math.max(0, gc);
	}

	/**
	 * DO NOT MODIFY!!! 
	 * Complete the setters correctly and the test for the constructor will pass
	 * 
	 * @param name
	 * @param played
	 * @param won
	 * @param drawn
	 * @param gs
	 * @param gc
	 * 
	 * using the setters, set instance variables based on parameters
	 */
	public TeamPerformance(String name, int played, int won, int drawn, int gs, int gc) {
		setName(name);
		setGamesPlayed(played);
		setGamesWon(won);
		setGamesDrawn(drawn);
		setGoalsScored(gs);
		setGoalsConceded(gc);
	}

	/**
	 * When the first match is added for a team, we don't need to pass
	 * 1 for gamesPlayed and a value for gamesWon. We can calculate that 
	 * using goalsScored and goalsConceded.
	 * 
	 * populate TeamPerformance using parameters passed.
	 * set gamesWon and gamesDrawn based on goals scored and goals conceded.
	 * if goalsScored > goalsConceded -> think
	 * if goalsScored == goalsConceded -> think
	 * 
	 * @param name
	 * @param gs: goals scored
	 * @param gc: goals conceded
	 */
	public TeamPerformance(String name, int gs, int gc) {
		setName(name);
		setGamesPlayed(1);
		if(gs > gc)
			setGamesWon(1);
		if(gs == gc)
			setGamesDrawn(1);
		setGoalsScored(gs);
		setGoalsConceded(gc);
	}

	/**
	 * DO NOT MODIFY
	 */
	public String toString() {
		return PrettyPrinterService.padRight(name, 15)+"Games played: "+gamesPlayed+". Games won: "+gamesWon+". Games drawn: "+gamesDrawn+". Games lost: "+getGamesLost()+". Points: "+PrettyPrinterService.padLeft(((3*gamesWon + gamesDrawn)+""), 3)+". Goal difference: "+PrettyPrinterService.padLeft((((goalsScored - goalsConceded))+""), 3);

	}

	/**
	 * DO NOT MODIFY
	 * @return points based on the formula that every win gets you 
	 * 3 points which every draw gets you 1 point
	 */
	public int getPoints() {
		// TODO Auto-generated method stub
		return 3*gamesWon + gamesDrawn;
	}

	/**
	 * DO NOT MODIFY
	 * @return the goal difference (goals scored minus goals conceded)
	 */
	public int getGoalDifference() {
		return this.getGoalsScored() - this.getGoalsConceded();
	}

	/**
	 * return 1 if calling object has more points than that of parameter object
	 * return -1 if calling object has less points than that of parameter object
	 * in case the two have the same number of points - 
	 * 		return 1 if calling object has a higher goal difference than that of parameter object
	 * 		return -1 if calling object has a lower goal difference than that of parameter object
	 * 		return 0 if calling object has the same goal difference as that of parameter object
	 */
	public int compareTo(TeamPerformance other) {
		if(getPoints() > other.getPoints())
			return 1;
		if(getPoints() < other.getPoints())
			return -1;
		if(getGoalDifference() > other.getGoalDifference())
			return 1;
		if(getGoalDifference() < other.getGoalDifference())
			return -1;
		return 0;
	}

	/**
	 * add the match passed to the teams record.
	 * note that the team corresponding to the calling object 
	 * might be the home team or the away team (or neither!) in the game passed.
	 * 
	 * based on different scenarios, the several attributes of the calling object
	 * need to be updated.
	 *  
	 * for example, 
	 * if calling object represents Chelsea's team performance and the
	 * match passed was between Arsenal and Liverpool, nothing changes for the calling object.
	 * 
	 * if calling object represents Chelsea's team performance and the
	 * match passed was between Arsenal (Home) and Chelsea (Away), 
	 * Chelsea's gamesPlayed increases by 1, and then based on who won,
	 * gamesWon or gamesDrawn will be updated. If Chelsea lost, neither gets changed,
	 * and getGamesLost() will return the correct value (as gamesPlayed HAS increased by 1).
	 * Away goals for Chelsea need to be updated too.
	 * 
	 * Similar scenarios when Chelsea draws or wins away.
	 * 
	 * Similar scenarios when Chelsea wins, draws or loses at home.
	 * @param m
	 */
	public void addMatchRecord(Match m) {
		if(m.getHomeTeam().equals(name)) {
			setGamesPlayed(gamesPlayed+1);
			if(m.winner()==1)
				setGamesWon(gamesWon+1);
			if(m.winner()==0)
				setGamesDrawn(gamesDrawn+1);
			setGoalsScored(goalsScored+m.getHomeGoals());
			setGoalsConceded(goalsConceded+m.getAwayGoals());
		}
		if(m.getAwayTeam().equals(name)) {
			setGamesPlayed(gamesPlayed+1);
			if(m.winner()==-1)
				setGamesWon(gamesWon+1);
			if(m.winner()==0)
				setGamesDrawn(gamesDrawn+1);
			setGoalsScored(goalsScored+m.getAwayGoals());
			setGoalsConceded(goalsConceded+m.getHomeGoals());
		}
	}
}