@echo off

echo -----------------------------------
echo clean project/coide_gen/rvmdk/ewarm
@for /r . %%a in (.) do (
    @if exist "%%a\template" rd /s /q "%%a\template"
    @if exist "%%a\Debug_Flash" rd /s /q "%%a\Debug_Flash"
    @if exist "%%a\Debug_Ram" rd /s /q "%%a\Debug_Ram"
    @if exist "%%a\ewarm\settings" rd /s /q "%%a\ewarm\settings"
    @if exist "%%a\Debug" rd /s /q "%%a\Debug"
    @if exist "%%a\Release" rd /s /q "%%a\Release"
    @if exist "%%a\*.dep" del /q "%%a\*.dep"
    @if exist "%%a\obj" rd /s /q "%%a\obj"
    @if exist "%%a\lst" rd /s /q "%%a\lst"
    @if exist "%%a\*.uvgui.*" del /q "%%a\*.uvgui.*"
    @if exist "%%a\*.bak" del /q "%%a\*.bak" 
    @if exist "%%a\*.o" del /q "%%a\*.o" 
    @if exist "%%a\*.d" del /q "%%a\*.d"
    @if exist "%%a\*.plg" del /q "%%a\*.plg"    
    @if exist "%%a\*.uvopt" del /q "%%a\*.uvopt"
    @if exist "%%a\*.cogui" del /q "%%a\*.cogui"
    @if exist "%%a\*.comarker" del /q "%%a\*.comarker"
    @if exist "%%a\coide\tmpm_coide_empty_project" rd /s /q "%%a\coide\tmpm_coide_empty_project"
)
@echo completed
echo -----------------------------------

pause
