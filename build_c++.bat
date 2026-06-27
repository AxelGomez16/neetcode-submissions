@echo off
echo  Clean n Build
echo.

if exist build (
    rmdir /s /q build
    echo Build folder deleted.
) else (
    echo Build folder not found, skipping.
)

cmake -B build -G "Visual Studio 17 2022" -A x64

if %errorlevel% neq 0 (
    echo.
    echo CMake generation failed!
    exit /b %errorlevel%
)

echo.
echo Success!

