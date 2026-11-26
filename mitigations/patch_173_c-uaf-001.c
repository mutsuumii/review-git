# Use-after-free pattern
# CWE-416 | Severity: HIGH
# File: builtin/history.c line 494

**Risk:** Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
