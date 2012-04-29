struct dcon_platform_data {
	...
	u8 (*read_status)(void);
};

struct dcon_platform_data *pdata = ...;
int status = pdata->read_status();
if (status == -1)
	return IRQ_NONE;
