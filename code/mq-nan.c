// declare maxmsg and msgsize as `nan' integers
if (isnan(maxmsg * msgsize + maxmsg * sizeof(void *)))
	return 0;
return 1;
