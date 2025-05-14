import java.util.ArrayList;
public class QuickSort {
    SortLexiographically comparator = new SortLexiographically();
    public void sort(ArrayList<String> lines,int low, int high){
        int q;
        if(low <high){
            q = partition(lines, low, high);
            this.sort(lines, low, q-1);
            this.sort(lines, q+1, high);
        }

    }
    int partition(ArrayList<String> lines, int low, int high){
        String pivotLineString = lines.get(high);
        int i = low -1;
        int comparison;
        String copy;
        for(int j=low;j<high;j++){
            comparison = this.comparator.compare(lines.get(j),pivotLineString);
            if(comparison <= 0 ){
                i+=1;
                copy = lines.get(i);
                lines.set(i,lines.get(j));
                lines.set(j,copy);
            }

        }
        copy = lines.get(i+1);
        lines.set(i+1,lines.get(high));
        lines.set(high,copy);
        return i+1;
    }
 }