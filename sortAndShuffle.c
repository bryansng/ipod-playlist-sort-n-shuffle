#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define STR_SIZE 160
#include "sortAndShuffle.h"

void merge(char a[][STR_SIZE], int i1, int j1, int i2, int j2);


/*
* This method sorts the artists alphabetically. It takes as input:
* - sortedArtists: the array of artists that that should be sorted
* - numOfArtists: the total number of artists
*
*/
void sortArtists(char sortedArtists[][80] , int numOfArtists){
}



/*
* This method sorts the songs of a specific artist alphabetically. It takes as input:
* - songsOfAnArtist: the array of the songs of an artist that was provided from the standard input
* - numOfArtists: the number of artists provided from the standard input
*/
void sortSongs(char songsOfAnArtist[][80], int numOfArtists){
}
// merge sort function.
void mergeSort(char a[][STR_SIZE], int i, int j)
{
	int mid;
	
	if (i < j)
	{
		mid = (i+j)/2;
		mergeSort(a, i, mid);		// left recursion.
		mergeSort(a, mid+1, j);		// right recursion.
		merge(a, i, mid, mid+1, j);	// merging of two sorted sub-arrays.
	}
}
// merge sort function that merges two list together in ascending order via lexicographic ordering.
void merge(char a[][STR_SIZE], int i1, int j1, int i2, int j2)
{
	char temp[STR_SIZE][STR_SIZE] = {0};		// array used for merging.
	int i, j, k;
	i = i1;		// beginning of the first list.
	j = i2; 	// beginning of the second list.
	k = 0;
	
	while (i <= j1 && j <= j2)		// while elements exist in both list.
	{
		if (strcmp(a[i], a[j]) < 0)
			strcpy(temp[k++], a[i++]);
		else
			strcpy(temp[k++], a[j++]);
	}
	
	while (i <= j1)		// copy remaining elements of the first list.
		strcpy(temp[k++], a[i++]);
	
	while (j <= j2)		// copy remaining elements of the second list.
		strcpy(temp[k++], a[j++]);
		
	// Transfer elements from temp[] back to a[].
	for (i = i1, j = 0; i <= j2; i++, j++)
		strcpy(a[i], temp[j]);
}



/*
* This method shuffles a set of songs. It takes as input:
* - songsToBeShuffled: the array of the songs that should be shuffled
* - numOfSongs: the number of songs to be shuffled
*/
void shuffleSongs(char songsToBeShuffled[][80], int numOfSongs){
}
// shuffle function via knuth fisher-yate's algorithm.
void shuffleArrayOfStrings(char a[][STR_SIZE], int N)
{
	int i, j;  // counters.
	char temp[STR_SIZE][STR_SIZE] = {0};  // array used as temp in bubble sort.
	srand(time(NULL));
	
	for (i = N-1; i > 0; i--)
	{
		j = rand() % i;
		
		strcpy(temp[0], a[j]);
		strcpy(a[j], a[i]);
		strcpy(a[i], temp[0]);
	}
}
