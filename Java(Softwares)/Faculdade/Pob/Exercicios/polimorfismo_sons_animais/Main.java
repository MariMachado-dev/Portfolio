public class Main {
    public static void main(String[] args) {
        Animal[] animais = new Animal[2];

        animais[0] = new Cachorro("Rex");
        animais[1] = new Gato("Mimi");

        for (Animal a : animais) {
            a.fazerSom();
        }
    }
}
