@echo off
cd /d %~dp0

javac -d . Main.java Model\*.java Repository\*.java Controller\*.java View\*.java Validacao\*.java
if errorlevel 1 (
    echo Compilation failed.
    pause
    goto cleanup
)

java -cp . GestaoVeiculosComplexo.Main

:cleanup
REM Ensure read-only attribute removed then delete class files reliably
attrib -r /s *.class >nul 2>nul
del /q /s *.class >nul 2>nul
echo Cleaned generated .class files.
pause