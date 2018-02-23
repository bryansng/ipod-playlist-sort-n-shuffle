/* Written by Sng Hong Yao.
 * Student No. 17205050 */
#include <stdio.h>
#include <string.h>

#define MAX_ARTISTS 4
#define MAX_SONGS 3
#define STR_SIZE 160
#include "insertArtistsAndSongs.h"

// le function prototypes.
void removeNewline(char a[][STR_SIZE], int i);
int artistRepeat(char artists[][STR_SIZE], char artist[][STR_SIZE]);
int songRepeat(char songsArtist[][STR_SIZE], char song[][STR_SIZE]);


// le function definitions.
/* Function inserts the artist name and song of the artist from the stdin.
*  It takes in:
* - artists: artists names to be inputted.
* - sortedArtists: artists names to be inputted and sorted after.
* - songsArtist1: artist 1 songs to be inputted.
* - songsArtist2: artist 2 songs to be inputted.
* - songsArtist3: artist 3 songs to be inputted.
* - songsArtist4: artist 4 songs to be inputted.
* - numOfArtists: total number of artists.
* - numSongsPerArtist: number of songs from each artist.
* - *ttl_songs_from_main: total number of songs.
*/
void insertArtistsNSongs(char artists[][STR_SIZE], char sortedArtists[][STR_SIZE], char songsArtist1[][STR_SIZE], char songsArtist2[][STR_SIZE], char songsArtist3[][STR_SIZE], char songsArtist4[][STR_SIZE], int *ttl_artists_from_main, int numSongsPerArtist[], int *ttl_songs_from_main)
{
	int artNum, songNum;
	char tempStoreArtist[1][STR_SIZE] = {0};	// holds artists temporary.
	char tempStoreSong[1][STR_SIZE] = {0};		// holds songs temporary.
	int numOfArtists = *ttl_artists_from_main;	// assigns total artists into a variable.
	int totalSongs = *ttl_songs_from_main;		// assigns total songs into a variable.
	
	for (artNum = 0; artNum < MAX_ARTISTS; artNum++)
	{
		// takes in the artist names from user.
		// if user press enter without input, stop inputting more artists from user.
		printf("Insert an artist/group name:\n");
		fgets(tempStoreArtist[0], STR_SIZE, stdin);
		
		if (tempStoreArtist[0][0] == '\n')
			break;
		else
		{
			removeNewline(tempStoreArtist, 0);
			
			// if artist is repeated, goes back up to the start of the for loop and keeps asking the user for a different artist name.
			// else, copy into artists.
			if (artistRepeat(artists, tempStoreArtist))
			{
				printf("\n[Input Error] You cannot input the same artist twice.\n\n");
				artNum--;
				strcpy(tempStoreArtist[0], "");
				continue;
			}
			
			strcpy(artists[artNum], tempStoreArtist[0]);
			strcpy(sortedArtists[artNum], tempStoreArtist[0]);
			
			// keeps track the number of artists.
			numOfArtists += 1;
			
			// resets tempStoreArtist.
			strcpy(tempStoreArtist[0], "");
		}
		puts("");
		
		// takes in the artist songs from user and removes newline in songs.
		// if user press enter without input, stop inputting more songs from user.
		for (songNum = 0; songNum < MAX_SONGS; songNum++)
		{
			printf("Insert song %d for %s\n", songNum+1, artists[artNum]);
			fgets(tempStoreSong[0], STR_SIZE, stdin);
			
			// if artist name is valid, but the first song is not inputted for that artist,
			// then keep asking for the user to input at least one song for that artist.
			if ( tempStoreSong[0][0] == '\n' && songNum == 0 && (strcmp(artists[artNum], "") != 0))
			{
				printf("[Input Error] Please enter at least one song for %s.\n\n", artists[artNum]);
				songNum--;
			}
			else if (tempStoreSong[0][0] == '\n')
				break;
			else
			{
				int bool_back_to_for = 0;
				removeNewline(tempStoreSong, 0);
			
				switch(artNum)
				{
					// if song is repeated, goes back up to the start of the for loop and keeps asking the user for a different song name.
					// else, copy into songsArtist.
					case 0:
						if (songRepeat(songsArtist1, tempStoreSong))
							bool_back_to_for = 1;
						else
							strcpy(songsArtist1[songNum], tempStoreSong[0]);
						break;
					case 1:
						if (songRepeat(songsArtist2, tempStoreSong))
							bool_back_to_for = 1;
						else
							strcpy(songsArtist2[songNum], tempStoreSong[0]);
						break;
					case 2:
						if (songRepeat(songsArtist3, tempStoreSong))
							bool_back_to_for = 1;
						else
							strcpy(songsArtist3[songNum], tempStoreSong[0]);
						break;
					case 3:
						if (songRepeat(songsArtist4, tempStoreSong))
							bool_back_to_for = 1;
						else
							strcpy(songsArtist4[songNum], tempStoreSong[0]);
						break;
				}
				// prints error message and goes back to top of for loop.
				if (bool_back_to_for)
				{
					printf("\n[Input Error] You cannot input the same song for %s.\n\n", artists[artNum]);
					songNum--;
					continue; // prevents incrementing totalSongs and numSongsPerArtist[] if song repeated.
				}
				
				// keeps track number of songs per artist and total number of songs.
				numSongsPerArtist[artNum] += 1;
				totalSongs += 1;
				
				// resets tempStoreSong.
				strcpy(tempStoreSong[0], "");
			}
		}
		puts("");
	}
	*ttl_artists_from_main = numOfArtists;	// returns the numOfArtists back into main.
	*ttl_songs_from_main = totalSongs;		// returns the totalSongs back into main.
}


/* Function checks if the same artist is inputted more than once in artists and takes in,
* - artists: 2D character array containing the artists.
* - artist: 2D character array containing the inputted artist from the user.
*/
int artistRepeat(char artists[][STR_SIZE], char artist[][STR_SIZE])
{
	for (size_t artNum = 0; artNum < MAX_ARTISTS; artNum++)
		if (strcmp(artists[artNum], artist[0]) == 0)
			return 1;
			
	return 0;
}


/* Function checks if the same song is inputted more than once in songsArtist and takes in,
* - songsArtist: 2D character array containing the songs of the artist.
* - song: 2D character array containing the inputted song from the user.
*/
int songRepeat(char songsArtist[][STR_SIZE], char song[][STR_SIZE])
{
	for (size_t songNum = 0; songNum < MAX_SONGS; songNum++)
		if (strcmp(songsArtist[songNum], song[0]) == 0)
			return 1;
			
	return 0;
}


/* Function removes newline at the end of a string in a 2D character array and takes in,
* - a[][]: a 2D character array,
* - i: the index for which string row it should remove the newline from.
*/
void removeNewline(char a[][STR_SIZE], int i)
{
	int len = strlen(a[i])-1;	// gets the string length-1 for that row.
	
	// if the 2nd last character is a newline, replace it with the null character.
	if (a[i][len] == '\n')
		a[i][len] = '\0';
}
