package GestaoVeiculosComplexo;

import GestaoVeiculosComplexo.Controller.*;
import GestaoVeiculosComplexo.Repository.*;
import GestaoVeiculosComplexo.View.*;

public class Main {
    public static void main(String[] args) {
        VeiculoRespository repository = new VeiculoRespository();
        VeiculoController controller = new VeiculoController(repository);
        VeiculoView view = new VeiculoView(controller);
        view.exibirMenu();
    }
}
