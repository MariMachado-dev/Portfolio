public class Produto {
    private String nome;
    private double preco;
    
    public Produto(String nome, double preco) {
        this.nome = nome;
        this.preco = preco;
    }

    public double getPreco() {
        return preco;
    }
    
    public void aplicarDesconto(double percentual) {
        double desconto = preco * (percentual / 100);
        preco = preco - desconto;
    }
}