@echo off

echo Compilando...
javac *.java

if %errorlevel% neq 0 (
    echo Erro na compilacao!
    pause
    exit /b
)

echo Executando...
java Main

echo Limpando arquivos...
del *.class

pause