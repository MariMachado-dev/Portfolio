package GestaoVeiculos.Dominio;

import GestaoVeiculos.Validacao.PlacaInvalidaException;

public class Caminhao extends Veiculo implements Tributavel {
    private double toneladasCarga;

    public Caminhao(double toneladasCarga, double custoFixo, String placa) throws PlacaInvalidaException {
        super(placa, custoFixo);
        
        if (placa == null || placa.length() != 7) {
            throw new PlacaInvalidaException("Placa deve seguir o formato ABC-1234.");
        }

        this.toneladasCarga = toneladasCarga;
    }

    @Override
    public double calcularCustoTotal() {
        return getCustoFixo() + (toneladasCarga * 50.0);
    }

    @Override
    public double calcularIPVA() {
        return getCustoFixo() * 0.15;
    }
}
