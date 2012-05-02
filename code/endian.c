/* le32_to_cpu returns an unsigned integer */
int status = le32_to_cpu(lp->rfd_cur->fd.FDStat);
if (status & 0x4000) { ... }
