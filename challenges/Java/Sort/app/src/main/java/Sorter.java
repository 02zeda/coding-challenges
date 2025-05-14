import java.util.Collections;
import java.util.ArrayList;
public class Sorter {
    public final Sorters sortOption;
    public final boolean uniqueOption;
    public final SortLexiographically comparator;
    public final QuickSort quickSort;
    public ArrayList<String> lines;
    public Sorter(Sorters sortOption, boolean uniqueOption,ArrayList<String> lines){
        this.sortOption = sortOption;
        this.uniqueOption = uniqueOption;
        comparator = new SortLexiographically();
        quickSort = new QuickSort();
        this.lines = lines;
    }
    public void sortLines(){
        if (this.sortOption == Sorters.DEFAULT){
            Collections.sort(lines,this.comparator);
        }
        else if (this.sortOption == Sorters.QUICKSORT){
            quickSort.sort(this.lines, 0, lines.size()-1);
        }

        if(uniqueOption){
            removeDuplicates();
        }
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
    public void printLines(){
        for(int i =0;i<this.lines.size();i++){
            System.out.println(this.lines.get(i));
        }
    }

}
