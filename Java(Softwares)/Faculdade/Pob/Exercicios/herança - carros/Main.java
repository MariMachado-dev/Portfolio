public class Main
{
	public static void main(String[] args) {
		Gerente gerente1 = new Gerente("Carlos", 7000, "TI");
		Gerente gerente2 = new Gerente("Ana", 7000, "RH");
		Gerente gerente3 = new Gerente("Thiago", 7000, "Atendente");

		gerente1.calcularBonus();
		gerente1.exibirDados();
		
		gerente2.calcularBonus();
		gerente2.exibirDados();

		gerente3.calcularBonus();
		gerente3.exibirDados();

	}
}
