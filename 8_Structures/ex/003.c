#include <stdlib.h>
#include <stdio.h>

struct time
{
	int hours;
	int minutes;
	int seconds;
};
struct time elapsed_time(struct time time1, struct time time2)
{
	struct time elapsed;

	elapsed.hours = abs(time2.hours - time1.hours);
	if ((time2.minutes - time1.minutes < 0 && time1.hours < time2.hours) || (time1.minutes - time2.minutes < 0 && time2.hours < time1.hours)) 
	{
		elapsed.hours--;
		elapsed.minutes = 60 - abs(time2.minutes - time1.minutes);
	}
	else
	{
		elapsed.minutes = time2.minutes - time1.minutes >= 0 ? time2.minutes - time1.minutes : time1.minutes - time2.minutes;
	}

	if ((time2.seconds - time1.seconds < 0 && time1.hours < time2.hours) || (time1.seconds - time2.seconds < 0 && time2.hours < time1.hours))
	{
		if (elapsed.minutes != 0)
		{
			elapsed.minutes--;
			elapsed.seconds = 60 - abs(time2.seconds - time1.seconds);
		}
		else
		{
			if (elapsed.hours != 0)
			{
				elapsed.hours--;
				elapsed.minutes = 59;
			}
			elapsed.seconds = 60 - abs(time2.seconds - time1.seconds);
		}
	}
	else
	{
		elapsed.seconds = 60 - abs(time2.seconds - time1.seconds);
	}

	return elapsed;
}

int main(int argc, char const *argv[])
{
	struct time time1;
	printf("Enter time1 HH:MIN:SEC: ");
	scanf("%d:%d:%d", &time1.hours, &time1.minutes, &time1.seconds);

	struct time time2;
	printf("Enter time2 HH:MIN:SEC: ");
	scanf("%d:%d:%d", &time2.hours, &time2.minutes, &time2.seconds);

	struct time elapsed = elapsed_time(time1, time2);
	printf("Elapsed time is: %.2i:%.2i:%.2i\n", elapsed.hours, elapsed.minutes, elapsed.seconds);
	return 0;
}
