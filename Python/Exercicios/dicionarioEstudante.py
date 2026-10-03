# estudante = {
#     "nome": "Joana",
#     "idade": 20,
#     "nota1": 10,
#     "nota2": 6
# }

# estudante["curso"] = "Algoritmos em Python"
# estudante["idade"] = 21

# estudante["media"] = (estudante["nota1"] + estudante["nota2"]) / 2

# print(estudante)

# ############################
# #Invertendo strings
# stringInput = input("Digite uma string: ")
# stringInvertida = ''.join(reversed(stringInput))
# print(f"A string invertida é: {stringInvertida}")

qtdVogais = {
    'a': 0,
    'e': 0,
    'i': 0,
    'o': 0,
    'u': 0
}

palavra = input("Digite uma palavra: ")
for letra in palavra:
    if letra in qtdVogais:
        qtdVogais[letra] += 1

print(f"A quantidade de vogais na palavra '{palavra}' é: {qtdVogais}")