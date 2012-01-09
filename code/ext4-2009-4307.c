sbi->s_log_groups_per_flex = ...; /* from disk */
groups_per_flex = 1 << sbi->s_log_groups_per_flex;
flex_group_count = ... / groups_per_flex;
