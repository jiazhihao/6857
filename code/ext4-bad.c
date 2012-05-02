sbi->s_log_groups_per_flex = ...; /* from disk */
groups_per_flex = 1 << sbi->s_log_groups_per_flex;
/* patched check */
if (groups_per_flex < 2) {
	sbi->s_log_groups_per_flex = 0;
	return 1;
}
/* groups_per_flex is used as a divisor */
flex_group_count = ... / groups_per_flex;
