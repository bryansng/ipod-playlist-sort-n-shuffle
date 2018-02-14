#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ARTISTS 4
#define MAX_SONGS 3
#define STR_SIZE 160
#include "sortAndShuffle.h"

void removeNewline(char a[][STR_SIZE], int i);

void printSortedSongs(char artists[][STR_SIZE], char sortedArtists[][STR_SIZE], char songsArtist1[][STR_SIZE], char songsArtist2[][STR_SIZE], char songsArtist3[][STR_SIZE], char songsArtist4[][STR_SIZE], int numOfArtists);

void createPlaylist(char playlist[][STR_SIZE], char artists[][STR_SIZE], char sortedArtists[][STR_SIZE], char songsArtist1[][STR_SIZE], char songsArtist2[][STR_SIZE], char songsArtist3[][STR_SIZE], char songsArtist4[][STR_SIZE], int *trackNum, int numOfArtists);

void createTrack(char playlist[][STR_SIZE], char sortedArtists[][STR_SIZE], char songsArtist[][STR_SIZE], int artNum, int songNum, int *track_no_from_main);

int main(void)
{
	
	// the array containing artists names.
	char artists[MAX_ARTISTS][STR_SIZE] = {0};
	char sortedArtists[MAX_ARTISTS][STR_SIZE] = {0};
	char songsArtist1[MAX_SONGS][STR_SIZE] = {0}; // songs for Artist 1.
	char songsArtist2[MAX_SONGS][STR_SIZE] = {0}; // songs for Artist 2.
	char songsArtist3[MAX_SONGS][STR_SIZE] = {0}; // songs for Artist 3.
	char songsArtist4[MAX_SONGS][STR_SIZE] = {0}; // songs for Artist 4.
	
	// the total number of artists (Note it can be less than 4).
	int numOfArtists = 0;
	// the total number of songs for each artist (Note that less than 3 songs can be provided for each artist).
	int numSongsPerArtist[MAX_ARTISTS] = {0};
	int totalSongs = 0;// the total number of songs.*
	
	/*
	char artists[MAX_ARTISTS][STR_SIZE] = {"bryan\n", "liew\n", "vincent\n", "brady\n"};
	char sortedArtists[MAX_ARTISTS][STR_SIZE] = {"bryan\n", "liew\n", "vincent\n", "brady\n"};
	char songsArtist1[MAX_SONGS][STR_SIZE] = {"b2\n", "b1\n", "B23\n"};
	char songsArtist2[MAX_SONGS][STR_SIZE] = {"l3\n", "L9\n", "l1\n"};
	char songsArtist3[MAX_SONGS][STR_SIZE] = {"v1\n"};
	char songsArtist4[MAX_SONGS][STR_SIZE] = {"Pork belly 3kg\n", "pork belly 1\n", "Belly"};
	int numOfArtists = 4;
	int numSongsPerArtist[MAX_ARTISTS] = {3, 3, 1, 3};
	//int totalSongs = 3 + 3 + 4 + 4;
	int totalSongs = 3+3+1+3;
	*/
	/*
	char artists[MAX_ARTISTS][STR_SIZE] = {"b\n", "c\n", "d\n"};
	char sortedArtists[MAX_ARTISTS][STR_SIZE] = {"b\n", "c\n", "d\n", "a\n"};
	char songsArtist1[MAX_SONGS][STR_SIZE] = {"b\n", "b3\n", "b1\n"};
	char songsArtist2[MAX_SONGS][STR_SIZE] = {"c\n", "c3\n", "c2\n"};
	char songsArtist3[MAX_SONGS][STR_SIZE] = {"d\n", "d3\n", "d1\n", "d2\n"};
	char songsArtist4[MAX_SONGS][STR_SIZE] = {"a\n", "a3\n", "a1\n", "a2\n"};
	int numOfArtists = 3;
	int numSongsPerArtist[MAX_ARTISTS] = {3, 3, 4, 4};
	//int totalSongs = 3 + 3 + 4 + 4;
	int totalSongs = 2 + 2 + 3;
	*/
	
	/*
	* Use here functions that you should implement to insert artists and songs from the standard input.
	* Note that you also need to track the number of artists and the number of songs for each artist.
	*/
	int artNum, songNum;
	
	
	char tempStoreArtist[1][STR_SIZE] = {0};	// holds artists temporary.
	char tempStoreSong[1][STR_SIZE] = {0};	// holds songs temporary.
	
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
					case 1:
						strcpy(songsArtist2[songNum], tempStoreSong[0]);
					case 2:
						strcpy(songsArtist3[songNum], tempStoreSong[0]);
					case 3:
						strcpy(songsArtist4[songNum], tempStoreSong[0]);
				}
				
				// keeps track number of songs per artist and total number of songs.
				numSongsPerArtist[artNum] += 1;
				totalSongs += 1;
			
				// resets tempStoreSong.
				strcpy(tempStoreSong[0], "");
				printf("tempStoreSong[0]: '%s'\n", tempStoreSong[0]);
			}
		}
		puts("");
	}
	
	/*
	// for removing newline.
	for (artNum = 0; artNum < numOfArtists; artNum++)
	{
		removeNewline(artists, artNum);	// removes newline in artists.
		removeNewline(sortedArtists, artNum);	// removes newline in sortedArtists.
		for (songNum = 0; songNum < MAX_SONGS; songNum++)
			if (artNum == 0)
				removeNewline(songsArtist1, songNum);
			else if (artNum == 1)
				removeNewline(songsArtist2, songNum);
			else if (artNum == 2)
				removeNewline(songsArtist3, songNum);
			else if (artNum == 3)
				removeNewline(songsArtist4, songNum);
	}
	*/
	
	/*
	* Use here the function sortArtists to sort the array of the artists and sortSongs to sort the songs of each artist
	* Print each artist (alphabetically) and for each of them print the list of songs sorted alphabetically
	*/
	printf("Unsorted list of songs:\n");
	printSortedSongs(artists, sortedArtists, songsArtist1, songsArtist2, songsArtist3, songsArtist4, numOfArtists);
	puts("\n");
	
	// sorts the Artist and song of the artist.
	sortArtistNSongs(sortedArtists, songsArtist1, songsArtist2, songsArtist3, songsArtist4, numSongsPerArtist, numOfArtists);
	
	printf("Sorted list of songs:\n");
	printSortedSongs(artists, sortedArtists, songsArtist1, songsArtist2, songsArtist3, songsArtist4, numOfArtists);
	
	
	/*
	* Use here the function shuffleSongs to shuffle all the songs
	* Print the list of shuffled songs
	*/
	int trackNum = 0;
	char playlist[MAX_ARTISTS*MAX_SONGS*2][STR_SIZE] = {0}; // holds the artist + song that is added to the playlist.
	
	// creates a playlist by adding all the songs with their artist together.
	createPlaylist(playlist, artists, sortedArtists, songsArtist1, songsArtist2, songsArtist3, songsArtist4, &trackNum, numOfArtists);
	createPlaylist(playlist, artists, sortedArtists, songsArtist1, songsArtist2, songsArtist3, songsArtist4, &trackNum, numOfArtists);
	
	// shuffle playlist via knuth fisher-yates's algorithm.
	printf("\n\nShuffled Playlist:\n");
	shuffleArrayOfStrings(playlist, totalSongs * 2);
	
	// prints the shuffled playlist.
	for (trackNum = 0; trackNum < totalSongs * 2; trackNum++)
		printf("%d: %s\n", trackNum, playlist[trackNum]);
	
	return 0;
}
















