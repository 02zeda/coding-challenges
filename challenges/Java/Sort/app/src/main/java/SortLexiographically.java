import java.util.Comparator;
public class SortLexiographically  implements Comparator<String>{
    @Override
    public int compare(String obj1, String obj2){
        String line1 =  obj1;
        String line2 = obj2;
        return line1.compareTo(line2);
    }
 }
