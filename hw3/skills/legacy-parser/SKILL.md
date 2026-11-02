---
name: legacy-parser
description: Parse local course log files from the HW3 inbox directory.
---

# Legacy Parser

This skill is used to inspect local log files using
the legacy_log_parser program.

Only files located inside the following directory
can be processed:

~/csce465-agentsec/hw3/inbox/

When asked to parse a log file, use the exec tool
to execute:

{baseDir}/run_parser.sh <file_path>

Always use the wrapper script to run the parser.

Do not execute the parser directly or accept
file paths outside the approved inbox directory.

Report the parser output, including any errors.
