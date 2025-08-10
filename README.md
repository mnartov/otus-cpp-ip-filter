# OTUS C++ Course Homework #2 IP filter

[![CI/CD Pipeline](https://github.com/mnartov/otus-cpp-template/actions/workflows/build.yml/badge.svg)](https://github.com/mnartov/otus-cpp-template/actions/workflows/build.yml)

A utility for sorting and filtering IP address logs. Processes TSV input, extracts IPs, sorts them in reverse lexicographical order (by byte value), and outputs filtered lists.

Features
 - Reads TSV data from stdin (format: ip\ttext\ttext)
 - Sorts IPs in reverse lex order (numerical byte comparison)

Outputs:
 - All sorted IPs
 - IPs where first byte = 1
 - IPs where first byte = 46 and second = 70
 - IPs containing any byte = 46

## Quick Start

### Build and Run

The repository includes `run.sh` script that handles all build and execution steps:

```bash
# Run the application (default)
./tools/run.sh

# Run unit tests
./tools/run.sh --test

# Clean build and run tests
./tools/run.sh --test --clean