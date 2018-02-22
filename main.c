#include <stdio.h>

#define MAX_ARTISTS 4
#define MAX_SONGS 3
#define STR_SIZE 160
#include "insertArtistsAndSongs.h"
#include "sortAndShuffle.h"
#include "printArtistsAndSongs.h"
#include "createPlaylistAndTrack.h"

int main(void)
{
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
	
	
	
	/*	PART 1
	* Use here functions that you should implement to insert artists and songs from the standard input.
	* Note that you also need to track the number of artists and the number of songs for each artist.
	*/
	insertArtistsNSongs(artists, sortedArtists, songsArtist1, songsArtist2, songsArtist3, songsArtist4, &numOfArtists, numSongsPerArtist, &totalSongs);
	
	
	
	/*	PART 2
	* Use here the function sortArtists to sort the array of the artists and sortSongs to sort the songs of each artist
	* Print each artist (alphabetically) and for each of them print the list of songs sorted alphabetically
	*/
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
		printf("%02d: %s\n", trackNum+1, playlist[trackNum]);
}
