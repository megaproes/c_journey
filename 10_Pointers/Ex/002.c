struct entry
{
	int value;
	struct entry *next;
};
// Function to insert newEntry after afterEntry
void insertEntry(struct entry *newEntry, struct entry *afterEntry)
{
	// Check if afterEntry and newEntry are not NULL
	if (newEntry == 0 || afterEntry == 0)
	{
		return; // You could print an error message or handle this case
	}

	// Insert the new entry into the list
	struct entry *temp = afterEntry->next;
	afterEntry->next = newEntry;
	newEntry->next = temp;
}
