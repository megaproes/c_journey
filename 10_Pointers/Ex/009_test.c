#include <cmocka.h>
#include <stdio.h>
#include <string.h>
#include "009.c" // Assuming this is where your function is implemented

// Mock the input using fmemopen
static void test_readLine(void **state)
{
	char buffer[100];				    // Use a buffer to store the result
	const char *input = "Hello, world!\n"; // The input string to simulate stdin

	// Use fmemopen to simulate stdin with our input string
	FILE *input_stream = fmemopen((void *)input, strlen(input), "r");
	assert_non_null(input_stream); // Make sure the stream was opened successfully
	stdin = input_stream;		 // Redirect stdin to the simulated input stream

	// Call the readLine function
	readLine(buffer);

	// Assert the result
	assert_string_equal(buffer, "Hello, world!");

	// Close the input stream
	fclose(input_stream);
}

int main(void)
{
	const struct CMUnitTest tests[] = {
	    cmocka_unit_test(test_readLine),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
