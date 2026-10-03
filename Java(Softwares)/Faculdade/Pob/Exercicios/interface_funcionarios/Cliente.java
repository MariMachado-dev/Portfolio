public class Cliente implements Autenticavel {
    private String nome;
    private String senha;

    public Cliente(String nome, String senha) {
        this.nome = nome;
        this.senha = senha;
    }

    @Override
    public boolean autenticar(String senhaDigitada) {
        return this.senha.equals(senhaDigitada);
    }
}