echo off

set v_repo_root=..\..\
set v_gen_root=.\

::echo %v_repo_root_self%
set v_iar2coide=%v_repo_root%\resource\tools\iar2coide\iar2coide.exe
::echo %v_iar2coide%

echo --------------------------------------------
echo generate coide project in publish\example
echo --------------------------------------------
echo clean project/coide/rvmdk/ewarm
@for /r "%v_gen_root%" %%a in (.) do (
    @if exist "%%a\coide" rd /s /q "%%a\coide"
    @if exist "%%a\coide_gen" rd /s /q "%%a\coide_gen"
    @if exist "%%a\Debug_Flash" rd /s /q "%%a\Debug_Flash"
    @if exist "%%a\Debug_Ram" rd /s /q "%%a\Debug_Ram"
    @if exist "%%a\ewarm\settings" rd /s /q "%%a\ewarm\settings"
    @if exist "%%a\Debug" rd /s /q "%%a\Debug"
    @if exist "%%a\Release" rd /s /q "%%a\Release"
    @if exist "%%a\*.dep" del /q "%%a\*.dep"
    @if exist "%%a\obj" rd /s /q "%%a\obj"
    @if exist "%%a\lst" rd /s /q "%%a\lst"
    @if exist "%%a\*.uvgui.*" del /q "%%a\*.uvgui.*"
    @if exist "%%a\*.uvopt" del /q "%%a\*.uvopt" 
    @if exist "%%a\*.bak" del /q "%%a\*.bak" 
    @if exist "%%a\*.o" del /q "%%a\*.o" 
    @if exist "%%a\*.d" del /q "%%a\*.d"
)
echo completed
echo --------------------------------------------
echo gen coide project: 
%v_iar2coide% -w "%v_gen_root%\cmsis_lib" -t %v_gen_root%\resource\coide_empty_project  >>nul
echo completed
echo --------------------------------------------

pause
