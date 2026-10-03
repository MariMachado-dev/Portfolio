public class Veiculo {
    protected String marca;
    protected String modelo;
    
    public Veiculo(String marca, String modelo) {
        this.marca = marca;
        this.modelo = modelo;
    }
    
    public void exibirDados() {
        System.out.println("A marca do veiculo é"+marca);
        System.out.println("O modelo do veiculo é"+modelo);
    }
}