// change the type of maxmsg and msgsize to `nan long'
if (isnan(maxmsg * (msgsize + sizeof(void *))))
	return 0;
return 1;
