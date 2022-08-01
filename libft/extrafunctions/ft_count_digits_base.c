int	ft_count_digits_base(long long int number, int base)
{
	int	index;

	index = 0;
	if (!number)
		return (1);
	// invert_number_signal(&number);
	while (number != 0)
	{
		index++;
		number /= base;
	}
	return (index);
}
