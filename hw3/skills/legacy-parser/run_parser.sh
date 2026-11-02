#!/usr/bin/env bash

set -euo pipefail

ROOT="${HW3_ROOT:-$HOME/csce465-agentsec/hw3}"
INBOX="$ROOT/inbox"

# Require exactly one file path.
if [[ $# -ne 1 ]]; then
    echo "Usage: run_parser.sh <file_path>"
    exit 1
fi

# Resolve the actual file path.
FILE=$(realpath -e -- "$1") || exit 1

# Only allow files inside inbox.
if [[ ! -f "$FILE" || "$FILE" != "$INBOX/"* ]]; then
    echo "Access denied: File must be inside inbox/"
    exit 1
fi

# Run the vulnerable parser on the approved file.
exec "$ROOT/legacy_log_parser" "$FILE"
