package challenges.Java.sort;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
public class Sort {
    ArrayList<String> lines = new ArrayList<String>();
    public static void main(String[] args) {
        boolean uniqueOption = false;
        String fileName = "";
        //System.out.println("Sort program initialized.");
        if (args.length > 1){
            for(int i =0; i<args.length;i++){
                switch (args[i]){
                    case "-u":
                        uniqueOption = true;
                        break;
                    default:
                        fileName =args[i];
                        break;
                }
            }
        }
        Sort sorter = new Sort();
        Comparator comparator = new SortLexiographically();
        sorter.readFile(fileName);
        Collections.sort(sorter.lines,comparator);
        if(uniqueOption){
            // System.out.println("Removing duplicates");
            // System.out.println("Number of entries with still left: " + sorter.lines.size());
            sorter.removeDuplicates();
            // System.out.println("Number of entries left: " + sorter.lines.size());
            // System.out.println("First entry and second entry: " +sorter.lines.get(0)+ " " + sorter.lines.get(1));
        }

        for(int i =0;i<sorter.lines.size();i++){
            System.out.println(sorter.lines.get(i));
        }
    }
    public void readFile(String fileName) {
        // Implement file reading logic here
        //System.out.println("Reading file: " + fileName);
        File fileToSort = new File(fileName);
        Scanner fileScanner;
        try {
            fileScanner= new Scanner(fileToSort);
        } catch (FileNotFoundException fileException) {
            System.out.println("File " +fileName + " not found");
            return;
        }
        while(fileScanner.hasNextLine() ){
            this.lines.add(fileScanner.nextLine().toUpperCase());
        }
        fileScanner.close();
    }
    public void removeDuplicates(){
        String previousLine = "";
        for(int i=this.lines.size() -1; i>=0;i-- ){
            if (this.lines.get(i).equals(previousLine)){
                this.lines.remove(i);
            }
            else {
                previousLine = this.lines.get(i);
            }

        }
    }

 }
 class SortLexiographically  implements Comparator {

    public int compare(Object obj1, Object obj2){
        String line1 = (String) obj1;
        String line2 = (String) obj2;
        return line1.compareTo(line2);
    }
 }