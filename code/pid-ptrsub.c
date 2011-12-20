struct pid_namespace {
	int kref;
	struct pidmap pidmap[PIDMAP_ENTRIES];
	...
};
struct pid_namespace *pid_ns = ...;
unsigned int last = ...;
struct pidmap *map =
	&pid_ns->pidmap[(last + 1)/BITS_PER_PAGE];
int off = map - pid_ns->pidmap;
