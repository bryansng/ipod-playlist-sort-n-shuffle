/* Written by Sng Hong Yao.
 * Student No. 17205050 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ARTISTS 4
#define STR_SIZE 160
#include "sortAndShuffle.h"

// le function prototypes.
void quickSort(char a[][STR_SIZE], int N);
void merge(char a[][STR_SIZE], int i1, int j1, int i2, int j2);
void mergeSort(char a[][STR_SIZE], int i, int j);

// le function definitions.
/* Function sorts sortedArtists and songsArtist. It takes in:
* - sortedArtists: artist names to be sorted.
* - songsArtist1: songs of artist 1 to be sorted.
* - songsArtist2: songs of artist 2 to be sorted.
* - songsArtist3: songs of artist 3 to be sorted.
* - songsArtist4: songs of artist 4 to be sorted.
* - numSongsPerArtist: number of songs from each artist.
* - numOfArtists: total number of artists inputted (required for loop).
*/
void sortArtistNSongs(char sortedArtists[][STR_SIZE], char songsArtist1[][STR_SIZE], char songsArtist2[][STR_SIZE], char songsArtist3[][STR_SIZE], char songsArtist4[][STR_SIZE], int numSongsPerArtist[MAX_ARTISTS], int numOfArtists)
{
	int artNum;
	// sorts the artist by lexicographic ordering in ascending order.
	//mergeSort(sortedArtists, 0, numOfArtists-1);
	quickSort(sortedArtists, numOfArtists);
	// sorts the song names by lexicographic ordering in ascending order.
	for (artNum = 0; artNum < numOfArtists; artNum++)
		if (artNum == 0)
			//mergeSort(songsArtist1, 0, numSongsPerArtist[artNum]-1);
			quickSort(songsArtist1, numSongsPerArtist[artNum]);
		else if (artNum == 1)
			//mergeSort(songsArtist2, 0, numSongsPerArtist[artNum]-1);
			quickSort(songsArtist2, numSongsPerArtist[artNum]);
		else if (artNum == 2)
			//mergeSort(songsArtist3, 0, numSongsPerArtist[artNum]-1);
			quickSort(songsArtist3, numSongsPerArtist[artNum]);
		else if (artNum == 3)
			//mergeSort(songsArtist4, 0, numSongsPerArtist[artNum]-1);
			quickSort(songsArtist4, numSongsPerArtist[artNum]);
}


/* Function quick sorts any 2D character array lexicographically. It takes in:
* - a: 2D character array to be sorted.
* - N: number of elements in the 2D character array. (or size of array)
*/
void quickSort(char a[][STR_SIZE], int N)
{
	size_t i, j;
	int minIndex;
	char temp[1][STR_SIZE] = {0};
	
	for (i = 0; i < N-1; i++)
	{
		minIndex = i;
		for (j = i+1; j < N; j++)
			// if numerical lexicographic ordering of minIndex is greater than j, we swap them.
			if (strcmp(a[minIndex], a[j]) > 0)
				minIndex = j;
			
		strcpy(temp[0], a[minIndex]);
		strcpy(a[minIndex], a[i]);
		strcpy(a[i], temp[0]);
	}
}
/* Function merge sorts any 2D character array lexicographically. It takes in:
* - a: 2D character array to be sorted.
* - i: starting index of array to sort.
* - j: ending index of array to sort.
*/
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
/* Function that merges two list together in ascending order lexicographically.
*  It takes in:
* - a: 2D character array to be sorted.
* - i1: starting index of the first list.
* - j1: ending index of the first list.
* - i2: starting index of the second list.
* - j2: ending index of the seond list.
*/
void merge(char a[][STR_SIZE], int i1, int j1, int i2, int j2)
{
	char temp[STR_SIZE][STR_SIZE] = {0};		// array used for merging.
	int i, j, k = 0;
	i = i1;		// beginning of the first list.
	j = i2; 	// beginning of the second list.
	
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
		
	// transfer elements from temp[] back to a[].
	for (i = i1, j = 0; i <= j2; i++, j++)
		strcpy(a[i], temp[j]);
}


/* Function brute-force shuffles any 2D character array via Knuth 
*  Fisher-Yate's algorithm and takes into account the consecution of the 
*  song not appearing until 5 other songs appeared. It takes in:
* - a: 2D character array to be shuffled.
* - N: row size of the 2D character array.
*/
void shuffleArrayOfStrings(char a[][STR_SIZE], int N)
{
	int i, j, k;  		// counters.
	int shuffle = 1;	// boolean value.
	char temp[1][STR_SIZE] = {0};  // array used as temp in switching pos.
	srand(time(NULL));	// seeds random number generator.
	
	// while loop: while we are allowed to shuffle
	while (shuffle)
	{
		// shuffle algorithm, starting from the last element in array to the second element.
		for (i = N-1; i > 0; i--)
		{
			j = rand() % (i+1);	// from last to first.
			
			strcpy(temp[0], a[j]);
			strcpy(a[j], a[i]);
			strcpy(a[i], temp[0]);
		}
		/*
		// shuffle algorithm, starting from the first element in array to the second last element.
		for (i = 0; i < N-1; i++)
		{
			j = i + (rand() % (N-i)); // from first to last.
			
			strcpy(temp[0], a[j]);
			strcpy(a[j], a[i]);
			strcpy(a[i], temp[0]);
		}
		*/
		
		// Deals with consecution.
		/* First, set the shuffle flag to disable,
		 * loop through the playlist and search for songs that appeared within
		 * the previous 5 songs of itself.
		 * if such cases exist, set the shuffle flag back to enable and break
		 * out of both inner and outer loop, back to the start of the while 
		 * loop.
		 */
		shuffle = 0;
		for (i = N-1; i > 0; i--)
		{
			// Consecution where songs should appear after 5 songs of itself.
			if (N/2 > 5)
			{
				// upper 5 index down to will-be replacing index.
				for (k = i+5; k > i; k--)
					if (strcmp(a[i], a[k]) == 0)
					{
						shuffle = 1;
						break;	// break out of inner loop.
					}
			}
			/* Consecution where songs should appear after 5 songs of itself do not work when the number of inputted songs are less than 6.
			 * The code below simply ensures that the same song do not after itself.
			 */
			else
			{
				// upper N/4=totalSongs/2 index down to will-be replacing index.
				for (k = i+(N/4); k > i; k--)
					if (strcmp(a[i], a[k]) == 0)
					{
						shuffle = 1;
						break;	// break out of inner loop.
					}
			}
			if (shuffle)
				break;	// break out of outer loop.
		}
	}
}
