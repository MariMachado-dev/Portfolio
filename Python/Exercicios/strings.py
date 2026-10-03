palavra = input("Digite uma palavra: ")
letrasMaiusculas = []
letrasMinusculas = []

tamanho = len(palavra)
ultCaracter = palavra[-1]  
primCaracter = palavra[0]
invertida = palavra[::-1]

for i in range(tamanho):
    if (palavra[i].isupper()):
        letrasMaiusculas.append(palavra[i])

    else:
        letrasMinusculas.append(palavra[i])

#Exibir
print(f"A palavra digitada foi: {palavra}")
print(f"O tamanho da palavra é: {tamanho}")
print(f"A palavra invertida é: {invertida}")    
print(f"A primeira letra da palavra é: {primCaracter}")
print(f"A última letra da palavra é: {ultCaracter}")
print(f"As letras maiúsculas da palavra são: {letrasMaiusculas}")
print(f"As letras minúsculas da palavra são: {letrasMinusculas}")