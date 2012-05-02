static int mq_attr_ok(struct ipc_namespace *ipc_ns, struct mq_attr *attr)
{
    .../* guarantee attr->mq_msgsize > 0 and attr->mq_maxmsg > 0*/
    if (attr->mq_msgsize > ULONG_MAX/attr->mq_maxmsg)
        return 0;
    if ((unsigned long)(attr->mq_maxmsg * (attr->mq_msgsize
                                           + sizeof (struct msg_msg *))) <
        (unsigned long)(attr->mq_maxmsg * attr->mq_msgsize))
        return 0;
    return 1;
}