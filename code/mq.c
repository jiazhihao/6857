static int mq_attr_ok(..., struct mq_attr *attr)
{
    /* attr->mq_msgsize > 0 and attr->mq_maxmsg > 0 */
    if (attr->mq_msgsize > ULONG_MAX/attr->mq_maxmsg)
        return 0;
    unsigned long size, lhs, rhs;
    size = attr->mq_msgsize + sizeof(struct msg_msg*);
    lhs = attr->mq_maxmsg * size;
    rhs = attr->mq_maxmsg * attr->mq_msgsize;
    if (lhs < rhs)
        return 0;
    return 1;
}