#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ARTISTS 4
#define MAX_SONGS 3
#define STR_SIZE 160
#include "sortAndShuffle.h"

// le function prototypes.
void insertArtistsNSongs(char artists[][STR_SIZE], char sortedArtists[][STR_SIZE], char songsArtist1[][STR_SIZE], char songsArtist2[][STR_SIZE], char songsArtist3[][STR_SIZE], char songsArtist4[][STR_SIZE], int *ttl_artists_from_main, int numSongsPerArtist[], int *ttl_songs_from_main);

void removeNewline(char a[][STR_SIZE], int i);

void printSortedSongs(char artists[][STR_SIZE], char sortedArtists[][STR_SIZE], char songsArtist1[][STR_SIZE], char songsArtist2[][STR_SIZE], char songsArtist3[][STR_SIZE], char songsArtist4[][STR_SIZE], int numOfArtists);

void createPlaylist(char playlist[][STR_SIZE], char artists[][STR_SIZE], char sortedArtists[][STR_SIZE], char songsArtist1[][STR_SIZE], char songsArtist2[][STR_SIZE], char songsArtist3[][STR_SIZE], char songsArtist4[][STR_SIZE], int *trackNum, int numOfArtists);

void createTrack(char playlist[][STR_SIZE], char sortedArtists[][STR_SIZE], char songsArtist[][STR_SIZE], int artNum, int songNum, int *track_no_from_main);

