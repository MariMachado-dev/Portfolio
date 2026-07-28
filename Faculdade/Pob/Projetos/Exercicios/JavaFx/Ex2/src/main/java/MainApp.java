import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundImage;
import javafx.scene.layout.BackgroundPosition;
import javafx.scene.layout.BackgroundRepeat;
import javafx.scene.layout.BackgroundSize;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;
import javafx.scene.control.TextInputDialog;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class MainApp extends Application {

    @Override
    public void start(Stage stage) {
        Pane root = new Pane();
        Campus campus = new Campus();

        Image bgImage = new Image(getClass().getResource("/images/plantaCampus.jpg").toExternalForm());
         BackgroundImage bg = new BackgroundImage(
            bgImage,
            BackgroundRepeat.NO_REPEAT,
            BackgroundRepeat.NO_REPEAT,
            BackgroundPosition.CENTER,
            new BackgroundSize(
                100, 100, true, true, false, true
            )
        );

        root.setBackground(new Background(bg));
        root.getChildren().add(campus);

        Scene scene = new Scene(root, 700, 550);
        stage.setScene(scene);
        stage.setResizable(false);
        stage.setTitle("Campus");
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}