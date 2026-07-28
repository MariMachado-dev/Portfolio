package GestaoVeiculosComplexo.Model;

import GestaoVeiculosComplexo.Validacao.PlacaInvalidaException;

public class Carro extends Veiculo implements Tributavel {
    private int quilometragem;
    
    public Carro(int quilometragem, double custoFixo, String placa) throws PlacaInvalidaException {
        super(placa, custoFixo);
        this.quilometragem = quilometragem;
    }

    @Override
    public double calcularCustoTotal() {
        double custoTotal = getCustoFixo() + (quilometragem * 0.15); 
        return custoTotal;
    }

    @Override
    public double calcularIPVA() {
        return getCustoFixo() * 0.04;
    }
}
