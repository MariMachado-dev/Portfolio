public class Main {
    public static void main(String[] args) {
        Funcionario diretor = new Diretor("123456789", 10000);
        Funcionario vendedor = new Vendedor("987654321", 5000);

        if (diretor != null) {
            System.out.println("O diretor tem CPF: " + diretor.getCpf() + " e salário: " + diretor.getSalario());
        }   
        else {
            System.out.println("Não foi criado um diretor");
        }

        if (vendedor != null) {
            System.out.println("O vendedor tem CPF: " + vendedor.getCpf() + " e salário: " + vendedor.getSalario());
        }   
        else {
            System.out.println("Não foi criado um vendedor");
        }
    }
}
