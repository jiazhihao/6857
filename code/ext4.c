static int ext4_split_extent(...);

static int ext4_ext_convert_to_initialized(...)
{
	unsigned int allocated;
	int err = 0;
	...
	allocated = ext4_split_extent(...);
	if (allocated < 0)
		err = allocated;
	return err ? err : allocated;
}
