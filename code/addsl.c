signed long addsl(signed long lhs, signed long rhs) {
  errno = 0;
  if ( (((lhs+rhs)^lhs) & ((lhs+rhs)^rhs))
        >> (sizeof(int)*CHAR_BIT-1) ) {
    error_handler("OVERFLOW ERROR", NULL, EOVERFLOW);
    errno = EINVAL;
  }
  return lhs+rhs;
}
