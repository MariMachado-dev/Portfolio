import java.util.ArrayList;
import java.util.Optional;

import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.TextInputDialog;
import javafx.scene.layout.AnchorPane;

public class Campus extends AnchorPane {
    private ArrayList<Dorm> dorms = new ArrayList<>();
    private DistanciaDorms distanciaDorms;
    private GrupoEstudo grupoEstudo;

    public Campus() {
        int addDorm = 1;
        distanciaDorms = new DistanciaDorms();

        while (addDorm == 1) {
            TextInputDialog dialog = new TextInputDialog();
            dialog.setTitle("Adicionar Dorm");
            dialog.setHeaderText("Dorm " + (dorms.size() + 1));
            dialog.setHeaderText("Forneça o tamanho e a quantidade de pessoas (separados por espaço, ex.: 100 5(0 0 para sair))");

            Optional<String> result = dialog.showAndWait();
            if (result.isPresent()) {
                String input = result.get().trim();
                String[] parts = input.split("\\s+");

                double size = Double.parseDouble(parts[0]);
                int people = Integer.parseInt(parts[1]);

                if (people < 0 || size < 0) {
                    errorDialog("Entrada inválida", "Não é permitido valores negativos para tamanho ou quantidade de pessoas.");
                    continue;
                }

                if (size == 0 && people == 0) {
                    addDorm = 0;
                }

                else {
                    Dorm d = new Dorm(size, people);
                    dorms.add(d);
                    this.getChildren().add(d);
                    distanciaDorms.atualizarDistanciaDorms(dorms);

                    d.boundsInParentProperty().addListener((obs, oldVal, newVal) ->
                        distanciaDorms.atualizarDistanciaDorms(dorms)
                    );
                }
            } 
            
            else {
                break;
            }
        }

        grupoEstudo = new GrupoEstudo(dorms);
        this.getChildren().addAll(distanciaDorms, grupoEstudo);
    }

    //Metodos auxiliares
    private void errorDialog(String title, String message) {
        Alert alert = new Alert(AlertType.ERROR);
        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }
}