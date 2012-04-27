struct shrinker *shrinker = ...;
unsigned long long delta = ...;
unsigned long total_scan = ...;
unsigned long max_pass = ...;
total_scan += delta;
if (total_scan < 0) {
	printk(KERN_ERR "shrink_slab: %pF negative "
	       "objects to delete nr=%ld\n",
	       shrinker->shrink, total_scan);
	total_scan = max_pass;
}
