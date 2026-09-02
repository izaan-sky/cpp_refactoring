#!/bin/bash
cmake -S . -B build && cmake --build build && ctest --test-dir build --output-on-failure \
  && (git add -A && git commit -m "TCR: tests passing") \
  || (git checkout -- . && git clean -fd)
