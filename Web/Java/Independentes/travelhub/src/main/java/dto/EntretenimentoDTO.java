package dto;

public class EntretenimentoDTO {
    private String nome;
    private String descricao;
    private String categoria;
    private String icone;

    public EntretenimentoDTO() {

    }

    public EntretenimentoDTO(String nome, String descricao, String categoria, String icone) {
        this.nome = nome;
        this.descricao = descricao;
        this.categoria = categoria;
        this.icone = icone;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public String getCategoria() {
        return categoria;
    }

    public void setCategoria(String categoria) {
        this.categoria = categoria;
    }

    public String getIcone() {
        return icone;
    }

    public void setIcone(String icone) {
        this.icone = icone;
    }
}


