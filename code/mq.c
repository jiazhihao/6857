static int mq_attr_ok(struct ipc_namespace *ipc_ns, struct mq_attr *attr)
{
    if (attr->mq_maxmsg <= 0 || attr->mq_msgsize <= 0)
        return 0;
    ...../*not change attr->mq_maxmsg and attr->mq_msgsize*/
    /* check for overflow */
    if (attr->mq_msgsize > ULONG_MAX/attr->mq_maxmsg)
        return 0;
    if ((unsigned long)(attr->mq_maxmsg * (attr->mq_msgsize
                                           + sizeof (struct msg_msg *))) <
        (unsigned long)(attr->mq_maxmsg * attr->mq_msgsize))
        return 0;
    return 1;
}

