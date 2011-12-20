/* maxnum is read from userspace */
unsigned long maxnum = ...;
/* sizeof(struct __fdb_entry) = 16 */
size_t size = maxnum * sizeof(struct __fdb_entry);
/* PAGE_SIZE = 4096 */
if (size > PAGE_SIZE) {
	/* limit to 4096 */
	size = PAGE_SIZE;
	/* limit to 256 = 4096 / 16 */
	maxnum = PAGE_SIZE / sizeof(struct __fdb_entry);
}
buf = kmalloc(size, GFP_USER);
if (!buf)
	return -ENOMEM;
/* write to buf[0..maxnum-1] */
