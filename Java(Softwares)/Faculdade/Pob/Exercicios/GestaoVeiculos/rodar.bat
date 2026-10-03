@echo off
cd /d %~dp0

REM Compile all Java sources in this module into package folders
javac -d . Main.java Dominio\*.java Gerenciar_Dados\*.java Validacao\*.java
if errorlevel 1 (
    echo Compilation failed.
    pause
    goto cleanup
)

REM Run the module
java -cp . GestaoVeiculos.Main

:cleanup
REM Delete generated class files



del /q /s *.class >nul 2>nul
echo Cleaned generated .class files.
pause