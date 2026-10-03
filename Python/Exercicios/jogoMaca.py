qtdMacas = int(input("Digite a quantidade de maçãs que você deseja armazenar para jogar: "))
JogaPrimeiro = input("Digite 1 se você deseja jogar primeiro ou 2 se deseja que seu amigo jogue primeiro: ")

if (JogaPrimeiro == '1'):
    print("Você jogará primeiro!")

    if (qtdMacas % 2 == 0):
        print("Você perdeu e seu amigo ganhou o jogo!")

    else:
        print("Você ganhou o jogo e seu amigo perdeu!")

else:
    print("Seu amigo jogará primeiro!")

    if (qtdMacas % 2 == 0):
        print("Você ganhou o jogo e seu amigo perdeu!")

    else:
        print("Você perdeu e seu amigo ganhou o jogo!")