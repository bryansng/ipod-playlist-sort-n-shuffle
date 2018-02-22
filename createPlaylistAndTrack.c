#include <string.h>

#define MAX_SONGS 3
#define STR_SIZE 160
#include "createPlaylistAndTrack.h"

// le function prototypes.
void createTrack(char playlist[][STR_SIZE], char sortedArtists[][STR_SIZE], char songsArtist[][STR_SIZE], int artNum, int songNum, int *track_no_from_main);


// le function definitions.
/* Function creates a playlist by creating individual tracks and adding them into the playlist. It takes in:
* - playlist: the playlist array where tracks are added into.
* - artists: the unsorted artists that is used to compare with sortedArtists.
* - sortedArtists: the sorted artists that is used to compare with artists.
* - sortedArtist1: sorted songs of artist 1.
* - sortedArtist2: sorted songs of artist 2.
* - sortedArtist3: sorted songs of artist 3.
* - sortedArtist4: sorted songs of artist 4.
* - *i: starting index to start adding tracks into.
* - numOfArtists: total number of artists.
*/
void createPlaylist(char playlist[][STR_SIZE], char artists[][STR_SIZE], char sortedArtists[][STR_SIZE], char songsArtist1[][STR_SIZE], char songsArtist2[][STR_SIZE], char songsArtist3[][STR_SIZE], char songsArtist4[][STR_SIZE], int *i, int numOfArtists)
{
	int trackNum = *i;	// stores the trackNum.
	int sortArtNum, songNum, artNum;
	
	/*	Loops explanation and creating relation between sortedArtist, 
	*   songArtist and artist.
	*
	* first loop: for sortedArtists,
	* second loop: for songs of sorted artists,
	* third loop: for unsorted artists,
	* 			  if name of sortedArtists is the name of the first artist,
	* 			  and sortedArtists[] is a valid artist (i.e. not empty),
	* 			  and songsArtist1[] is a valid song (i.e. not empty),
	* 			  then create a track of them and break out to move on to the
	* 			  next song.
	*/
	for (sortArtNum = 0; sortArtNum < numOfArtists; sortArtNum++)
		for (songNum = 0; songNum < MAX_SONGS; songNum++)
			for (artNum = 0; artNum < numOfArtists; artNum++)
			{
				if (strcmp(sortedArtists[sortArtNum], artists[0]) == 0 && strcmp(sortedArtists[sortArtNum], "") != 0 && strcmp(songsArtist1[songNum], "") != 0)
				{
					createTrack(playlist, sortedArtists, songsArtist1, sortArtNum, songNum, &trackNum);
					break;
				}
				else if (strcmp(sortedArtists[sortArtNum], artists[1]) == 0 && strcmp(sortedArtists[sortArtNum], "") != 0 && strcmp(songsArtist2[songNum], "") != 0)
				{
					createTrack(playlist, sortedArtists, songsArtist2, sortArtNum, songNum, &trackNum);
					break;
				}
				else if (strcmp(sortedArtists[sortArtNum], artists[2]) == 0 && strcmp(sortedArtists[sortArtNum], "") != 0 && strcmp(songsArtist3[songNum], "") != 0)
				{
					createTrack(playlist, sortedArtists, songsArtist3, sortArtNum, songNum, &trackNum);
					break;
				}
				else if (strcmp(sortedArtists[sortArtNum], artists[3]) == 0 && strcmp(sortedArtists[sortArtNum], "") != 0 && strcmp(songsArtist4[songNum], "") != 0)
				{
					createTrack(playlist, sortedArtists, songsArtist4, sortArtNum, songNum, &trackNum);
					break;
				}
			}
	*i = trackNum;	// returns the trackNum back into main.
}


/* Function creates a track by concatenating the song name to its artist and takes in,
* - playlist: 2D-array where the track is added into.
* - sortedArtists: 2D-array containing the sorted artists.
* - songsArtist: 2D-array containing the songs of the artist.
* - sortArtNum: artist index in sortedArtists.
* - songNum: song index in songsArtist
* - *track_no_from_main: starting index to start adding tracks into.
*/
void createTrack(char playlist[][STR_SIZE], char sortedArtists[][STR_SIZE], char songsArtist[][STR_SIZE], int sortArtNum, int songNum, int *track_no_from_main)
{
	// assigns track number into a variable
	int trackNum = *track_no_from_main;
	
	// appends artist name first, then a "-", followed by the song.
	strcat(playlist[trackNum], sortedArtists[sortArtNum]);
	strcat(playlist[trackNum], " - ");
	strcat(playlist[trackNum], songsArtist[songNum]);
	
	trackNum++;
	*track_no_from_main = trackNum;	// returns the starting index.
}