void printSortedSongs(char artists[][STR_SIZE], char sortedArtists[][STR_SIZE], char songsArtist1[][STR_SIZE], char songsArtist2[][STR_SIZE], char songsArtist3[][STR_SIZE], char songsArtist4[][STR_SIZE], int numOfArtists)
{
	int sortArtNum, songNum, artNum;
	for (sortArtNum = 0; sortArtNum < numOfArtists; sortArtNum++)
	{
		// prints the artist name.
		printf("%s\n", sortedArtists[sortArtNum]);
		
		// prints the songs based on the artists.
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
	}
}


void createPlaylist(char playlist[][STR_SIZE], char artists[][STR_SIZE], char sortedArtists[][STR_SIZE], char songsArtist1[][STR_SIZE], char songsArtist2[][STR_SIZE], char songsArtist3[][STR_SIZE], char songsArtist4[][STR_SIZE], int *i, int numOfArtists)
{
	int trackNum = *i;	// stores the trackNum.
	int sortArtNum, songNum, artNum;
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


void createTrack(char playlist[][STR_SIZE], char sortedArtists[][STR_SIZE], char songsArtist[][STR_SIZE], int sortArtNum, int songNum, int *track_no_from_main)
{
	int trackNum = *track_no_from_main;
	strcat(playlist[trackNum], sortedArtists[sortArtNum]);
	strcat(playlist[trackNum], " - ");
	strcat(playlist[trackNum], songsArtist[songNum]);
	
	trackNum++;
	*track_no_from_main = trackNum;
}


void removeNewline(char a[][STR_SIZE], int i)
{
	int len = strlen(a[i])-1;
	if (a[i][len] == '\n')
		a[i][len] = '\0';
}
