import math
import random

# Aqui está a lista de preços
precos = [2.50, 5.99, 1.20, 10.00, 4.35, 0.1]

# Aqui está a variável que armazenará a soma dos preços
total = 0
media = 0

#Escreva o seu laço de repetição para percorrer a lista e obter a soma dos preços.
for preco in precos:
    total += preco

#Após isso, calcule e imprima a média aritmética dos preços.
media = total / len(precos)

print(f"A média dos preços é: {media:.2f}")