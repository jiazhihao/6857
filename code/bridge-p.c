unsigned long maxnum0 = ...; /* read from userspace */ 
size_t size;
/* limit to 256 = 4096 / 16 */
if (maxnum0 > PAGE_SIZE / sizeof(struct __fdb_entry))
    maxnum1 = PAGE_SIZE / sizeof(struct __fdb_entry);
else
    maxnum1 = maxnum0;
size = maxnum1 * sizeof(struct __fdb_entry);
buf = kmalloc(size, GFP_USER);
