/* overflow checks for
 *   maxmsg * msgsize + maxmsg * sizeof(void *)
 * assume 0 < maxmsg $\leq$ $2^{15}$ $\land$ 0 < msgsize $<$ $2^{31}$
 */
if (msgsize > ULONG_MAX / maxmsg)
	return 0;
if (maxmsg * (msgsize + sizeof(void *))
    < maxmsg * msgsize)
	return 0;
return 1;
