if (maxnum > PAGE_SIZE / sizeof(struct __fdb_entry))
    maxnum = PAGE_SIZE / sizeof(struct __fdb_entry);
size = maxnum * sizeof(struct __fdb_entry);
buf = kmalloc(size, GFP_USER);
...
