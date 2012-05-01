void *malloc(nan size_t size)
{
	size_t bytes = unnan(size, SIZE_MAX);
	return libc_malloc(bytes);
}
