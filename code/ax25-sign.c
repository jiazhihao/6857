#define IFNAMSIZ 16
static int ax25_setsockopt(...,
	char __user *optval, int optlen)
{
	char devname[IFNAMSIZ];
	/* consider optlen = 0xffffffff */
	/* optlen is treated as unsigned: $2^{32}-1$ */
	if (optlen < sizeof(int))
		return -EINVAL;
	/* optlen is treated as signed: $-1$ */
	if (optlen > IFNAMSIZ)
		optlen = IFNAMSIZ;
	copy_from_user(devname, optval, optlen);
	...
}
