struct dcon_platform_data {
	...
	u8 (*read_status)(void);
};
/* ->read_status() implementation */
static u8 dcon_read_status_xo_1_5(u8 *status)
{
	if (!dcon_was_irq())
		return -1;
	...
}
irqreturn_t dcon_interrupt(int irq, void *id)
{
	struct dcon_platform_data *pdata = ...;
	int status = pdata->read_status();
	if (status == -1)
		return IRQ_NONE;
	...
}
