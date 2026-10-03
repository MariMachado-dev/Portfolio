import math
from xml.etree.ElementTree import PI

def calcula_vertice(a,b,c):
    discriminante = b**2 - 4*a*c

    verticeX = -b/(2*a)
    verticeY = -discriminante/(4*a)
    verticeX = math.floor(verticeX)
    verticeY = math.floor(verticeY)
    coordenadas = (verticeX, verticeY)
    print(f"O vértice da parábola é: {coordenadas}")
    return coordenadas

def fibonacci(n):
    if (n == 1):
        return 1

    if (n == 0):
        return 0

    return fibonacci(n - 2) + fibonacci(n - 1)

def fibonaci_soma(n):
    if n == 0:
        return 0

    return fibonacci(n - 1) + fibonaci_soma(n - 1)
    

def calcula_cone(raio, altura):
    AreaBase = math.pi * (raio ** 2)
    print("Você escolheu calcular o Cone.")
    raio = float(input("Digite o valor do raio da base do cone: "))
    altura = float(input("Digite o valor da altura do cone: "))

    AreaBase = math.pi * (raio ** 2)
    g = math.hypot(raio, altura)
    AreaConeLateral = math.pi * raio * g
    AreaConeTotal = AreaBase + AreaConeLateral
    VolumeCone = (1/3) * AreaBase * altura

    print(f"A área da base do cone é: {AreaBase:.2f}")
    print(f"A área lateral do cone é: {AreaConeLateral:.2f}")
    print(f"A área total do cone é: {AreaConeTotal:.2f}")
    print(f"O volume do cone é: {VolumeCone:.2f}")

def calcula_cilindro(raio, altura):
    print("Você escolheu calcular o Cilindro.")
    raio = int(input("Digite o valor do raio da base do cilindro: "))
    altura = int(input("Digite o valor da altura do cilindro: "))

    AreaBase = math.pi * (raio ** 2)
    AreaLateral = 2 * math.pi * raio * altura
    AreaTotal = 2 * AreaBase + AreaLateral
    Volume = AreaBase * altura

    print(f"A área da base do cilindro é: {AreaBase:.2f}")
    print(f"A área lateral do cilindro é: {AreaLateral:.2f}")   
    print(f"A área total do cilindro é: {AreaTotal:.2f}")
    print(f"O volume do cilindro é: {Volume:.2f}")

def calcula_esfera(raio):
    print("Você escolheu calcular a Esfera.")
    raio = int(input("Digite o valor do raio da esfera: "))

    AreaEsfera = 4 * math.pi * (raio ** 2)
    VolumeEsfera = (4/3) * math.pi * (raio ** 3)

    print(f"A área da esfera é: {AreaEsfera:.2f}")
    print(f"O volume da esfera é: {VolumeEsfera:.2f}")


calcula_vertice(-34453, 4234654, 44575)
resp = fibonaci_soma(27)
print(f"A soma dos 27 primeiros números da sequência de Fibonacci é: {resp}")





