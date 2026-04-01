package fliperama;

public class categoriaPremio {
    private String nome;
    private int custoTickets;
    private int qtdItens;

    public categoriaPremio(String nome, int custoTickets, int qtdItens) {
        this.nome = nome;
        this.custoTickets = custoTickets;
        this.qtdItens = qtdItens;
    }

    public String getNome() {
        return nome;
    }
    
    public int getCustoTickets() {
        return custoTickets;
    }

    public int getQtdItens() {
        return qtdItens;
    }

    public void setQtdItens(int qtdItens) {
        this.qtdItens = qtdItens;   
    }
}
