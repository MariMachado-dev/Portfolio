public class Gerente extends Funcionario implements Autenticavel {
    public Gerente(String nome, String senha) {
        super(nome, senha);
    }

    @Override
    public boolean autenticar(String senha) {
        return this.senha.equals(senha);
    }

    public void aprovarRelatorio() {
        System.out.println(nome + " aprovou relatório");
    }
}
