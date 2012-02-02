/* function parameter: __u32 key_len */
/* patched check */
if (INT_MAX - key_len < sizeof(struct sctp_auth_bytes))
	return NULL;
key = kmalloc(sizeof(struct sctp_auth_bytes)
				+ key_len, gfp);
