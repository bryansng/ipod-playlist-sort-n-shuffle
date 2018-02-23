/* Written by Sng Hong Yao.
 * Student No. 17205050 */
#include <stdio.h>
#include <string.h>

#define MAX_ARTISTS 4
#define MAX_SONGS 3
#define STR_SIZE 160
#include "printArtistsAndSongs.h"


// le function definitions.
/* Function prints the sorted artist with their songs. It takes in:
* - artists: the unsorted artists that is used to compare with sortedArtists.
* - sortedArtists: the sorted artists that is used to compare with artists.
* - songsArtist1: sorted songs of artist 1.
* - songsArtist2: sorted songs of artist 2.
* - songsArtist3: sorted songs of artist 3.
* - songsArtist4: sorted songs of artist 4.
* - numOfArtists: total number of artists.
*/
void printSortedSongs(char artists[][STR_SIZE], char sortedArtists[][STR_SIZE], char songsArtist1[][STR_SIZE], char songsArtist2[][STR_SIZE], char songsArtist3[][STR_SIZE], char songsArtist4[][STR_SIZE], int numOfArtists)
{
	int sortArtNum, songNum, artNum;
	
	/*	Loops explanation and creating relation between sortedArtist,
	*   songArtist and artist.
	*
	* first loop: for sortedArtists, print the artist name,
	* second loop: for songs of sorted artists,
	* third loop: for unsorted artists,
	* 			  if name of sortedArtists is the name of the first artist,
	* 			  and sortedArtists[] is a valid artist (i.e. not empty),
	* 			  and songsArtist1[] is a valid song (i.e. not empty),
	* 			  then print the song of that artist and break out to move 
	* 			  on to the next song.
	*/
	for (sortArtNum = 0; sortArtNum < numOfArtists; sortArtNum++)
	{
		printf("%s\n", sortedArtists[sortArtNum]);
		
		for (songNum = 0; songNum < MAX_SONGS; songNum++)
			for (artNum = 0; artNum < numOfArtists; artNum++)
			{
				if (strcmp(sortedArtists[sortArtNum], artists[0]) == 0 && strcmp(sortedArtists[sortArtNum], "") != 0 && strcmp(songsArtist1[songNum], "") != 0)
				{
					printf("    -  %s\n", songsArtist1[songNum]);
					break;
				}
				else if (strcmp(sortedArtists[sortArtNum], artists[1]) == 0 && strcmp(sortedArtists[sortArtNum], "") != 0 && strcmp(songsArtist2[songNum], "") != 0)
				{
					printf("    -  %s\n", songsArtist2[songNum]);
					break;
				}
				else if (strcmp(sortedArtists[sortArtNum], artists[2]) == 0 && strcmp(sortedArtists[sortArtNum], "") != 0 && strcmp(songsArtist3[songNum], "") != 0)
				{
					printf("    -  %s\n", songsArtist3[songNum]);
					break;
				}
				else if (strcmp(sortedArtists[sortArtNum], artists[3]) == 0 && strcmp(sortedArtists[sortArtNum], "") != 0 && strcmp(songsArtist4[songNum], "") != 0)
				{
					printf("    -  %s\n", songsArtist4[songNum]);
					break;
				}
			}
		puts("");
	}
}
