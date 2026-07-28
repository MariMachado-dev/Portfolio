import javafx.scene.Group;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Color;
import javafx.scene.shape.Polygon;

public class Dorm extends Group {
    private Polygon dorm;
    private Label labelQtdPessoas;
    private static int qtdDorms = 0;
    private int qtdPessoas = 0;
    private double tamanho;

    public Dorm(double tamanho, int qtdPessoas) {
        double centroXInicial = 30 + tamanho / 2;

        this.tamanho = tamanho;
        this.qtdPessoas = qtdPessoas;
        qtdDorms++;//Importante para ditar as cores dos dormitórios e o número do dorm no label

        this.dorm = new Polygon();
        dorm.getPoints().addAll(
            30.0, 30.0,
            30.0, 30.0 + tamanho,
            30.0 + tamanho, 30.0 + tamanho,
            30.0 + tamanho, 30.0
        );

        switch (qtdDorms) {
            case 1:
                this.dorm.setFill(Color.rgb(0, 0, 255, 0.2));
                this.dorm.setStroke(Color.BLUE);
                break;
            case 2:
                this.dorm.setFill(Color.rgb(255, 0, 0, 0.2));
                this.dorm.setStroke(Color.RED);
                break;
            case 3:
                this.dorm.setFill(Color.rgb(0, 255, 0, 0.2));
                this.dorm.setStroke(Color.GREEN);
                break;
            case 4:
                this.dorm.setFill(Color.rgb(255, 255, 0, 0.2));
                this.dorm.setStroke(Color.YELLOW);
                break;
            case 5:
                this.dorm.setFill(Color.rgb(255, 0, 255, 0.2));
                this.dorm.setStroke(Color.MAGENTA);
                break;
            default:
                System.out.println("Número máximo de dormitórios atingido.");
        }

        //Criar o label para exibir a quantidade de pessoas e posiciona-lo no centro do dorm
        labelQtdPessoas = new Label("Dorm " + qtdDorms + "\n" + qtdPessoas + " pessoas");
        labelQtdPessoas.setTextFill(Color.RED);
        labelQtdPessoas.layoutBoundsProperty().addListener((obs, oldVal, newVal) -> {
            labelQtdPessoas.setLayoutX(centroXInicial - newVal.getWidth() / 2);
        });
        labelQtdPessoas.setLayoutY(35 + tamanho);

        //Estilizar o label
        labelQtdPessoas.setStyle("-fx-font-weight: bold;");

        //Arrastar o dorms
        final double[] offsetX = new double[1];
        final double[] offsetY = new double[1];

        this.setOnMousePressed(me -> {
            offsetX[0] = me.getSceneX() - this.getLayoutX();
            offsetY[0] = me.getSceneY() - this.getLayoutY();
        });

        //Arrastar o dorm e exibir a posição do mouse ao mesm
        this.setOnMouseDragged((MouseEvent me) -> {
            this.setLayoutX(me.getSceneX() - offsetX[0]);
            this.setLayoutY(me.getSceneY() - offsetY[0]);

        });


        this.getChildren().addAll(dorm, labelQtdPessoas);
    }

    public static int getQtdDorms() {
        return qtdDorms;
    }

    public int getQtdPessoas() {
        return qtdPessoas;
    }

    public int getCordsXCentro() {
        var b = this.getBoundsInParent();
        return (int)(b.getMinX() + b.getWidth() / 2);
    }

    public int getCordsYCentro() {
        var b = this.getBoundsInParent();
        return (int)(b.getMinY() + b.getHeight() / 2);
    }
}