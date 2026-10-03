import javafx.scene.media.AudioClip;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.AnchorPane;
import javafx.event.EventHandler;
import javafx.scene.input.MouseEvent;

public class Goal extends AnchorPane {
    private Image dukeImage;
    private ImageView dukeImageView;
    private Image gloveImage;
    private ImageView gloveImageView;
    private AudioClip audio;

        public Goal(double x, double y) {
            //Pegar a imagem e audio do recurso e criar um ImageView
            dukeImage = new Image(getClass().getResourceAsStream("/images/Duke.png"));
            dukeImageView = new ImageView(dukeImage);
            gloveImage = new Image(getClass().getResourceAsStream("/images/Glove.png"));
            gloveImageView = new ImageView(gloveImage);
            audio = new AudioClip(getClass().getResource("/audio/Note5.wav").toString());
            audio.setCycleCount(1);

            dukeImageView.setOnMouseClicked((MouseEvent me) -> {
                 audio.play(); 
            });

            //Arrastar o Duke
            final double[] offsetX = new double[1];
            final double[] offsetY = new double[1];

            dukeImageView.setOnMousePressed(me -> {
                offsetX[0] = me.getSceneX() - this.getLayoutX();
                offsetY[0] = me.getSceneY() - this.getLayoutY();
            });

            //Arrastar o duke e exibir a posição do mouse ao mesm
            dukeImageView.setOnMouseDragged((MouseEvent me) -> {
                this.setLayoutX(me.getSceneX() - offsetX[0]);
                this.setLayoutY(me.getSceneY() - offsetY[0]);

                double posX = me.getScreenX();
                double posY = me.getScreenY();
                System.out.println("Posição do duke: (" + posX + ", " + posY + ")");
            });

            //definir a posição do ImageView
            dukeImageView.setLayoutX(x);
            dukeImageView.setLayoutY(y);
            gloveImageView.setLayoutX(x+24);
            gloveImageView.setLayoutY(y);

            //Adicionar Duke primeiro, depois luva (luva fica na frente)
            this.getChildren().addAll(dukeImageView, gloveImageView);

            //Evitar distorção da imagem
            dukeImageView.setPreserveRatio(true);
            dukeImageView.setFitWidth(60);
            gloveImageView.setPreserveRatio(true);
            gloveImageView.setFitWidth(43);
        }
}
