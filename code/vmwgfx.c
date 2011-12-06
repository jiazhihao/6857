// "data" is passed from userspace.
struct drm_vmw_update_layout_arg *arg = data;
struct drm_vmw_rect *rects = 0;
unsigned size;
int i, ret = 0;
// Check arg->num_outputs.
if (!arg->num_outputs)
	goto out;
// Compute allocation size for "rects".
// sizeof(struct drm_vmw_rect) = 16.
size = arg->num_outputs * sizeof(struct drm_vmw_rect);
// Allocate memory.
rects = kzalloc(size, GFP_KERNEL);
if (unlikely(!rects)) {
	ret = -ENOMEM;
	goto out;
}
// Validate input data.
for (i = 0; i < arg->num_outputs; ++i) {
	if (rects[i]->x < 0 || rects[i]->y < 0) {
		ret -EINVAL;
		goto out;
	}
}
// Clean up. 
out:
	kfree(rects);
	return ret;
