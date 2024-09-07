#include <stdlib.h>
#include <stdio.h>

struct time
{
	int hours;
	int minutes;
	int seconds;
};

// Function to convert time to total seconds since the start of the day
int time_to_seconds(struct time t)
{
	return t.hours * 3600 + t.minutes * 60 + t.seconds;
}

// Function to convert total seconds back to a time structure
struct time seconds_to_time(int total_seconds)
{
	struct time t;
	t.hours = total_seconds / 3600;
	total_seconds %= 3600;
	t.minutes = total_seconds / 60;
	t.seconds = total_seconds % 60;
	return t;
}

// Function to compute the minimum elapsed time between two times
struct time elapsed_time(struct time time1, struct time time2)
{
	int seconds_in_a_day = 24 * 3600;

	// Convert both times to total seconds since the start of the day
	int time1_in_seconds = time_to_seconds(time1);
	int time2_in_seconds = time_to_seconds(time2);

	// Compute the elapsed time in both directions
	int elapsed_seconds_forward = (time2_in_seconds >= time1_in_seconds)
							    ? time2_in_seconds - time1_in_seconds
							    : (seconds_in_a_day - time1_in_seconds) + time2_in_seconds;

	int elapsed_seconds_backward = (time1_in_seconds >= time2_in_seconds)
								? time1_in_seconds - time2_in_seconds
								: (seconds_in_a_day - time2_in_seconds) + time1_in_seconds;

	// Return the shorter of the two elapsed times
	int elapsed_seconds = (elapsed_seconds_forward <= elapsed_seconds_backward)
						 ? elapsed_seconds_forward
						 : elapsed_seconds_backward;

	return seconds_to_time(elapsed_seconds);
}

int main()
{
	struct time time1, time2;

	// Input the first time
	printf("Enter time1 (HH:MM:SS): ");
	scanf("%d:%d:%d", &time1.hours, &time1.minutes, &time1.seconds);

	// Input the second time
	printf("Enter time2 (HH:MM:SS): ");
	scanf("%d:%d:%d", &time2.hours, &time2.minutes, &time2.seconds);

	// Calculate the elapsed time
	struct time elapsed = elapsed_time(time1, time2);
	printf("Elapsed time is: %.2i:%.2i:%.2i\n", elapsed.hours, elapsed.minutes, elapsed.seconds);

	return 0;
}
