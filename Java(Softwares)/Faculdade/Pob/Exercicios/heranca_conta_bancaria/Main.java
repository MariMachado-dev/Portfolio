package heranca_conta_bancaria;

public class Main {
    public static void main(String[] args) {
        ContaCorrente conta1 = new ContaCorrente("Joao", 1000, 1234, 500);
        ContaPoupanca conta2 = new ContaPoupanca("Maria", 2000, 4321, 10);
        
        conta1.escolherOperacao('S', 1200);
        conta1.escolherOperacao('S', 500);
        
        conta2.escolherOperacao('S', 1800);
    }
}