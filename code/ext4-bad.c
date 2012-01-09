
	sbi->s_log_groups_per_flex = ...; /* from disk */
	groups_per_flex = 1 << sbi->s_log_groups_per_flex;

	if (groups_per_flex < 2) {
		sbi->s_log_groups_per_flex = 0;
		return 1;
	}

	flex_group_count = ... / groups_per_flex;
