#!/bin/bash

set -eou pipefail

cmake -B build
cmake --build build
