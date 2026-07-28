import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class GoalTest extends Application {
    @Override
    public void start(Stage stage) {
        Goal goal = new Goal(50, 50);
        Scene scene = new Scene(goal, 200, 200);
        stage.setScene(scene);
        stage.setTitle("Pinguim");
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}
