import java.util.ArrayList;

import javafx.scene.Group;
import javafx.scene.control.Label;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;

public class DistanciaDorms extends Group {
    private Circle distanciaDormsCircle;
    private Label distanciaDormsLabel;
    private double distanciaMediaDorms = 0;

    public DistanciaDorms() {
        distanciaDormsCircle = new Circle(50, 50, 10, Color.BLACK);
        distanciaDormsCircle.setStroke(Color.YELLOW);

        //Criar o label para exibir a distância média dos dormitórios
        distanciaDormsLabel = new Label("Concentração populacional\nDistância: " + distanciaMediaDorms);
        distanciaDormsLabel.setTextFill(Color.RED);
        distanciaDormsLabel.setLayoutX(50);
        distanciaDormsLabel.setLayoutY(55);
        this.getChildren().addAll(distanciaDormsCircle, distanciaDormsLabel);
    }

    
    public int getDistanciaMediaDorms() {
        return (int) distanciaMediaDorms;
    }

    public void setDistanciaMediaDorms(double distanciaMediaDorms) {
        this.distanciaMediaDorms = distanciaMediaDorms;
    }

    public void atualizarDistanciaDorms(ArrayList<Dorm> dorms) {
        double somaX = 0;
        double somaY = 0;
        int somaPesos = 0;

        for (Dorm d : dorms) {
            int x = d.getCordsXCentro();
            int y = d.getCordsYCentro();
            int peso = d.getQtdPessoas();

            somaX += x * peso;
            somaY += y * peso;
            somaPesos += peso;
        }

        if (somaPesos == 0) { return; }

        double centroX = somaX / somaPesos;
        double centroY = somaY / somaPesos;

        //Colocar o círculo populacional e seu label nas coordenadas do centro calculado
        distanciaDormsCircle.setCenterX(centroX);
        distanciaDormsCircle.setCenterY(centroY);

        //Calcular a distância média dos dormitórios para exibir posteriormente
        double somaDist = 0;

        for (Dorm d : dorms) {
            int x = d.getCordsXCentro();
            int y = d.getCordsYCentro();
            int peso = d.getQtdPessoas();

            double dist = Math.sqrt(
                Math.pow(x - centroX, 2) +
                Math.pow(y - centroY, 2)
            );

            somaDist += dist * peso;
        }

        int distanciaMedia = (int) (somaDist / somaPesos);
        setDistanciaMediaDorms(distanciaMedia);
        distanciaDormsLabel.setText("Concentração populacional\nDistância: " + distanciaMediaDorms);

        // Força o JavaFX a calcular tamanho real do label
        distanciaDormsLabel.applyCss();
        distanciaDormsLabel.layout();
        distanciaDormsLabel.setLayoutX(centroX - distanciaDormsLabel.getWidth() / 2);
        // Posiciona verticalmente abaixo do círculo (5px abaixo)
        distanciaDormsLabel.setLayoutY(centroY + 10);

        System.out.println("Posição do círculo populacional: (" +  Math.round(centroX) + ", " + Math.round(centroY) + ")");
        System.out.println("Distância média populacional: " +  Math.round(distanciaMediaDorms));
    }
}
