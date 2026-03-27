#!/usr/bin/env bash
set -euo pipefail

# Convert one map's scripts.inc to scripts.pory by wrapping the legacy content
# in a raw block. This creates a migration baseline without changing behavior.

usage() {
    cat <<'USAGE'
Usage:
  convert_map_script_to_pory.sh <map-dir|scripts.inc-path> [--force]

Examples:
  convert_map_script_to_pory.sh data/maps/ViridianForest
  convert_map_script_to_pory.sh data/maps/ViridianForest/scripts.inc
  convert_map_script_to_pory.sh data/maps/ViridianForest --force

Behavior:
  - Creates scripts.pory only when missing (or when --force is provided).
  - Wraps current scripts.inc content in:
      raw `
      ...legacy content...
      `
USAGE
}

convert_one_map() {
    local map_dir="$1"
    local force="${2:-0}"

    local inc_file="${map_dir}/scripts.inc"
    local pory_file="${map_dir}/scripts.pory"

    if [[ ! -f "$inc_file" ]]; then
        echo "Error: missing scripts.inc at '$inc_file'" >&2
        return 1
    fi

    if [[ -f "$pory_file" && "$force" != "1" ]]; then
        echo "Skipped: scripts.pory already exists at '$pory_file'"
        return 0
    fi

    {
        printf 'raw `\n'
        cat "$inc_file"
        printf '\n`\n'
    } > "$pory_file"

    echo "Converted: '$inc_file' -> '$pory_file'"
}

main() {
    if [[ $# -lt 1 || $# -gt 2 ]]; then
        usage
        exit 2
    fi

    local input="$1"
    local force="0"

    if [[ $# -eq 2 ]]; then
        if [[ "$2" == "--force" ]]; then
            force="1"
        else
            echo "Error: unknown option '$2'" >&2
            usage
            exit 2
        fi
    fi

    local map_dir
    if [[ -d "$input" ]]; then
        map_dir="$input"
    elif [[ -f "$input" ]]; then
        if [[ "$(basename "$input")" != "scripts.inc" ]]; then
            echo "Error: file input must be scripts.inc, got '$input'" >&2
            exit 2
        fi
        map_dir="$(dirname "$input")"
    else
        echo "Error: path does not exist: '$input'" >&2
        exit 2
    fi

    convert_one_map "$map_dir" "$force"
}

main "$@"
