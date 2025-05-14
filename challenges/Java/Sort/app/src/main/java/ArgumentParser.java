import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;
enum Sorters {
    DEFAULT,
    QUICKSORT
}
public class ArgumentParser {


    public AppConfig parse(String[] args){
    boolean uniqueOption = false;
    Sorters sortOption = Sorters.DEFAULT;
    String fileName = "";
       if (args.length > 1){
            for(int i =0; i<args.length;i++){
                switch (args[i]){
                    case "-u":
                        uniqueOption = true;
                        break;
                    case "-sort=QuickSort":
                        if(sortOption != Sorters.DEFAULT){
                            sortOption = Sorters.QUICKSORT;
                        }
                        break;
                    default:
                        fileName =args[i];
                        break;
                }
            }
        }
        return new AppConfig(uniqueOption,sortOption,fileName);
    }

}
class AppConfig {
    public final boolean uniqueOption;
    public final Sorters sortOption;
    public final String fileName;

    public AppConfig(boolean uniqueOption, Sorters sortOption, String fileName) {
        this.uniqueOption = uniqueOption;
        this.sortOption = sortOption;
        this.fileName = fileName;
    }
    public ArrayList<String> readFile() {
        String fileName = this.fileName;
        File fileToSort = new File(fileName);
        Scanner fileScanner;
        ArrayList<String> lines = new ArrayList<String>();
        try {
            fileScanner= new Scanner(fileToSort);
            while(fileScanner.hasNextLine() )
            {
                lines.add(fileScanner.nextLine().toUpperCase());
            }
            fileScanner.close();
        } catch (FileNotFoundException fileException) {
            System.out.println("File " +fileName + " not found");
        }
        return lines;


    }
}
