# Security audit: git/git

Date: 2026-11-26 | Auditor: [mutsuumii](https://github.com/mutsuumii)

## Summary

Found 181 issue(s): 20 critical, 161 high.

## Findings

### 1. [HIGH] Use-after-free pattern

**CWE-416** | `log-tree.c` line 1080

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
commit_list_free(bases);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 2. [HIGH] Missing NULL check after allocation

**CWE-476** | `log-tree.c` line 999

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
o->additional_path_headers = xmalloc(sizeof(struct strmap));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 3. [HIGH] Missing NULL check after allocation

**CWE-476** | `log-tree.c` line 1120

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
opt->follow_pathspec_slab = xmalloc(sizeof(*opt->follow_pathspec_slab));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 4. [HIGH] Missing NULL check after allocation

**CWE-476** | `log-tree.c` line 1127

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
*slot = xstrdup(path);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 5. [HIGH] Missing NULL check after allocation

**CWE-476** | `t/unit-tests/u-mem-pool.c` line 8

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
char *buffer = mem_pool_calloc(&pool, 1, size);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 6. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/push.c` line 402

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(anon_url);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 7. [HIGH] Use-after-free pattern

**CWE-416** | `commit-graph.c` line 429

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(graph);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 8. [HIGH] Use-after-free pattern

**CWE-416** | `commit-graph.c` line 495

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(graph);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 9. [HIGH] Use-after-free pattern

**CWE-416** | `commit-graph.c` line 523

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(graph_name);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 10. [HIGH] Use-after-free pattern

**CWE-416** | `commit-graph.c` line 682

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(graph_name);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 11. [HIGH] Use-after-free pattern

**CWE-416** | `commit-graph.c` line 689

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
commit_graph_free(g);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 12. [HIGH] Use-after-free pattern

**CWE-416** | `commit-graph.c` line 705

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(oids);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 13. [HIGH] Use-after-free pattern

**CWE-416** | `commit-graph.c` line 727

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(chain_file);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 14. [HIGH] Use-after-free pattern

**CWE-416** | `commit-graph.c` line 1888

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(sorted_commits);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 15. [HIGH] Use-after-free pattern

**CWE-416** | `commit-graph.c` line 1962

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(p);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 16. [HIGH] Use-after-free pattern

**CWE-416** | `commit-graph.c` line 1968

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(p);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 17. [HIGH] Use-after-free pattern

**CWE-416** | `commit-graph.c` line 2123

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(lock_name);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 18. [HIGH] Use-after-free pattern

**CWE-416** | `commit-graph.c` line 2251

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(graph_name);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 19. [HIGH] Use-after-free pattern

**CWE-416** | `commit-graph.c` line 2332

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(old_graph_name);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 20. [HIGH] Use-after-free pattern

**CWE-416** | `commit-graph.c` line 2499

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(chain_file_name);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 21. [HIGH] Use-after-free pattern

**CWE-416** | `commit-graph.c` line 2950

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(g);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 22. [HIGH] Missing NULL check after allocation

**CWE-476** | `commit-graph.c` line 222

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
struct commit_graph *g = xcalloc(1, sizeof(*g));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 23. [HIGH] Missing NULL check after allocation

**CWE-476** | `commit-graph.c` line 369

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
g->bloom_filter_settings = xmalloc(sizeof(struct bloom_filter_settings));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 24. [HIGH] Missing NULL check after allocation

**CWE-476** | `commit-graph.c` line 2208

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
char *new_base_hash = xstrdup(oid_to_hex(&ctx->new_base_graph->oid));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 25. [HIGH] Missing NULL check after allocation

**CWE-476** | `commit-graph.c` line 2256

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
xstrdup(hash_to_hex_algop(file_hash, ctx->r->hash_algo));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 26. [HIGH] Missing NULL check after allocation

**CWE-476** | `commit-graph.c` line 2340

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
ctx->commit_graph_filenames_after[i] = xstrdup(ctx->commit_graph_filenames_before[i]);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 27. [HIGH] Missing NULL check after allocation

**CWE-476** | `commit-graph.c` line 2347

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
ctx->commit_graph_hash_after[i] = xstrdup(oid_to_hex(&g->oid));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 28. [HIGH] Missing NULL check after allocation

**CWE-476** | `commit-graph.c` line 2463

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
ctx->base_graph_name = xstrdup(ctx->new_base_graph->filename);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 29. [HIGH] Missing NULL check after allocation

**CWE-476** | `commit-graph.c` line 2627

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
ctx.commit_graph_filenames_before[--i] = xstrdup(chain->filename);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 30. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/interpret-trailers.c` line 57

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(item);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 31. [HIGH] Missing NULL check after allocation

**CWE-476** | `builtin/interpret-trailers.c` line 75

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
item = xmalloc(sizeof(*item));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 32. [HIGH] Use-after-free pattern

**CWE-416** | `hash.c` line 282

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(ctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 33. [HIGH] Missing NULL check after allocation

**CWE-476** | `hash.c` line 277

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
return xmalloc(sizeof(struct git_hash_ctx));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 34. [HIGH] Use-after-free pattern

**CWE-416** | `odb/streaming.c` line 197

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(st);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 35. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/merge-base.c` line 20

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
commit_list_free(result);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 36. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/merge-base.c` line 33

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
commit_list_free(result);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 37. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/merge-base.c` line 76

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
commit_list_free(revs);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 38. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/merge-base.c` line 90

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
commit_list_free(revs);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 39. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/merge-base.c` line 91

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
commit_list_free(result);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 40. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/merge-base.c` line 94

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
commit_list_free(revs);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 41. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/merge-base.c` line 106

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
commit_list_free(result);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 42. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/merge-base.c` line 208

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(rev);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 43. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/bugreport.c` line 193

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(prefixed_filename);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 44. [HIGH] Use-after-free pattern

**CWE-416** | `reflog.c` line 92

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(tmp);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 45. [HIGH] Use-after-free pattern

**CWE-416** | `reflog.c` line 564

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(ref);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 46. [HIGH] Use-after-free pattern

**CWE-416** | `compat/regex/regex.c` line 33

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
# define regfree(preg) __regfree (preg)
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 47. [HIGH] Use-after-free pattern

**CWE-416** | `compat/simple-ipc/ipc-shared.c` line 27

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ipc_server_free(server_data);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 48. [HIGH] Use-after-free pattern

**CWE-416** | `stable-qsort.c` line 55

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(tmp);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 49. [HIGH] Missing NULL check after allocation

**CWE-476** | `stable-qsort.c` line 53

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
tmp = xmalloc(size);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 50. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/last-modified.c` line 206

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(ent);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 51. [HIGH] Use-after-free pattern

**CWE-416** | `negotiator/skipping.c` line 209

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(entry);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 52. [HIGH] Use-after-free pattern

**CWE-416** | `negotiator/skipping.c` line 259

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(entry);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 53. [HIGH] Integer overflow in size calculation

**CWE-190** | `mem-pool.h` line 42

Arithmetic in allocator argument can overflow to a small value, causing under-allocation and subsequent heap overflow.

```
void *mem_pool_calloc(struct mem_pool *pool, size_t count, size_t size);
```

**Fix:** Validate sizes before arithmetic. Use calloc(n, size) for n*size. Check: if (n > SIZE_MAX / size) abort().
---

### 54. [HIGH] Missing NULL check after allocation

**CWE-476** | `mem-pool.h` line 42

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
void *mem_pool_calloc(struct mem_pool *pool, size_t count, size_t size);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 55. [HIGH] Missing NULL check after allocation

**CWE-476** | `mem-pool.h` line 47

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
char *mem_pool_strdup(struct mem_pool *pool, const char *str);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 56. [HIGH] Use-after-free pattern

**CWE-416** | `xdiff/xdiff.h` line 119

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
#define xdl_free(ptr) free(ptr)
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 57. [CRITICAL] Format string vulnerability

**CWE-134** | `compat/hstrerror.c` line 19

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
snprintf(buffer, sizeof(buffer), "Name resolution error %d", err);
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 58. [CRITICAL] Format string vulnerability

**CWE-134** | `http-backend.c` line 86

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
n = vsnprintf(buffer, sizeof(buffer), fmt, args);
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 59. [HIGH] Use-after-free pattern

**CWE-416** | `http-backend.c` line 217

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(buf);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 60. [HIGH] Use-after-free pattern

**CWE-416** | `http-backend.c` line 218

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(p);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 61. [HIGH] Use-after-free pattern

**CWE-416** | `http-backend.c` line 321

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(buf);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 62. [HIGH] Use-after-free pattern

**CWE-416** | `http-backend.c` line 359

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(buf);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 63. [HIGH] Use-after-free pattern

**CWE-416** | `http-backend.c` line 444

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(full_request);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 64. [HIGH] Use-after-free pattern

**CWE-416** | `http-backend.c` line 455

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(buf);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 65. [HIGH] Use-after-free pattern

**CWE-416** | `http-backend.c` line 810

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(dir);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 66. [HIGH] Use-after-free pattern

**CWE-416** | `http-backend.c` line 820

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(cmd_arg);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 67. [HIGH] Missing NULL check after allocation

**CWE-476** | `http-backend.c` line 193

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
char *buf = xmalloc(buf_alloc);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 68. [HIGH] Missing NULL check after allocation

**CWE-476** | `http-backend.c` line 311

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
unsigned char *buf = xmalloc(alloc);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 69. [HIGH] Missing NULL check after allocation

**CWE-476** | `http-backend.c` line 356

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
buf = xmalloc(req_len);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 70. [HIGH] Missing NULL check after allocation

**CWE-476** | `http-backend.c` line 714

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
return xstrdup(path);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 71. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/commit-tree.c` line 157

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
commit_list_free(parents);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 72. [HIGH] Use-after-free pattern

**CWE-416** | `xdiff-interface.c` line 282

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(buffer);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 73. [HIGH] Use-after-free pattern

**CWE-416** | `xdiff-interface.c` line 296

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(regs);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 74. [HIGH] Missing NULL check after allocation

**CWE-476** | `xdiff-interface.c` line 187

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
ptr->ptr = xstrdup("");
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 75. [HIGH] Missing NULL check after allocation

**CWE-476** | `xdiff-interface.c` line 257

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
regs = xecfg->find_func_priv = xmalloc(sizeof(struct ff_regs));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 76. [CRITICAL] Format string vulnerability

**CWE-134** | `t/helper/test-lazy-init-name-hash.c` line 57

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
printf("name %08x %s\n", ce->ent.hash, ce->name);
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 77. [HIGH] Missing NULL check after allocation

**CWE-476** | `string-list.c` line 223

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
list->strdup_strings ? xstrdup(string) : (char *)string);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 78. [CRITICAL] Format string vulnerability

**CWE-134** | `t/helper/test-read-graph.c` line 30

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
printf(" commit_metadata");
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 79. [CRITICAL] Format string vulnerability

**CWE-134** | `t/helper/test-read-graph.c` line 32

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
printf(" generation_data");
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 80. [CRITICAL] Format string vulnerability

**CWE-134** | `t/helper/test-read-graph.c` line 34

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
printf(" generation_data_overflow");
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 81. [CRITICAL] Format string vulnerability

**CWE-134** | `t/helper/test-read-graph.c` line 40

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
printf(" bloom_data");
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 82. [CRITICAL] Format string vulnerability

**CWE-134** | `t/helper/test-read-graph.c` line 50

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
printf(" read_generation_data");
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 83. [HIGH] Use-after-free pattern

**CWE-416** | `t/helper/test-read-graph.c` line 122

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
commit_graph_free(graph);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 84. [HIGH] Integer overflow in size calculation

**CWE-190** | `compat/regex/regex_internal.h` line 472

Arithmetic in allocator argument can overflow to a small value, causing under-allocation and subsequent heap overflow.

```
#define re_malloc(t,n) ((t *) malloc ((n) * sizeof (t)))
```

**Fix:** Validate sizes before arithmetic. Use calloc(n, size) for n*size. Check: if (n > SIZE_MAX / size) abort().
---

### 85. [HIGH] Integer overflow in size calculation

**CWE-190** | `compat/regex/regex_internal.h` line 474

Arithmetic in allocator argument can overflow to a small value, causing under-allocation and subsequent heap overflow.

```
#define re_realloc(p,t,n) ((p != NULL) ? (t *) realloc (p,(n)*sizeof(t)) : (t *) calloc(n,sizeof(t)))
```

**Fix:** Validate sizes before arithmetic. Use calloc(n, size) for n*size. Check: if (n > SIZE_MAX / size) abort().
---

### 86. [HIGH] Use-after-free pattern

**CWE-416** | `compat/regex/regex_internal.h` line 475

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
#define re_free(p) free (p)
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 87. [HIGH] Use-after-free pattern

**CWE-416** | `compat/regex/regex_internal.h` line 705

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
#define re_node_set_free(set) re_free ((set)->elems)
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 88. [HIGH] Use-after-free pattern

**CWE-416** | `tools/coccinelle/tests/free.c` line 10

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(v);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 89. [CRITICAL] Code injection via eval()

**CWE-95** | `gitweb/static/js/lib/common-lib.js` line 217

eval() with dynamic input runs arbitrary JavaScript.

```
// perhaps str = eval('"'+str+'"'); would be enough?
```

**Fix:** Use JSON.parse() for data. Pass function references, not strings, to setTimeout.
---

### 90. [HIGH] Use-after-free pattern

**CWE-416** | `packfile-list.c` line 11

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(e);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 91. [HIGH] Missing NULL check after allocation

**CWE-476** | `packfile-list.c` line 50

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
entry = xmalloc(sizeof(*entry));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 92. [HIGH] Missing NULL check after allocation

**CWE-476** | `packfile-list.c` line 67

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
entry = xmalloc(sizeof(*entry));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 93. [CRITICAL] Format string vulnerability

**CWE-134** | `builtin/merge.c` line 1792

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
printf(_("Trying merge strategy %s...\n"),
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 94. [CRITICAL] Format string vulnerability

**CWE-134** | `builtin/merge.c` line 1859

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
printf(_("Using the %s strategy to prepare resolving by hand.\n"),
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 95. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/merge.c` line 637

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(found_ref);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 96. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/merge.c` line 658

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(argv);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 97. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/merge.c` line 673

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(branch_mergeoptions);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 98. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/merge.c` line 837

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
commit_list_free(reversed);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 99. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/merge.c` line 1012

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
commit_list_free(parents);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 100. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/merge.c` line 1028

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
commit_list_free(common);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 101. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/merge.c` line 1041

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
commit_list_free(parents);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 102. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/merge.c` line 1203

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
commit_list_free(remoteheads);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 103. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/merge.c` line 1361

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(tag_ref);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 104. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/merge.c` line 1631

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(list);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 105. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/merge.c` line 1635

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(list);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 106. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/merge.c` line 1882

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
commit_list_free(common);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 107. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/merge.c` line 1883

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
commit_list_free(remoteheads);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 108. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/merge.c` line 1886

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(branch_to_free);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 109. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/merge.c` line 1887

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(argv_to_free);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 110. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/merge.c` line 1888

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(pull_twohead);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 111. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/merge.c` line 1889

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(pull_octopus);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 112. [HIGH] Missing NULL check after allocation

**CWE-476** | `builtin/merge.c` line 225

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
ret->name = xstrdup(name);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 113. [HIGH] Missing NULL check after allocation

**CWE-476** | `builtin/merge.c` line 674

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
branch_mergeoptions = xstrdup(v);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 114. [HIGH] Missing NULL check after allocation

**CWE-476** | `builtin/merge.c` line 1113

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
args = xcalloc(st_add(branch->merge_nr, 1), sizeof(char *));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 115. [CRITICAL] Format string vulnerability

**CWE-134** | `t/helper/test-submodule-config.c` line 62

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
printf("Submodule name: '%s' for path '%s'\n", submodule->name,
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 116. [HIGH] Use-after-free pattern

**CWE-416** | `t/helper/test-submodule-config.c` line 68

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
submodule_free(the_repository);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 117. [CRITICAL] Format string vulnerability

**CWE-134** | `setup.c` line 3129

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
xsnprintf(buf, sizeof(buf), "0%o", -repo_settings_get_shared_repository(repo));
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 118. [HIGH] Use-after-free pattern

**CWE-416** | `setup.c` line 128

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(sanitized);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 119. [HIGH] Use-after-free pattern

**CWE-416** | `setup.c` line 132

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(sanitized);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 120. [HIGH] Use-after-free pattern

**CWE-416** | `setup.c` line 140

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(sanitized);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 121. [HIGH] Use-after-free pattern

**CWE-416** | `setup.c` line 165

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(r);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 122. [HIGH] Use-after-free pattern

**CWE-416** | `setup.c` line 190

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(to_free);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 123. [HIGH] Use-after-free pattern

**CWE-416** | `setup.c` line 194

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(to_free);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 124. [HIGH] Use-after-free pattern

**CWE-416** | `setup.c` line 977

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(dir);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 125. [HIGH] Use-after-free pattern

**CWE-416** | `setup.c` line 1055

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(buf);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 126. [HIGH] Use-after-free pattern

**CWE-416** | `setup.c` line 1086

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(path);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 127. [HIGH] Use-after-free pattern

**CWE-416** | `setup.c` line 1203

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(core_worktree);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 128. [HIGH] Use-after-free pattern

**CWE-416** | `setup.c` line 1232

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(gitfile);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 129. [HIGH] Use-after-free pattern

**CWE-416** | `setup.c` line 1253

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(to_free);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 130. [HIGH] Use-after-free pattern

**CWE-416** | `setup.c` line 1296

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(gitdir);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 131. [HIGH] Use-after-free pattern

**CWE-416** | `setup.c` line 1400

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(normalized);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 132. [HIGH] Use-after-free pattern

**CWE-416** | `setup.c` line 1422

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(allowed);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 133. [HIGH] Use-after-free pattern

**CWE-416** | `setup.c` line 1737

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(gitdir_path);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 134. [HIGH] Use-after-free pattern

**CWE-416** | `setup.c` line 1738

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(gitfile);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 135. [HIGH] Use-after-free pattern

**CWE-416** | `setup.c` line 2484

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(to_free);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 136. [HIGH] Use-after-free pattern

**CWE-416** | `setup.c` line 2634

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(ref);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 137. [HIGH] Use-after-free pattern

**CWE-416** | `setup.c` line 2642

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(to_free);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 138. [HIGH] Use-after-free pattern

**CWE-416** | `setup.c` line 2866

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(str);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 139. [HIGH] Use-after-free pattern

**CWE-416** | `setup.c` line 3142

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(original_git_dir);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 140. [HIGH] Missing NULL check after allocation

**CWE-476** | `setup.c` line 597

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
data->work_tree = xstrdup(value);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 141. [HIGH] Missing NULL check after allocation

**CWE-476** | `setup.c` line 625

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
data->partial_clone = xstrdup(value);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 142. [HIGH] Missing NULL check after allocation

**CWE-476** | `setup.c` line 1136

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
r->gitdir = xstrdup(gitdir);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 143. [HIGH] Missing NULL check after allocation

**CWE-476** | `setup.c` line 1161

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
gitfile = xstrdup(gitfile);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 144. [HIGH] Missing NULL check after allocation

**CWE-476** | `setup.c` line 1292

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
char *gitdir = offset == cwd->len ? xstrdup(".") : xmemdupz(cwd->buf, offset);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 145. [HIGH] Missing NULL check after allocation

**CWE-476** | `setup.c` line 1686

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
gitdir_path = xstrdup(dir->buf);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 146. [HIGH] Missing NULL check after allocation

**CWE-476** | `setup.c` line 1706

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
gitfile = xstrdup(dir->buf);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 147. [HIGH] Missing NULL check after allocation

**CWE-476** | `setup.c` line 2179

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
repo->prefix = xstrdup(prefix);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 148. [HIGH] Missing NULL check after allocation

**CWE-476** | `setup.c` line 2329

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
data->path = path ? path : xstrdup(value);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 149. [CRITICAL] Format string vulnerability

**CWE-134** | `exec-cmd.c` line 79

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
trace_printf("trace: resolved executable path from argv0: %s\n",
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 150. [CRITICAL] Format string vulnerability

**CWE-134** | `exec-cmd.c` line 364

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
trace_argv_printf(nargv.v, "trace: exec:");
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 151. [HIGH] Missing NULL check after allocation

**CWE-476** | `exec-cmd.c` line 295

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
return xstrdup(path);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 152. [HIGH] Missing NULL check after allocation

**CWE-476** | `exec-cmd.c` line 318

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
exec_path_value = xstrdup(env);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 153. [HIGH] Use-after-free pattern

**CWE-416** | `blame.c` line 58

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(o);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 154. [HIGH] Use-after-free pattern

**CWE-416** | `blame.c` line 997

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(similarities);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 155. [HIGH] Use-after-free pattern

**CWE-416** | `blame.c` line 998

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(certainties);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 156. [HIGH] Use-after-free pattern

**CWE-416** | `blame.c` line 999

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(second_best_result);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 157. [HIGH] Use-after-free pattern

**CWE-416** | `blame.c` line 1015

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(line_starts);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 158. [HIGH] Use-after-free pattern

**CWE-416** | `blame.c` line 1202

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(next);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 159. [HIGH] Use-after-free pattern

**CWE-416** | `blame.c` line 1726

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(fuzzy_matches);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 160. [HIGH] Use-after-free pattern

**CWE-416** | `blame.c` line 1896

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(line_blames);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 161. [HIGH] Use-after-free pattern

**CWE-416** | `blame.c` line 2330

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(blame_list);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 162. [HIGH] Use-after-free pattern

**CWE-416** | `blame.c` line 2581

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(sg_origin);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 163. [HIGH] Missing NULL check after allocation

**CWE-476** | `blame.c` line 1316

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
bd->keys[bd->nr] = xmalloc(sizeof(struct bloom_key));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 164. [HIGH] Missing NULL check after allocation

**CWE-476** | `blame.c` line 1467

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
struct blame_entry *e = xmalloc(sizeof(*e));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 165. [HIGH] Missing NULL check after allocation

**CWE-476** | `blame.c` line 1642

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
struct blame_entry *n = xcalloc(1, sizeof(struct blame_entry));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 166. [HIGH] Missing NULL check after allocation

**CWE-476** | `blame.c` line 2757

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
*name_p = xstrdup(name);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 167. [HIGH] Missing NULL check after allocation

**CWE-476** | `blame.c` line 2848

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
struct commit_list *l = xcalloc(1, sizeof(*l));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 168. [HIGH] Missing NULL check after allocation

**CWE-476** | `blame.c` line 2904

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
struct blame_entry *new_head = xcalloc(1, sizeof(struct blame_entry));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 169. [HIGH] Missing NULL check after allocation

**CWE-476** | `blame.c` line 2923

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
bd = xmalloc(sizeof(struct blame_bloom_data));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 170. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/history.c` line 47

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(d);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 171. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/history.c` line 197

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(original_author);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 172. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/history.c` line 340

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
commit_list_free(from_list);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 173. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/history.c` line 494

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ref_transaction_free(transaction);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 174. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/history.c` line 974

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
commit_list_free(parents);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 175. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/history.c` line 1257

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(subject);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 176. [HIGH] Use-after-free pattern

**CWE-416** | `builtin/history.c` line 1698

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(message_template);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 177. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `quote.h` line 17

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
* sprintf(cmd, "foobar %s %s", sq_quote(arg0), sq_quote(arg1))
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 178. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `quote.h` line 22

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
* sprintf(cmd, "git-diff-tree %s %s", sq_quote(arg0), sq_quote(arg1));
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 179. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `quote.h` line 23

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
* sprintf(rcmd, "ssh %s %s", sq_quote(host), sq_quote(cmd));
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 180. [CRITICAL] Command injection via system()/popen()

**CWE-78** | `quote.h` line 14

system() and popen() invoke /bin/sh. Any unsanitized input in the command string gives full shell access.

```
* For example, if you are passing the result to system() as an
```

**Fix:** Use execve() with explicit argv array. If shell features are needed, whitelist all arguments strictly.
---

### 181. [CRITICAL] Command injection via system()/popen()

**CWE-78** | `quote.h` line 19

system() and popen() invoke /bin/sh. Any unsanitized input in the command string gives full shell access.

```
* would be appropriate.  If the system() is going to call ssh to
```

**Fix:** Use execve() with explicit argv array. If shell features are needed, whitelist all arguments strictly.
---
