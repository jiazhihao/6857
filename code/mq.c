/* overflow checks for
 *   maxmsg * msgsize + maxmsg * sizeof(void *)
 * assume
 *   $\cc{maxmsg} > 0 \land \cc{maxmsg} \leq 2^{15}$
 *   $\cc{msgsize} > 0 \land \cc{msgsize} \leq 2^{20}$
 */
if (msgsize > ULONG_MAX / maxmsg)
	return 0;
if (maxmsg * (msgsize + sizeof(void *))
    < maxmsg * msgsize)
	return 0;
return 1;
