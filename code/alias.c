/* arg is a function parameter
 * user_ptr points to a user-space list */
if (arg->count < 1 || arg->count > 128)
	return -EINVAL;
int *klist = kmalloc(arg->count * sizeof(int), ...);
if (!klist)
	return -ENOMEM;
ret = copy_from_user(klist, user_ptr,
                     arg->count * sizeof(int));
