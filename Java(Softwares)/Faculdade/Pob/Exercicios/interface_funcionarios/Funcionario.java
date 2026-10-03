public class  Funcionario {
    protected String nome;
    protected String senha;

    public Funcionario(String nome, String senha) {
        this.nome = nome;
        this.senha = senha;
    }

     public void trabalhar() {
        System.out.println(nome + " está trabalhando");
    }
}
    