package GestaoVeiculos.Validacao;

public class PlacaInvalidaException extends Exception {
    private String placaInvalida;

    public PlacaInvalidaException(String placaInvalida) {
        super("Placa inválida: " + placaInvalida + ". A placa deve seguir o formato ABC-1234.");
        this.placaInvalida = placaInvalida;
    }
}
