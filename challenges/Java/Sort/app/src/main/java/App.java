
public class App {
    public static void main(String[] args) {

        AppConfig config = new ArgumentParser().parse(args);
        Sorter sorter = new Sorter(config.sortOption, config.uniqueOption,config.readFile());
        sorter.sortLines();
        sorter.printLines();
    }
 }
