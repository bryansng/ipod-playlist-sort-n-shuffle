#include <stdio.h>
#include <string.h>

#define MAX_ARTISTS 4
#define MAX_SONGS 3
#define STR_SIZE 160
#include "insertArtistsAndSongs.h"

// le function prototypes.
void removeNewline(char a[][STR_SIZE], int i);


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
			
			if (tempStoreSong[0][0] == '\n')
				break;
			else
			{
				removeNewline(tempStoreSong, 0);
			
				switch(artNum)
				{
					case 0:
						strcpy(songsArtist1[songNum], tempStoreSong[0]);
						break;
					case 1:
						strcpy(songsArtist2[songNum], tempStoreSong[0]);
						break;
					case 2:
						strcpy(songsArtist3[songNum], tempStoreSong[0]);
						break;
					case 3:
						strcpy(songsArtist4[songNum], tempStoreSong[0]);
						break;
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


/* Function removes newline in a 2D character array and takes in,
* - a[][]: a 2D character array,
* - i: the index for which string row it should remove * the newline from.
*/
void removeNewline(char a[][STR_SIZE], int i)
{
	int len = strlen(a[i])-1;	// gets the string length-1 for that row.
	
	// if the 2nd last character is a newline, replace it with the null character.
	if (a[i][len] == '\n')
		a[i][len] = '\0';
}
