	long points; /* int points; */
	...
	points = get_mm_rss(p->mm) + p->mm->nr_ptes;
	points += get_mm_counter(p->mm, MM_SWAPENTS);

	points *= 1000;
	points /= totalpages;
