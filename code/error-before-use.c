unsigned size = x * y;
if (x > UINT_MAX / y)
	return -1;
... = malloc(size);
