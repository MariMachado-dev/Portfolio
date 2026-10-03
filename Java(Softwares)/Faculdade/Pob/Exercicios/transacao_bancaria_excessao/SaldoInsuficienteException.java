public class SaldoInsuficienteException extends Exception {
    private double saldoDisponivel;
    private double valorSolicitado;

    public SaldoInsuficienteException(double saldoDisponivel, double valorSolicitado) {
        super("Saldo insuficiente! Saldo disponível: R$ " + saldoDisponivel + " | Valor solicitado: R$ " + valorSolicitado);

        this.saldoDisponivel = saldoDisponivel;
        this.valorSolicitado = valorSolicitado;
    }
}
