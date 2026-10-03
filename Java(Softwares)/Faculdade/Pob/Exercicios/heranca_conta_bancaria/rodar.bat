@echo off

cd ..

javac heranca_conta_bancaria\*.java

if %errorlevel% neq 0 exit /b

java heranca_conta_bancaria.Main

del heranca_conta_bancaria\*.class

pause