#define IFNAMSIZ 16
static int ax25_setsockopt(...,
	char __user *optval, int optlen)
{
	char devname[IFNAMSIZ];
	...
	/* optlen will be silently converted to unsigned */
	if (optlen < sizeof(int))
		return -EINVAL;
	/* optlen is treated as signed here */
	if (optlen > IFNAMSIZ)
		optlen = IFNAMSIZ;
	copy_from_user(devname, optval, optlen);
	...
}
