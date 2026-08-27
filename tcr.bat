@echo off
call test.bat && (git add -A && git commit -m "TCR: tests passing") || (git checkout -- . && git clean -fd)
