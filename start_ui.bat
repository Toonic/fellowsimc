@echo off
title FellowSimc Simulator ^& Character Importer
echo ===================================================
echo   Starting FellowSimc Web UI ^& Character Importer
echo ===================================================
echo.

python -c "import requests" 2>nul
if %ERRORLEVEL% NEQ 0 (
    echo Installing required dependency (requests)...
    pip install requests
    echo.
)

python ui\server.py

if %ERRORLEVEL% NEQ 0 (
    echo.
    echo Server stopped or Python was not found. Please ensure Python 3 is installed.
    pause
)
