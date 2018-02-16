#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ARTISTS 4
#define STR_SIZE 160
#include "sortAndShuffle.h"

void quickSort(char a[][STR_SIZE], int N);
void merge(char a[][STR_SIZE], int i1, int j1, int i2, int j2);
void mergeSort(char a[][STR_SIZE], int i, int j);

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
	mergeSort(sortedArtists, 0, numOfArtists-1);
	// sorts the song names by lexicographic ordering in ascending order.
	for (artNum = 0; artNum < numOfArtists; artNum++)
		if (artNum == 0)
			//mergeSort(songsArtist1, 0, numSongsPerArtist[artNum]-1);
			quickSort(songsArtist1, numSongsPerArtist[artNum]);
		else if (artNum == 1)
			//mergeSort(songsArtist2, 0, numSongsPerArtist[artNum]-1);
			quickSort(songsArtist2, numSongsPerArtist[artNum]);
		else if (artNum == 2)
			mergeSort(songsArtist3, 0, numSongsPerArtist[artNum]-1);
		else if (artNum == 3)
			mergeSort(songsArtist4, 0, numSongsPerArtist[artNum]-1);
}

// N is the size of the array.
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
void quickSortV2(char a[][STR_SIZE], int N)
{
	size_t i, j;
	int minIndex;
	int swap = 0;	// boolean value.
	char temp[1][STR_SIZE] = {0};
	
	for (i = 0; i < N-1; i++)
	{
		minIndex = i;
		for (j = i+1; j < N; j++)
			// if numerical lexicographic ordering of minIndex is greater than j, we swap them.
			if (strcmp(a[minIndex], a[j]) > 0)
			{
				minIndex = j;
				swap = 1;
			}
			
		if (swap)
		{
			strcpy(temp[0], a[minIndex]);
			strcpy(a[minIndex], a[i]);
			strcpy(a[i], temp[0]);
			
			swap = 0;
		}
	}
}
void quickSortV1(char a[][STR_SIZE], int N)
{
	size_t i, j;
	int minIndex;
	int swap = 0;	// boolean value.
	char temp[1][STR_SIZE] = {0};
	
	for (i = 0; i < N-1; i++)
	{
		minIndex = i;
		for (j = i+1; j < N; j++)
			// if numerical lexicographic ordering of minIndex is greater than j, we swap them.
			if (strcmp(a[minIndex], a[j]) > 0)
			{
				minIndex = j;
				swap = 1;
			}
			
			if (swap)
			{
				memset(temp[0], '$', N-2);
				temp[0][N-1] = '\0';
				
				strcpy(temp[0], a[minIndex]);
				strcpy(a[minIndex], a[i]);
				strcpy(a[i], temp[0]);
				
				swap = 0;
			}
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


/* Function shuffles any 2D character array via Knuth Fisher-Yate's algorithm.
*  It takes in:
* - a: 2D character array to be shuffled.
* - N: row size of the 2D character array.
*/
void shuffleArrayOfStringsV1(char a[][STR_SIZE], int N)
{
	int i, j, k;  		// counters.
	int shuffle = 1;	// boolean value.
	int shuffle_num = 0;
	char temp[1][STR_SIZE] = {0};  // array used as temp in switching pos.
	srand(time(NULL));	// seeds random number generator.
	
	while (shuffle)
	{
		printf("Number of Shuffles: %d\n", shuffle_num);
		for (i = N-1; i > 0; i--)
		{
			j = rand() % i;
			
			strcpy(temp[0], a[j]);
			strcpy(a[j], a[i]);
			strcpy(a[i], temp[0]);
		}
		shuffle = 0;
		
		int conflict_num = 0;
		for (i = N-1; i > 0; i--)
		{
			//for (k = i-5; k < i; k++)
			for (k = i+5; k > i; k--)
				if (strcmp(a[i], a[k]) == 0)
				{
					printf("\nConflict: %d\n", ++conflict_num);
					printf("%d: %s\n", i, a[i]);
					puts("with");
					printf("%d: %s\n", k, a[k]);
					puts("");
					
					shuffle = 1;
					break;
				}
			if (shuffle)
				break;
		}
		shuffle_num++;
	}
}


void shuffleArrayOfStrings(char a[][STR_SIZE], int N)
{
	int i, j, k;  		// counters.
	int allow_switch = 0;	// boolean value.
	int shuffle_num = 0;
	char temp[1][STR_SIZE] = {0};  // array used as temp in switching pos.
	//srand(time(NULL));	// seeds random number generator.
	
	int conflict_num = 0;
	
	for (i = N-1; i > 0; )
	{
		printf("i: %d\n", i);
		j = rand() % i;
		
		printf("a[%d]: %s\t%s\n", j, a[j], "replacing with");
		// switch pos only if the element in the array does not occur in the previous 5 positions.
		for (k = i+5; k > i; k--)
		{
			printf("k: %d\ta[k]: %s\n", k, a[k]);
			
			if (strcmp(a[j], a[k]) == 0)	// if songs exist within 5 tracks
			{
				conflict_num++;
				puts("");
				break;
			}
			else if (k == i+1)	// if k reaches the last one
			{
				conflict_num = 0;
				--k;
				printf("k: %d\ta[k]: %s\t%s\n", k, a[k], "being replaced");
				allow_switch = 1;
			}
		}
		
		if (allow_switch)
		{
			strcpy(temp[0], a[j]);
			strcpy(a[j], a[i]);
			strcpy(a[i], temp[0]);
			
			printf("replaced\n\n");
			allow_switch = 0;
			i--;
		}
		
		if (conflict_num >= 20)	// break out and be printed by main.
			break;
	}
}
