/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED BY BPFTOOL! */
#ifndef __MINIMAL_BPF_SKEL_H__
#define __MINIMAL_BPF_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct minimal_bpf {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *bss;
		struct bpf_map *rodata;
	} maps;
	struct {
		struct bpf_program *handle_tp;
	} progs;
	struct {
		struct bpf_link *handle_tp;
	} links;
	struct minimal_bpf__bss {
		int my_pid;
	} *bss;
	struct minimal_bpf__rodata {
	} *rodata;

#ifdef __cplusplus
	static inline struct minimal_bpf *open(const struct bpf_object_open_opts *opts = nullptr);
	static inline struct minimal_bpf *open_and_load();
	static inline int load(struct minimal_bpf *skel);
	static inline int attach(struct minimal_bpf *skel);
	static inline void detach(struct minimal_bpf *skel);
	static inline void destroy(struct minimal_bpf *skel);
	static inline const void *elf_bytes(size_t *sz);
#endif /* __cplusplus */
};

static void
minimal_bpf__destroy(struct minimal_bpf *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
minimal_bpf__create_skeleton(struct minimal_bpf *obj);

static inline struct minimal_bpf *
minimal_bpf__open_opts(const struct bpf_object_open_opts *opts)
{
	struct minimal_bpf *obj;
	int err;

	obj = (struct minimal_bpf *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = minimal_bpf__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	minimal_bpf__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct minimal_bpf *
minimal_bpf__open(void)
{
	return minimal_bpf__open_opts(NULL);
}

static inline int
minimal_bpf__load(struct minimal_bpf *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct minimal_bpf *
minimal_bpf__open_and_load(void)
{
	struct minimal_bpf *obj;
	int err;

	obj = minimal_bpf__open();
	if (!obj)
		return NULL;
	err = minimal_bpf__load(obj);
	if (err) {
		minimal_bpf__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
minimal_bpf__attach(struct minimal_bpf *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
minimal_bpf__detach(struct minimal_bpf *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *minimal_bpf__elf_bytes(size_t *sz);

static inline int
minimal_bpf__create_skeleton(struct minimal_bpf *obj)
{
	struct bpf_object_skeleton *s;
	int err;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)	{
		err = -ENOMEM;
		goto err;
	}

	s->sz = sizeof(*s);
	s->name = "minimal_bpf";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 2;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps) {
		err = -ENOMEM;
		goto err;
	}

	s->maps[0].name = "minimal_.bss";
	s->maps[0].map = &obj->maps.bss;
	s->maps[0].mmaped = (void **)&obj->bss;

	s->maps[1].name = "minimal_.rodata";
	s->maps[1].map = &obj->maps.rodata;
	s->maps[1].mmaped = (void **)&obj->rodata;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs) {
		err = -ENOMEM;
		goto err;
	}

	s->progs[0].name = "handle_tp";
	s->progs[0].prog = &obj->progs.handle_tp;
	s->progs[0].link = &obj->links.handle_tp;

	s->data = (void *)minimal_bpf__elf_bytes(&s->data_sz);

	obj->skeleton = s;
	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return err;
}

static inline const void *minimal_bpf__elf_bytes(size_t *sz)
{
	*sz = 2264;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x58\x05\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x0e\0\
\x01\0\x85\0\0\0\x0e\0\0\0\x77\0\0\0\x20\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\xb7\x02\0\0\x1c\0\0\0\xbf\x03\0\0\0\0\0\0\x85\0\0\0\x06\0\0\0\xb7\0\0\0\0\
\0\0\0\x95\0\0\0\0\0\0\0\x44\x75\x61\x6c\x20\x42\x53\x44\x2f\x47\x50\x4c\0\0\0\
\0\x42\x50\x46\x20\x74\x72\x69\x67\x67\x65\x72\x65\x64\x20\x66\x72\x6f\x6d\x20\
\x50\x49\x44\x20\x25\x64\x2e\x0a\0\x9f\xeb\x01\0\x18\0\0\0\0\0\0\0\x10\x01\0\0\
\x10\x01\0\0\x2a\x01\0\0\0\0\0\0\0\0\0\x02\0\0\0\0\0\0\0\0\x01\0\0\x0d\x03\0\0\
\0\x01\0\0\0\x01\0\0\0\x05\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\x01\x09\0\0\0\x01\
\0\0\x0c\x02\0\0\0\xdb\0\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x01\0\0\0\0\0\0\0\x03\
\0\0\0\0\x05\0\0\0\x07\0\0\0\x0d\0\0\0\xe0\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\
\xf4\0\0\0\0\0\0\x0e\x06\0\0\0\x01\0\0\0\xfc\0\0\0\0\0\0\x0e\x03\0\0\0\x01\0\0\
\0\0\0\0\0\0\0\0\x0a\x05\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x0a\0\0\0\x07\0\0\0\
\x1c\0\0\0\x03\x01\0\0\0\0\0\x0e\x0b\0\0\0\0\0\0\0\x15\x01\0\0\x01\0\0\x0f\0\0\
\0\0\x09\0\0\0\0\0\0\0\x04\0\0\0\x1a\x01\0\0\x01\0\0\x0f\0\0\0\0\x0c\0\0\0\0\0\
\0\0\x1c\0\0\0\x22\x01\0\0\x01\0\0\x0f\0\0\0\0\x08\0\0\0\0\0\0\0\x0d\0\0\0\0\
\x63\x74\x78\0\x69\x6e\x74\0\x68\x61\x6e\x64\x6c\x65\x5f\x74\x70\0\x6b\x70\x72\
\x6f\x62\x65\x2f\x6e\x65\x77\x5f\x73\x6c\x61\x62\0\x2f\x68\x6f\x6d\x65\x2f\x77\
\x61\x6e\x67\x7a\x63\x2f\x44\x6f\x63\x75\x6d\x65\x6e\x74\x73\x2f\x46\x6c\x61\
\x6d\x65\x47\x72\x61\x70\x68\x2d\x66\x6f\x72\x2d\x6e\x65\x77\x2d\x64\x65\x66\
\x65\x6e\x73\x65\x2f\x65\x62\x70\x66\x2f\x70\x72\x6f\x6a\x65\x63\x74\x73\x2f\
\x6d\x69\x6e\x69\x6d\x61\x6c\x2e\x62\x70\x66\x2e\x63\0\x09\x69\x6e\x74\x20\x70\
\x69\x64\x20\x3d\x20\x62\x70\x66\x5f\x67\x65\x74\x5f\x63\x75\x72\x72\x65\x6e\
\x74\x5f\x70\x69\x64\x5f\x74\x67\x69\x64\x28\x29\x20\x3e\x3e\x20\x33\x32\x3b\0\
\x09\x62\x70\x66\x5f\x70\x72\x69\x6e\x74\x6b\x28\x22\x42\x50\x46\x20\x74\x72\
\x69\x67\x67\x65\x72\x65\x64\x20\x66\x72\x6f\x6d\x20\x50\x49\x44\x20\x25\x64\
\x2e\x5c\x6e\x22\x2c\x20\x70\x69\x64\x29\x3b\0\x09\x72\x65\x74\x75\x72\x6e\x20\
\x30\x3b\0\x63\x68\x61\x72\0\x5f\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\
\x5f\x54\x59\x50\x45\x5f\x5f\0\x4c\x49\x43\x45\x4e\x53\x45\0\x6d\x79\x5f\x70\
\x69\x64\0\x68\x61\x6e\x64\x6c\x65\x5f\x74\x70\x2e\x5f\x5f\x5f\x5f\x66\x6d\x74\
\0\x2e\x62\x73\x73\0\x2e\x72\x6f\x64\x61\x74\x61\0\x6c\x69\x63\x65\x6e\x73\x65\
\0\0\0\x9f\xeb\x01\0\x20\0\0\0\0\0\0\0\x14\0\0\0\x14\0\0\0\x4c\0\0\0\x60\0\0\0\
\0\0\0\0\x08\0\0\0\x13\0\0\0\x01\0\0\0\0\0\0\0\x04\0\0\0\x10\0\0\0\x13\0\0\0\
\x04\0\0\0\0\0\0\0\x23\0\0\0\x71\0\0\0\x0c\x34\0\0\x08\0\0\0\x23\0\0\0\x71\0\0\
\0\x27\x34\0\0\x10\0\0\0\x23\0\0\0\x9e\0\0\0\x02\x48\0\0\x38\0\0\0\x23\0\0\0\
\xd0\0\0\0\x02\x50\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x03\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x14\0\0\0\x01\0\x07\0\0\0\0\0\0\0\
\0\0\x1c\0\0\0\0\0\0\0\0\0\0\0\x03\0\x07\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x2b\
\0\0\0\x12\0\x03\0\0\0\0\0\0\0\0\0\x48\0\0\0\0\0\0\0\x87\0\0\0\x11\0\x05\0\0\0\
\0\0\0\0\0\0\x0d\0\0\0\0\0\0\0\x4b\0\0\0\x11\0\x06\0\0\0\0\0\0\0\0\0\x04\0\0\0\
\0\0\0\0\x10\0\0\0\0\0\0\0\x01\0\0\0\x03\0\0\0\xf0\0\0\0\0\0\0\0\x04\0\0\0\x06\
\0\0\0\x08\x01\0\0\0\0\0\0\x03\0\0\0\x03\0\0\0\x20\x01\0\0\0\0\0\0\x04\0\0\0\
\x05\0\0\0\x2c\0\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\x40\0\0\0\0\0\0\0\x04\0\0\0\
\x01\0\0\0\x50\0\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\x60\0\0\0\0\0\0\0\x04\0\0\0\
\x01\0\0\0\x70\0\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\x0d\x0e\x03\0\x2e\x74\x65\x78\
\x74\0\x2e\x72\x65\x6c\x2e\x42\x54\x46\x2e\x65\x78\x74\0\x68\x61\x6e\x64\x6c\
\x65\x5f\x74\x70\x2e\x5f\x5f\x5f\x5f\x66\x6d\x74\0\x2e\x62\x73\x73\0\x68\x61\
\x6e\x64\x6c\x65\x5f\x74\x70\0\x2e\x6c\x6c\x76\x6d\x5f\x61\x64\x64\x72\x73\x69\
\x67\0\x6c\x69\x63\x65\x6e\x73\x65\0\x6d\x79\x5f\x70\x69\x64\0\x2e\x73\x74\x72\
\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x2e\x72\x65\x6c\x6b\x70\x72\x6f\
\x62\x65\x2f\x6e\x65\x77\x5f\x73\x6c\x61\x62\0\x2e\x72\x6f\x64\x61\x74\x61\0\
\x2e\x72\x65\x6c\x2e\x42\x54\x46\0\x4c\x49\x43\x45\x4e\x53\x45\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x52\0\0\0\x03\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\xc3\x04\0\0\0\0\0\0\x8f\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x66\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\
\0\0\0\0\0\x48\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x62\0\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x30\x04\0\0\0\0\0\0\x10\
\0\0\0\0\0\0\0\x0d\0\0\0\x03\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x43\0\0\
\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x88\0\0\0\0\0\0\0\x0d\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x26\0\0\0\x08\0\0\0\x03\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x98\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x76\0\0\0\x01\0\0\0\x02\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x98\0\0\0\0\0\0\0\x1c\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x82\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb4\
\0\0\0\0\0\0\0\x52\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x7e\0\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\x04\0\0\0\0\0\
\0\x30\0\0\0\0\0\0\0\x0d\0\0\0\x08\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\
\x0b\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\x03\0\0\0\0\0\0\x80\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x07\0\0\0\x09\0\
\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x70\x04\0\0\0\0\0\0\x50\0\0\0\0\0\0\0\
\x0d\0\0\0\x0a\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x35\0\0\0\x03\x4c\xff\
\x6f\0\0\0\x80\0\0\0\0\0\0\0\0\0\0\0\0\xc0\x04\0\0\0\0\0\0\x03\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x5a\0\0\0\x02\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x88\x03\0\0\0\0\0\0\xa8\0\0\0\0\0\0\0\x01\0\0\0\x04\0\0\
\0\x08\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0";
}

#ifdef __cplusplus
struct minimal_bpf *minimal_bpf::open(const struct bpf_object_open_opts *opts) { return minimal_bpf__open_opts(opts); }
struct minimal_bpf *minimal_bpf::open_and_load() { return minimal_bpf__open_and_load(); }
int minimal_bpf::load(struct minimal_bpf *skel) { return minimal_bpf__load(skel); }
int minimal_bpf::attach(struct minimal_bpf *skel) { return minimal_bpf__attach(skel); }
void minimal_bpf::detach(struct minimal_bpf *skel) { minimal_bpf__detach(skel); }
void minimal_bpf::destroy(struct minimal_bpf *skel) { minimal_bpf__destroy(skel); }
const void *minimal_bpf::elf_bytes(size_t *sz) { return minimal_bpf__elf_bytes(sz); }
#endif /* __cplusplus */

__attribute__((unused)) static void
minimal_bpf__assert(struct minimal_bpf *s __attribute__((unused)))
{
#ifdef __cplusplus
#define _Static_assert static_assert
#endif
	_Static_assert(sizeof(s->bss->my_pid) == 4, "unexpected size of 'my_pid'");
#ifdef __cplusplus
#undef _Static_assert
#endif
}

#endif /* __MINIMAL_BPF_SKEL_H__ */
