public class Main {
    public static void main(String[] args) {
        ContaBancaria conta = new ContaBancaria(500, "João");
        
        try {
            conta.sacar(600, "João");
        } 
        catch (SaldoInsuficienteException e) {
            System.out.println("Erro na operação bancária:");
            System.out.println(e.getMessage());
        }
    }
}
