// https://www.cs.uic.edu/~jbell/CourseNotes/C_Programming/Arrays.html
#include <stdio.h>
#include <string.h>
#include "sortAndShuffle.h"

//#define NUM_ARTISTS 4
//#define NUM_SONGS 3
#define NUM_ARTISTS 1
#define NUM_SONGS 1
#define STR_SIZE 80


int main(void)
{
	//The array containing artists names
	char artists[NUM_ARTISTS][STR_SIZE] = {0};
	//The array containing the sorted artists
	char sortedArtists[NUM_ARTISTS][STR_SIZE] = {0};
	//Songs for Artist 1
	char songsArtist1[NUM_SONGS][STR_SIZE] = {0};
	//Songs for Artist 2
	char songsArtist2[NUM_SONGS][STR_SIZE] = {0};
	//Songs for Artist 3
	char songsArtist3[NUM_SONGS][STR_SIZE] = {0};
	//Songs for Artist 4
	char songsArtist4[NUM_SONGS][STR_SIZE] = {0};
	//The total number of artists (Note it can be less than 4)
	int numOfArtists = 0;
	//The total number of songs for each artist (Note that less than 3 songs can be provided for each artist)
	int numSongsPerArtist[NUM_ARTISTS] = {0};

	/*
	 * Use here functions that you should implement to insert artists and songs from the standard input.
	 * Note that you also need to track the number of artists and the number of songs for each artist.
	 */
	int artNum, songNum;
	for (artNum = 0; artNum < NUM_ARTISTS; artNum++)
	{
		// takes in the artist names.
		printf("Insert an artist/group name:\n");
		fgets(artists[artNum], STR_SIZE, stdin);
		puts("");
		
		// takes in the artist songs.
		for (songNum = 0; songNum < NUM_SONGS; songNum++)
		{
			printf("Insert song %d for %s", songNum+1, artists[artNum]);
			fgets(songsArtist1[songNum], STR_SIZE, stdin);
			
			// keeps track number of songs per artist.
			if (strlen(songsArtist1[songNum]) > 0)
				numSongsPerArtist[artNum] += 1;
		}
		puts("");
	}
	/*
	 * Use here the function sortArtists to sort the array of the artists and sortSongs to sort the songs of each artist
	 * Print each artist (alphabetically) and for each of them print the list of songs sorted alphabetically
	 */

	 /*
	 * Use here the function shuffleSongs to shuffle all the songs
	 * Print the list of shuffled songs
	 */




	return 0;
}



