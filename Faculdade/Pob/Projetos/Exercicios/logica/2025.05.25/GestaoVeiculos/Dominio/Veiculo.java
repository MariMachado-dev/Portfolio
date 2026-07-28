package GestaoVeiculos.Dominio;

import GestaoVeiculos.Validacao.PlacaInvalidaException;

// Classe Abstrata Base
public abstract class Veiculo {
    private String placa;
    private double custoFixo;

    public Veiculo(String placa, double custoFixo) throws PlacaInvalidaException {
    // Validar placa (deve conter exatamente 7 caracteres)
    if (placa == null || placa.length() != 7) {
        throw new PlacaInvalidaException(placa);
    }

    // Inicializar atributos
    this.placa = placa;
    this.custoFixo = custoFixo;
}
    public abstract double calcularCustoTotal();

    // Getters e Setters...
    public String getPlaca() {
        return placa;
    }

    public double getCustoFixo() {
        return custoFixo;
    }

    public void setPlaca(String placa) throws PlacaInvalidaException {
        if (placa == null || placa.length() != 7) {
            throw new PlacaInvalidaException(placa);
        }
        
        this.placa = placa;
    }

    public void setCustoFixo(double custoFixo) {
        this.custoFixo = custoFixo;
    }
}