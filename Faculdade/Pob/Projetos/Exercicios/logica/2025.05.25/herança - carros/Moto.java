public class Moto extends Veiculo {
    private int cilindradas;
    
    public Moto(String marca, String modelo, int cilindradas) {
        super(marca, modelo); 
        this.cilindradas = cilindradas;
    }
    
    @Override
    public void exibirDados() {
        System.out.println("A marca da moto é "+marca);
        System.out.println("O modelo da moto é "+modelo);
        System.out.println("A quantidade de cilindradas da moto é "+cilindradas);
    }
}