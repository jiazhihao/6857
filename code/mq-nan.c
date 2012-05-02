static int mq_attr_ok(struct ipc_namespace *ipc_ns, struct mq_attr *attr)
{
    .../* guarantee attr->mq_msgsize > 0 and attr->mq_maxmsg > 0*/
    nan unsigned long maxmsg = attr->mq_maxmsg, msgsize = attr->mq_msgsize;
    if(isnan(maxmsg * (msgsize + sizeof (struct msg_msg *))))
        return 0;
    return 1;
}