# Code injection via eval()
# CWE-95 | Severity: CRITICAL
# File: gitweb/static/js/lib/common-lib.js line 217

**Risk:** eval() with dynamic input runs arbitrary JavaScript.

**Fix:** Use JSON.parse() for data. Pass function references, not strings, to setTimeout.
