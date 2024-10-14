#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct entry
{
	char word[15];
	char definition[50];
};

// Comparator function for qsort
int compare(const void *a, const void *b)
{
	// Cast to struct entry pointers
	struct entry *entryA = (struct entry *)a;
	struct entry *entryB = (struct entry *)b;

	// Compare the words in the entries
	return strcmp(entryA->word, entryB->word);
}
void dictionarySort(struct entry dictionary[], int entries)
{
	// Use qsort to sort the dictionary
	qsort(dictionary, entries, sizeof(struct entry), compare);
}


int main()
{
	// Example dictionary
	struct entry dictionary[10] = {
	    {"aardvark", "a burrowing African mammal"},
	    {"ajar", "partially opened"},
	    {"abyss", "a bottomless pit"},
	    {"acumen", "mentally sharp; keen"},
	    {"addle", "to become confused"},
	    {"aerie", "a high nest"},
	    {"affix", "to append; attach"},
	    {"agar", "a jelly made from seaweed"},
	    {"ahoy", "a nautical call of greeting"},
	    {"aigrette", "an ornamental cluster of feathers"}};
	    

	int entries = 10;

	// Sort the dictionary
	dictionarySort(dictionary, entries);

	// Print sorted dictionary to verify
	for (int i = 0; i < entries; i++)
	{
		printf("%s: %s\n", dictionary[i].word, dictionary[i].definition);
	}

	return 0;
}