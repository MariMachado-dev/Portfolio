public class Main
{
	public static void main(String[] args) {
		Produto p1 = new Produto("Camiseta", 50);
		Produto p2 = new Produto("Calça", 100);

		CarrinhoDeCompras carrinho = new CarrinhoDeCompras();
		carrinho.adicionarProduto(p1);
		carrinho.adicionarProduto(p2);

		System.out.println("Total do carrinho: " + carrinho.calcularTotal());

		carrinho.aplicarDescontoGeral(10);
		System.out.println("Total do carrinho após desconto: " + carrinho.calcularTotal());
	}
}
