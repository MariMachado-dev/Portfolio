package GestaoVeiculosComplexo.Model;

import GestaoVeiculosComplexo.Validacao.PlacaInvalidaException;

public class Caminhao extends Veiculo implements Tributavel {
    private double toneladasCarga;

    public Caminhao(double toneladasCarga, double custoFixo, String placa) throws PlacaInvalidaException {
        super(placa, custoFixo);
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
