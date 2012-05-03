static int mq_attr_ok(..., struct mq_attr *attr)
{
    /*attr->mq_msgsize > 0 and attr->mq_maxmsg > 0*/
    nan unsigned long msg = attr->mq_maxmsg;
    nan unsigned long size = attr->mq_msgsize;
    if(isnan(msg * (size + sizeof(struct msg_msg *))))
        return 0;
    return 1;
}