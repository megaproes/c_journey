float strToFloat(const char float_str[])
{
	int i = 0, is_negative = 0;
	float result = 0.0f, divisor = 1.0f;

	// Handle negative numbers
	if (float_str[0] == '-')
	{
		is_negative = 1;
		i = 1;
	}

	// Process the part before the decimal point
	for (; float_str[i] >= '0' && float_str[i] <= '9'; ++i)
	{
		result = result * 10.0f + (float_str[i] - '0');
	}

	// Process the part after the decimal point
	if (float_str[i] == '.')
	{
		i++; // Move past the decimal point
		for (; float_str[i] >= '0' && float_str[i] <= '9'; ++i)
		{
			result = result * 10.0f + (float_str[i] - '0');
			divisor *= 10.0f;
		}
	}

	// Apply the divisor for decimals
	result /= divisor;

	// Return the result with correct sign
	return is_negative ? -result : result;
}

float strToFloat_old(const char float_str[])
{
	int i = 0, num_zeros = 0, is_negative = 0, is_after_dot = 0;
	float result = 0.0f, float_temp = 0.0f;

	if (float_str[0] == '-')
	{
		is_negative = 1;
		i = 1;
	}

	for (; float_str[i] >= '0' && float_str[i] <= '9' || float_str[i] == '.'; ++i)
	{
		if (float_str[i] == '.')
		{
			is_after_dot = 1;
			continue;
		}
		else if (is_after_dot)
			num_zeros++;

		float_temp = float_str[i] - '0';
		result = result * 10.0f + float_temp;
	}

	for (int i = 0, temp = 10; i < num_zeros; i++)
	{
		result /= temp;
	}

	if (is_negative)
		return result * -1;

	return result;
} // char str[] = "867.6921";