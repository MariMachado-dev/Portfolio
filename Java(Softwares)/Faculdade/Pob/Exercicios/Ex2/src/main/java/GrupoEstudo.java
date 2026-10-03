import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

import javafx.scene.Group;
import javafx.scene.control.Label;
import javafx.scene.shape.Circle;

public class GrupoEstudo extends Group {
    private Circle grupoEstudoCircle;
    private Label grupoEstudoLabel;
    private double grupoEstudoDist = 0;
    private ArrayList<Dorm> dormsEscolhidos;

    public GrupoEstudo(ArrayList<Dorm> dorms) {
        ArrayList<Dorm> todosDorms = dorms; 
        grupoEstudoCircle = new Circle(50, 50, 10, javafx.scene.paint.Color.BLACK);
        grupoEstudoCircle.setStroke(javafx.scene.paint.Color.YELLOW);

        grupoEstudoLabel = new Label("Grupo de estudos\nDistância: " + grupoEstudoDist);
        grupoEstudoLabel.setTextFill(javafx.scene.paint.Color.RED);
        grupoEstudoLabel.setLayoutX(50);
        grupoEstudoLabel.setLayoutY(55);

        //Escolher 3 dormitórios aleatoriamente para formar o grupo de estudo
        ArrayList<Dorm> dormsShuffled = new ArrayList<>(todosDorms);
        Collections.shuffle(dormsShuffled);
        dormsEscolhidos = new ArrayList<>(dormsShuffled.subList(0, 3));
        System.out.println("Dorms escolhidos para o grupo de estudo: " + dormsEscolhidos);

        for (Dorm d : dormsEscolhidos) {
            d.layoutXProperty().addListener((obs, oldVal, newVal) -> atualizarPosicao());
            d.layoutYProperty().addListener((obs, oldVal, newVal) -> atualizarPosicao());
        }
    
        this.getChildren().addAll(grupoEstudoCircle, grupoEstudoLabel);
    }

    public int getDistGrupoEstudo() {
        return (int) grupoEstudoDist;
    }

    public void setDistGrupoEstudo(double grupoEstudoDist) {
        this.grupoEstudoDist = grupoEstudoDist;
    }

    //Metodos auxiliares
    private double[] calcularContribuicaoDorm(Dorm d) {
        Random rand = new Random();

        int x = d.getCordsXCentro();
        int y = d.getCordsYCentro();
        int peso = d.getQtdPessoas();

        double dist = Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2));
        
        // retorna {distancia* peso, peso} para depois somar
        return new double[]{dist * peso, peso, x, y};
    }

    private double calcularDistanciaFinal(ArrayList<Dorm> dorms) {
    double somaDist = 0;
    double somaPesos = 0;
    double somaX = 0;
    double somaY = 0;

    for (Dorm d : dorms) {
        double[] contribuicao = calcularContribuicaoDorm(d);
        somaDist += contribuicao[0];    
        somaPesos += contribuicao[1];
        somaX += contribuicao[2] * contribuicao[1];
        somaY += contribuicao[3] * contribuicao[1];
    }

    if (somaPesos > 0) {
        double centroX = somaX / somaPesos; // média ponderada
        double centroY = somaY / somaPesos;

        grupoEstudoCircle.setCenterX(centroX);
        grupoEstudoCircle.setCenterY(centroY);

        // Centraliza o label horizontalmente abaixo do círculo
        grupoEstudoLabel.applyCss();
        grupoEstudoLabel.layout();
        grupoEstudoLabel.setLayoutX(centroX - grupoEstudoLabel.getWidth() / 2);
        grupoEstudoLabel.setLayoutY(centroY + grupoEstudoCircle.getRadius() + 5);
    }

    return somaDist / somaPesos;
}

   private void atualizarPosicao() {
        grupoEstudoDist = calcularDistanciaFinal(dormsEscolhidos);
        grupoEstudoLabel.setText("Grupo de estudos\nDistância: " + Math.round(grupoEstudoDist));
    }
}