int main(void)
{
	/*
	// the array containing artists names.
	char artists[MAX_ARTISTS][STR_SIZE] = {0};
	// the array containing sorted artists names.
	char sortedArtists[MAX_ARTISTS][STR_SIZE] = {0};
	char songsArtist1[MAX_SONGS][STR_SIZE] = {0}; // songs for Artist 1.
	char songsArtist2[MAX_SONGS][STR_SIZE] = {0}; // songs for Artist 2.
	char songsArtist3[MAX_SONGS][STR_SIZE] = {0}; // songs for Artist 3.
	char songsArtist4[MAX_SONGS][STR_SIZE] = {0}; // songs for Artist 4.
	
	// the total number of artists (Note it can be less than 4).
	int numOfArtists = 0;
	// the total number of songs for each artist (Note that less than 3 songs can be provided for each artist).
	int numSongsPerArtist[MAX_ARTISTS] = {0};
	// the total number of songs.
	int totalSongs = 0;
	*/
	/*
	// superior test case 5.
	char artists[MAX_ARTISTS][STR_SIZE] = {"bb sng hong yao"};
	char sortedArtists[MAX_ARTISTS][STR_SIZE] = {"bb sng hong yao"};
	char songsArtist1[MAX_SONGS][STR_SIZE] = {"B23 B9381023 ./"};
	char songsArtist2[MAX_SONGS][STR_SIZE] = {0};
	char songsArtist3[MAX_SONGS][STR_SIZE] = {0};
	char songsArtist4[MAX_SONGS][STR_SIZE] = {0};
	int numOfArtists = 1;
	int numSongsPerArtist[MAX_ARTISTS] = {1};
	int totalSongs = 1;	// 1
	*/
	/*
	// superior test case 4.
	char artists[MAX_ARTISTS][STR_SIZE] = {"bb sng hong yao", "emily liew xuan"};
	char sortedArtists[MAX_ARTISTS][STR_SIZE] = {"bb sng hong yao", "emily liew xuan"};
	char songsArtist1[MAX_SONGS][STR_SIZE] = {"B23 B9381023 ./"};
	char songsArtist2[MAX_SONGS][STR_SIZE] = {"l5 yoyo"};
	char songsArtist3[MAX_SONGS][STR_SIZE] = {0};
	char songsArtist4[MAX_SONGS][STR_SIZE] = {0};
	int numOfArtists = 2;
	int numSongsPerArtist[MAX_ARTISTS] = {1, 1};
	int totalSongs = 2;	// 2
	*/
	/*
	// superior test case 3.
	char artists[MAX_ARTISTS][STR_SIZE] = {"bb sng hong yao", "emily liew xuan", "vincent ee en"};
	char sortedArtists[MAX_ARTISTS][STR_SIZE] = {"bb sng hong yao", "emily liew xuan", "vincent ee en"};
	char songsArtist1[MAX_SONGS][STR_SIZE] = {"b1 b9 []", "B23 B9381023 ./"};
	char songsArtist2[MAX_SONGS][STR_SIZE] = {"l5 yoyo"};
	char songsArtist3[MAX_SONGS][STR_SIZE] = {"v1 in the house", "vince vince"};
	char songsArtist4[MAX_SONGS][STR_SIZE] = {0};
	int numOfArtists = 3;
	int numSongsPerArtist[MAX_ARTISTS] = {2, 1, 2};
	int totalSongs = 2+1+2;	// 5
	*/
	
	// superior test case 2.
	char artists[MAX_ARTISTS][STR_SIZE] = {"bb sng hong yao", "emily liew xuan", "vincent ee en"};
	char sortedArtists[MAX_ARTISTS][STR_SIZE] = {"bb sng hong yao", "emily liew xuan", "vincent ee en"};
	char songsArtist1[MAX_SONGS][STR_SIZE] = {"b1 b9 []", "B23 B9381023 ./", "bobo"};
	char songsArtist2[MAX_SONGS][STR_SIZE] = {"l5 yoyo"};
	char songsArtist3[MAX_SONGS][STR_SIZE] = {"v1 in the house", "vince vince"};
	char songsArtist4[MAX_SONGS][STR_SIZE] = {0};
	int numOfArtists = 3;
	int numSongsPerArtist[MAX_ARTISTS] = {3, 1, 2};
	int totalSongs = 3+1+2;	// 6
	
	/*
	// superior test case 1.
	char artists[MAX_ARTISTS][STR_SIZE] = {"bb sng hong yao", "emily liew xuan", "vincent ee en", "brady"};
	char sortedArtists[MAX_ARTISTS][STR_SIZE] = {"bb sng hong yao", "emily liew xuan", "vincent ee en", "brady"};
	char songsArtist1[MAX_SONGS][STR_SIZE] = {"b1 b9 []", "B23 B9381023 ./"};
	char songsArtist2[MAX_SONGS][STR_SIZE] = {"l5 yoyo", "L9 hoho", "l1 bubu pp"};
	char songsArtist3[MAX_SONGS][STR_SIZE] = {"v1 in the house"};
	char songsArtist4[MAX_SONGS][STR_SIZE] = {"Pork belly no", "AIYOYO hehe"};
	int numOfArtists = 4;
	int numSongsPerArtist[MAX_ARTISTS] = {2, 3, 1, 2};
	int totalSongs = 2+3+1+2;	// 8
	*/
	/*	PART 1
	* Use here functions that you should implement to insert artists and songs from the standard input.
	* Note that you also need to track the number of artists and the number of songs for each artist.
	*/
	//insertArtistsNSongs(artists, sortedArtists, songsArtist1, songsArtist2, songsArtist3, songsArtist4, &numOfArtists, numSongsPerArtist, &totalSongs);
	
	
	/*	PART 2
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
	
	
	/*	PART 3
	* Use here the function shuffleSongs to shuffle all the songs
	* Print the list of shuffled songs
	*/
	int trackNum = 0;	// starting index for track number set to zero.
	char playlist[MAX_ARTISTS*MAX_SONGS*2][STR_SIZE] = {0}; // holds the artist + song that is added to the playlist.
	
	// creates a playlist by adding all the songs with their artist together.
	// creates first half of the playlist.
	createPlaylist(playlist, artists, sortedArtists, songsArtist1, songsArtist2, songsArtist3, songsArtist4, &trackNum, numOfArtists);
	// creates second half of the playlist.
	createPlaylist(playlist, artists, sortedArtists, songsArtist1, songsArtist2, songsArtist3, songsArtist4, &trackNum, numOfArtists);
	
	// shuffle playlist via knuth fisher-yates's algorithm,
	// and handles consecution of the track appearing after 5 different songs.
	printf("\nShuffled Playlist:\n");
	shuffleArrayOfStrings(playlist, totalSongs * 2);
	
	// prints the shuffled playlist.
	for (trackNum = 0; trackNum < totalSongs * 2; trackNum++)
		printf("%d: %s\n", trackNum, playlist[trackNum]);
	
	
	return 0;
}














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
